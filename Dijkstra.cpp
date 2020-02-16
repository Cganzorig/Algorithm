#include <iostream>
#include <limits.h>
#define V 9
using namespace std;

int printSolution(int distance[]) {
    cout << "Vertex     Distance from Source" << endl;
    for(int i = 0; i < V; i++) {
      cout << i << "          " << distance[i] << endl;
    }
}

int minDistance(int distance[], bool visited[]) {
  int minIndex;
  int min = INT_MAX;

  for(int i = 0; i < V; i++) {
    if(visited[i] == false && distance[i] <= min) { // Should be unvisited
      minIndex = i;
      min = distance[i];
    }
  }
  return minIndex;
}

void Dijkstra(int graph[V][V], int src) {

  // Initial setup
  int distance[V]; // distance from source vertext to all other vertices
  bool visited[V];

  for(int i = 0; i < V; i++) {
    distance[i] = INT_MAX;
    visited[i] = false;
  }

  distance[src] = 0;

  // Main procedure

  // Find the shortest path to the SOURCE vertice for all vertices
  for (int iV = 0; iV < V; iV++) {
    int minV = minDistance(distance, visited);
    visited[minV] = true;
    // Update distance value of the ADJACENT VERTICES of the picked vertex.
    for(int adjV = 0; adjV < V; adjV++) {
      // Update distance[adjV] only if
      // 1) it is not included in visited
      // 2) there is an edge from minV to adjV (unvisited)
      if (visited[adjV] == false &&
        graph[minV][adjV] != 0) {
          // 3) total weight of path from src to adjV through minV is smaller than current value of distance[adjV]
          if((distance[minV] + graph[minV][adjV]) < distance[adjV]) {
            distance[adjV] = distance[minV] + graph[minV][adjV];
          }
        }
      }
    }

  printSolution(distance);

}

int main() {
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

  Dijkstra(graph, 0);
  return 0;
}
