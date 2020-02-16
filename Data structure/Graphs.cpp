#include <iostream>

using namespace std;

struct Node {
  int vertex;
  Node* next;
};

Node* CreateNode(int n) {
  Node* temp = new Node();
  temp->vertex = n;
  temp->next = NULL;
  return temp;
}

struct Graph {
  int v;
  Node** adjLists;
};

struct Graph* CreateGraph(int n) {
  Graph* g = new Graph();
  g->v = n;
  g->adjLists = new Node*[n+1];
  for(int i = 0; i < n; i++) {
    g->adjLists[i] = NULL;
  }
  return g;
};

void AddEdge(Graph* graph, int src, int dest) {
  // Add edge from src to dest
  Node* newNode = CreateNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = CreateNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
};

void PrintGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->v; v++) {
      Node* temp = graph->adjLists[v];
      printf("\n Adjacency list of vertex %d\n ", v);
      while (temp != NULL) {
          printf("%d -> ", temp->vertex);
          temp = temp->next;
      }
      printf("\n");
  }
};

int main() {
  Graph* graph = CreateGraph(6);
  AddEdge(graph, 0, 1);
  AddEdge(graph, 0, 2);
  AddEdge(graph, 1, 2);
  AddEdge(graph, 1, 4);
  AddEdge(graph, 1, 3);
  AddEdge(graph, 2, 4);
  AddEdge(graph, 3, 4);
  AddEdge(graph, 4, 6);
  AddEdge(graph, 5, 1);
  AddEdge(graph, 5, 6);

  PrintGraph(graph);



  return 0;
}
