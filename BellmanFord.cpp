#include <iostream>
#include <limits.h>

using namespace std;

struct Edge{
  int src;
  int dest;
  int weight;
};

struct Graph {
  int V;
  int E;
  Edge* edge;
};

Graph* createGraph(int V, int E) {
  Graph* temp = new Graph();
  temp->V = V;
  temp->E = E;
  temp->edge = new Edge[E];
  return temp;
}

void printArr(int dist[], int n) {
  printf("Vertex   Distance from Source\n");
  for(int i = 0; i < n; ++i) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

void BellmanFord(Graph* graph, int src) {
  // Step 1: Set up
  int V = graph->V;
  int E = graph->E;

  int dist[V];

  for(int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
  }

  dist[src] = 0;

  // Step 2: Relax all vertices V-1 times
  for (int i = 1; i <= V - 1; i++) {
    // For all edges
    for (int j = 0; j < E; j++) {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;

      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  // Step 3: check for negative-weight cycles. If we get a shorter path even though all vertices relaxed, then there is a cycle.
  // After 1 more iteration (after V-1 iteration), any distance should not be changed. if changed, it is negative-weight cycles;
  for (int i = 0; i < E; i++) {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;

    if (dist[u] + weight < dist[v]) {
      cout << "Graph contains negative weight cycle" << endl;
      return;
    }
  }

  printArr(dist, V);
  return;
}




int main() {
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}
