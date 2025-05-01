# Minimum Cut Problem (Karger's Algorithm)

This project implements **Karger's randomized algorithm** to compute the minimum cut of an undirected, connected graph. It is available in both Java and C++ versions.

---

## 📘 Problem Description

The **Minimum Cut Problem** aims to find the smallest number of edges that, if removed, would split a connected graph into two disconnected components. Karger's algorithm solves this problem efficiently by randomly contracting edges until only two nodes remain.

---

## 📥 Input

The program expects an input file named `adjList.txt` located in the same directory. The file should contain the adjacency list representation of a **simple**, **undirected**, and **connected** graph.

### 📄 File Format

- Each line represents a vertex and its neighbors.
- The first number is the vertex label.
- The remaining values are labels of adjacent vertices, separated by tabs.

#### Example:

This represents a triangle (complete graph with 3 nodes).

---

## 📤 Output

An integer representing the **minimum cut** — i.e., the **fewest number of crossing edges** needed to separate the graph into two components.

---

## ⚙️ How It Works

Karger's **Random Contraction Algorithm** follows these steps:

1. While there are more than two nodes:
   - Randomly select an edge (u, v).
   - Merge the two vertices into a single node.
   - Remove all self-loops.
2. Once only two nodes remain, the number of edges between them is returned as the minimum cut.

This randomized approach is probabilistic. Running the algorithm multiple times improves the likelihood of finding the true minimum cut.

---

## 🧠 Time Complexity

- Expected time complexity: **Ω(n² * m)**,  
  where:
  - `n` = number of nodes
  - `m` = number of edges

- To improve accuracy, the algorithm should be repeated approximately `n(n - 1) * log n / 2` times.

---

## 🛠️ Build and Run

### C++ Version

#### ✅ Compile
```bash
g++ -std=c++17 -o min_cut min_cuts.cpp
