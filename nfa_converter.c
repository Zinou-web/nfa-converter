#include <stdio.h>



#define MAX 10



int n, m;

char alpha[MAX];

int start;



int final[MAX];

int newFinal[MAX];



int eps[MAX][MAX];

int trans[MAX][MAX][MAX];



int eclose[MAX][MAX];

int newTrans[MAX][MAX][MAX];



// Task 1: Read NFA

void readNFA() {

    int i, j, k;



    scanf("%d", &n);

    scanf("%d", &m);



    for (i = 0; i < m; i++)

        scanf(" %c", &alpha[i]);



    scanf("%d", &start);



    for (i = 0; i < n; i++)

        scanf("%d", &final[i]);



    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            scanf("%d", &eps[i][j]);



    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)

            for (k = 0; k < n; k++)

                scanf("%d", &trans[i][j][k]);

}



// Task 2: Epsilon Closure

// Helper function to perform DFS for epsilon closure
void dfsEpsilon(int state, int visited[]) {

    int i;

    

    visited[state] = 1;

    

    for (i = 0; i < n; i++)

        if (eps[state][i] && !visited[i])

            dfsEpsilon(i, visited);

}

void epsilonClosure() {

    int i, j;

    int visited[MAX];



    // For each state, compute its epsilon closure using DFS

    for (i = 0; i < n; i++) {

        // Initialize visited array for this DFS

        for (j = 0; j < n; j++)

            visited[j] = 0;

        

        // Perform DFS starting from state i

        dfsEpsilon(i, visited);

        

        // Copy visited states to epsilon closure

        for (j = 0; j < n; j++)

            eclose[i][j] = visited[j];

    }

}



// Task 3: New Transitions

void buildNewTransitions() {

    int i, j, x, y, z, k;



    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)

            for (k = 0; k < n; k++)

                newTrans[i][j][k] = 0;



    // For state i on symbol j: 
    // - Start from all states in epsilon closure of i
    // - Apply transition on symbol j
    // - Include all states in epsilon closure of the result
    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)

            for (x = 0; x < n; x++)

                if (eclose[i][x])

                    for (y = 0; y < n; y++)

                        if (trans[x][j][y])

                            for (z = 0; z < n; z++)

                                if (eclose[y][z])

                                    newTrans[i][j][z] = 1;

}



// Task 4: New Final States

void buildNewFinalStates() {

    int i, j;



    for (i = 0; i < n; i++) {

        newFinal[i] = 0;

        for (j = 0; j < n; j++)

            if (eclose[i][j] && final[j]) {

                newFinal[i] = 1;

                break;

            }

    }

}



// Task 5: Display

void display() {

    int i, j, k;



    for (i = 0; i < n; i++)

        printf("Final(%d) = %d\n", i, newFinal[i]);



    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++) {

            printf("d(%d,%c) = { ", i, alpha[j]);

            for (k = 0; k < n; k++)

                if (newTrans[i][j][k])

                    printf("%d ", k);

            printf("}\n");

        }

}



// Main

int main() {

    readNFA();

    epsilonClosure();

    buildNewTransitions();

    buildNewFinalStates();

    display();

    return 0;

}

