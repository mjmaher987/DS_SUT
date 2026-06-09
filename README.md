# 📚 Data Structures & Algorithms — Sharif University of Technology

> Practical homeworks for the **Data Structures and Algorithms** course — each one solving a problem with the right data structure, from stacks to graphs.

* **Author:** Mohammad Javad Maheronnaghsh
* **Instructor:** Dr. Masoud Seddighin
* **Languages:** Python (HW1) · C++ (HW2–HW5)

> 📘 **New to data structures?** Every project below opens with a **"💡 In plain English"** note explaining the core idea, so this repo works as a study companion — each folder has the original `Question.pdf` and the solution.

---

## 🗺️ Overview

| # | Topic | Core data structure / technique | Language |
|---|-------|-------------------------------|----------|
| 1 | [Algorithmic complexity](#1️⃣-project-1--algorithmic-complexity) | Brute force → two pointers (O(n³)→O(n)) | Python |
| 2 | [Monotonic Stack](#2️⃣-project-2--monotonic-stack) | Stack | C++ |
| 3 | [Ordered Set & Map](#3️⃣-project-3--ordered-set--map) | Balanced BST (`set`/`map`) + binary search | C++ |
| 4 | [String Hashing](#4️⃣-project-4--string-hashing) | Polynomial rolling hash | C++ |
| 5 | [Graphs](#5️⃣-project-5--graphs) | Adjacency lists + BFS/DFS | C++ |

> 💡 **Why data structures matter:** the *same* problem can be slow or lightning-fast depending on how you store and access your data. These projects show that trade-off in action — Project 1 makes it dramatic.

---

## 1️⃣ Project 1 — Algorithmic Complexity

**Problem:** count how many contiguous subarrays have a sum ≤ *k*. Solved **three ways**, each faster than the last:

| Version | Approach | Time complexity |
|---------|----------|:---:|
| `SubQuestion-1.py` | Triple loop (recompute every sum) | **O(n³)** |
| `SubQuestion-2.py` | Running sum, double loop | **O(n²)** |
| `SubQuestion-3.py` | **Two-pointer / sliding window** | **O(n)** |

> 💡 **In plain English — Big-O:** it describes how the running time grows as the input gets bigger. An O(n³) solution that handles 100 items in a blink can take *hours* on 10,000 — while the O(n) version barely notices. Same answer, wildly different speed.

The included **`Histogram.pdf`** (and the optional one) plot the measured runtimes, making the gap between the three versions visible.

📂 [`Project - 1/`](./Project%20-%201)

---

## 2️⃣ Project 2 — Monotonic Stack

> 💡 **In plain English — a stack:** a "last-in, first-out" pile, like a stack of plates — you add and remove from the top. A **monotonic stack** keeps its contents in sorted order, which lets you answer "what's the next bigger element?" type questions in a single pass instead of checking every pair.

This solution scans an array once, using a stack of indices to efficiently find, for each element, how it relates to the larger elements before it — turning an O(n²) brute force into **O(n)**.

📂 [`Project - 2/`](./Project%20-%202)

---

## 3️⃣ Project 3 — Ordered Set & Map

> 💡 **In plain English — an ordered set/map (balanced BST):** a container that always keeps its keys **sorted**, so you can instantly find the nearest smaller/larger key (`lower_bound` / `upper_bound`) in O(log n). Perfect when you keep inserting items and repeatedly need their neighbors.

The solution processes a stream of insertions, using `std::set` + `std::map` to look up each new point's neighbors and compute results based on them — all in logarithmic time per query.

📂 [`Project - 3/`](./Project%20-%203)

---

## 4️⃣ Project 4 — String Hashing

> 💡 **In plain English — string hashing:** turn a string into a single number (a "fingerprint") so you can compare chunks of text in O(1) instead of character by character. A **polynomial rolling hash** does this; comparing a string's fingerprint with its reverse is a fast way to detect **palindromes**.

This solution compares prefixes against suffixes using a polynomial rolling hash (mod 1e9+7) to detect palindromic structure quickly.

📂 [`Project - 4/`](./Project%20-%204)

---

## 5️⃣ Project 5 — Graphs

> 💡 **In plain English — a graph:** a network of **nodes** connected by **edges** (think cities linked by roads). **Adjacency lists** store each node's neighbors compactly, and **BFS/DFS** are the two fundamental ways to explore the network — breadth-first (level by level) or depth-first (follow a path to the end, then backtrack).

This solution builds a graph with adjacency lists (`std::list`), applies **coordinate compression** (sorting vertices and assigning compact indices so equal values share an index), and traverses it with BFS/DFS.

📂 [`Project - 5/`](./Project%20-%205)

---

## 🚀 Building & Running

**Python (Project 1):**
```bash
python3 "Project - 1/Answer/SubQuestion-3.py"
```

**C++ (Projects 2–5):**
```bash
g++ -O2 -std=c++17 "Project - 2/Answer.cpp" -o answer
./answer        # reads from standard input
```

Each project's `Question.pdf` contains the full problem statement and expected input/output format.

---

## 🧠 Concepts Covered

`Big-O analysis` · `Two pointers / sliding window` · `Stack (monotonic)` · `Balanced BST (ordered set/map)` · `Binary search (lower/upper bound)` · `String hashing` · `Graphs (BFS/DFS, adjacency lists)` · `Coordinate compression`
