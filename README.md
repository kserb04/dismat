# Discrete mathematics

This repo contains example problems in discrete mathematics solved in python and C.

## Problem 1

For given nonnegative integers $m, a_1, a_2, a_3, a_4$ find the number
of integer solutions to the equation $x_1 + x_2 + x_3 + x_4 = m$
under $0 \leq x_i \leq a_i$ for $i = 1, 2, 3, 4$.

### Solution
`src_01/sol_1.py`

## Problem 2
For a weighted graph $G$ with set of vertices $V = {1, ..., n}$ and
function $f \colon V \times V \to N, f(i, j) = a^{|i-j| \% c} + b (i -j)^2 - 1$
assigns each pair of vertices a weight to the connection between them.
Using Djikstra's algorithm find distance between 2 arbitrary vertices.

### Solution
`src_02/sol_2.py`

## Problem 3
A simple graph $G$ with $n$ edges is given by an adjacency matrix. Check if the
graph is planar and if it's not if it contains a subgraph homeomorphic with $K_5$ or $K_{3, 3}$.

Input is given by a text file. The first line of the file contains an integer $n$.
Next $n$ lines contain a sequence of 0s (no edge) and 1s (edge) separated by spaces.

### Example input
```
4
1 1 0 0
1 0 0 0
0 0 1 0
0 0 0 0
```

### Solution
`src_03/sol_3.c`
