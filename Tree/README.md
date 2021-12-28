# [Gold IV] Tree - 13244

### 성능 요약

메모리: 2180KB, 시간: 2180ms

### 분류

자료 구조(data_structures), 분리 집합(disjoint_set), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 트리(trees)

### 문제 설명

One of the most important data structures in computer science is the tree. You already dealt with binary trees in the qualification round. This problem is about general trees.

Trees are the subset of graphs that have the following 3 properties:


 It is connected: for every node you can reach every other node following edges.
 If an edge is removed, the graph is no longer connected. That is, some nodes cannot be reached anymore.
 When an edge is added between two existing nodes A and B, a cycle is created. There is a cycle if there is more than one way to go from A to B.


Your task is to decide if a given graph is a tree or not.

