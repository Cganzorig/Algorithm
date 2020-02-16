#include <iostream>
#include<bits/stdc++.h>
#define V 5
using namespace std;

// The number of edges = Vertices - 1 - No of cycles

// Prims algo:
// 1. Choose min edge
// 2. Choose min edge from connected vertices

int minIndex(int set[], bool visited[]) {
  int min = INT_MAX, minIndex;
  for(int i = 0; i < V; i++) {
    if(visited[i] == false && set[i] < min) {
      min = set[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
  cout<<"Edge \tWeight\n";
  for(int i = 1; i < V; i++) {
    cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
  }
}

void PrimMST(int graph[V][V]) {
  // 2 things to find: 1) Vertices included in MST 2) Values included in MST
  int parent[V]; // to store constructed Minimum Spanning Tree (MST)
  int set[V]; // to store minimum value
  bool visited[V]; // to check if a vertex is visited

  for(int i = 0; i < V; i++) {
    set[i] = INT_MAX;
    visited[V] = false;
  }
  set[0] = 0;
  parent[0] = -1;

  for(int i = 0; i < V - 1; i++) {
    int u = minIndex(set, visited);
    visited[u] = true;
    for(int v = 0; v < V; v++) {
      if(graph[u][v] != 0 && visited[v] == false && graph[u][v] < set[v]) {
        parent[v] = u;
        set[v] = graph[u][v];
      }
    }
  }

  printMST(parent, graph);
}


int main() {
  /*
  (0)--(1)--(2)
  | / \ |
  6| 8/ \5 |7
  | / \ |
  (3)-------(4)
          9     */
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                      { 2, 0, 3, 8, 5 },
                      { 0, 3, 0, 0, 7 },
                      { 6, 8, 0, 0, 9 },
                      { 0, 5, 7, 9, 0 } };

  PrimMST(graph);

  return 0;
}
