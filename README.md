License
- MIT-style (or adapt to your preferred license).

If you'd like, I can also:
- add a runnable HTML demo with interactive visualization
- generate a small example suite and sample NFAs
- commit the changes and create a release-ready README variant

Enjoy!
# 🔄 NFA Epsilon Transition Elimination

> ✨ Efficiently remove epsilon transitions from Non-deterministic Finite Automata ✨

---

## 📋 Team Members

| Name | Specialization |
|------|-----------------|
| DEGHNOUCHE ZIN EL ABIDINE | AI - Group 01 |


---

## 📖 Overview
This program automatically removes epsilon (ε) transitions from an NFA, creating an equivalent NFA without epsilon transitions while preserving the language acceptance.

---

## 🎯 What It Does

| Step | Description |
|------|-------------|
| 1️⃣ Read NFA | Takes input describing an NFA structure |
| 2️⃣ Calculate Epsilon Closure | Finds all states reachable via epsilon transitions |
| 3️⃣ Compute New Transitions | Creates transitions that skip epsilon moves |
| 4️⃣ Determine Final States | Marks states that can reach original final states |
| 5️⃣ Display Result | Shows the cleaned NFA with improved readability |

---


