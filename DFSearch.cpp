#include <iostream>
#include <limits.h>
#include <list>
#include <iterator>

using namespace std;


class Graph {
  int V; // Number of vertices
  list<int> *adj; // Pointer to array containing adjancency list
public:
  Graph(int v);
  void addEdge(int v, int w);
  void DFSUtil(int v, bool visited[]);
  void DFS();
};

Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";

  list<int>::iterator it;
  for(it = adj[v].begin(); it != adj[v].end(); ++it) {
    if(visited[*it] == false) {
      DFSUtil(*it, visited);
    }
  }
}

void Graph::DFS() {
  // Set-up
  bool visited[V];
  for(int i = 0; i < V; i++) {
    visited[i] = false;
  }

  for(int i = 0; i < V; i++) {
    if(visited[i] == false) {
      DFSUtil(i, visited);
    }
  }
}


int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal (starting from vertex 2)" << endl;
  g.DFS();

  return 0;
}
