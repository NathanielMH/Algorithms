# Algorithms
Series of graph and tree algorithms coded in C++. Throughout this file, |V| will denote the amount of vertex of the graph and |E| the amount of edges.

## DFS (Depth First Search)
This is a search algorithm for graphs (directed or undirected). 
Applicability: None.
As it name suggests, given an initial vertex it explores the first path it encounters in full depth before moving to the next.
This is the opposite of what BFS does.
Complexity: O(|V|+|E|), each edges is visited only once.

## BFS (Breadth First Search)
This is again a search algorithm for graphs(directed or undirected).
Applicability: None.
Given an initial vertex, the algorithm epxlores the different paths from it in a layered search, that is it starts all possible paths and updates each path sequentially,
in layers.
Complexity: O(|V|+|E|), each edges is visited only once.

## Dijkstra
This is an algorithm to find the path from a source to a given destination with minimum cost, easily adaptable for maximum cost.
Applicability: all edges capacities have to be positive.
It is again based on a heuristic approach to construct the shortest path by updating the path with the lightest edge every time. 
This works as the edge capacities are all positive, it is impossible to do better by passing through a heavier edge.
Complexity: O(|E|·log|V|) as a priority queue is used to select the lightest edge at every iteration.

## Bellman Ford

This is an algorithm to find shortest path with edge capacities being integer, not necessarily positive.
Applicability: there should be no negative cycles in the graph.
It is ia constructive algorithm, at each iteration we find the first i steps of the shortest path. As it can have at most |V|-1 edges, we will have found it in those iterations.
Complexity: O(|V|·|E|), as we go through all edges |V|-1 times.

## Topological sort
Given an directed acyclic graph (DAG), this algorithm finds an order of vertices to traverse it without going back on vertices, passing by all of them exactly once.
Applicability: Graph must be a DAG.
Complexity: O(|V|+|E|), as we use DFS and information on the order of traversal to obtain our topological sort.

## SCC (Strongly Connected Components)
A strongly connected component is a subgraph where for any pair of vertices there exists a path between them.
The goal of the algorithm is to find the amount of SCC, as well as their composition.
Applicability: None.
We wish to find a sink SCC, that is one from which a DFS algorithm would reveal exactly the vertices from the SCC. To do so, we find a source SCC from the reverse graph, which is a sink SCC from the graph. From there, we use DFS and connected components to find the SCC one by one. 
Complexity: O(|V|+|E|), as we can reverse the graph in linear time, use DFS to find the sink SCC and the connected components algorithm is linear.

## FF (Ford Fulkerson)
This is an algorithm to solve a maxflow problem, that is to maximize the amount of flow through edges whilst respecting the following constraints:
-> For every vertex except the source and sink, the flow going in is equal to the flow going out.
-> For every edge, the flow does not exceed its capacity.
The algorithm is based on a relaxation of the problem that gets increasingly better until it reaches the optimum.
It can also be used to find the mincut, which is the dual problem of the maxflow.
Complexity: Depends on the implementation, the given one is O(|V|·|E|^2) as BFS is usedn to find the path with fewest edges.
