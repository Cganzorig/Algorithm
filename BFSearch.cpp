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
  void BFS(int s);
};

Graph::Graph(int v) {
  V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
}

void Graph::BFS(int s) {
  // Set-up
  bool visited[V];
  for(int i = 0; i < V; i++) {
    visited[i] = false;
  }
  visited[s] = true;

  list<int> queue;
  queue.push_back(s);

  // it used to get all adjancency of a vertex
  list<int>::iterator it;

  while(!queue.empty()) {
    int s = queue.front();
    cout << s << " ";
    queue.pop_front();

    // Going through all the adjacent vertices of the vertice "S"
    for(it = adj[s].begin(); it != adj[s].end(); ++it) {
      if(visited[*it] == false) {
        visited[*it] = true;
        queue.push_back(*it);
      }
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

  cout << "Following is Breadth First Traversal (starting from vertex 2)" << endl;
  g.BFS(2);

  return 0;
}
