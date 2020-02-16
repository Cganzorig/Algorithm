#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define V 5

int parent[V];

// Union-Find Algorithm
// 2 operations:
// 1) Union() - make union of 2 sets
// 2) Find() - find in which set an element belongs to

int Find(int i) {
  while (parent[i] != i)
      i = parent[i];
  return i;
}

void Union(int x, int y) {
  int set_x = Find(x);
  int set_y = Find(y);
  parent[set_x] = set_y;
}

void KruskalMST(int cost[][V]) {
  for(int i = 0; i < V; i++) {
    parent[i] = i;
  }
  int edge_count;
  for(edge_count = 0; edge_count < V-1; edge_count++) {
    int min = INT_MAX;
    int a = -1;
    int b = -1;
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        if(Find(i) != Find(j) && cost[i][j] < min) {
          min = cost[i][j];
          a = i;
          b = j;
        }
      }
    }
    Union(a, b);
    printf("Edge %d:(%d, %d) cost:%d \n",
           edge_count++, a, b, min);
  }
}

int main() {
  int cost[][V] = {
      { INT_MAX, 2, INT_MAX, 6, INT_MAX },
      { 2, INT_MAX, 3, 8, 5 },
      { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
      { 6, 8, INT_MAX, INT_MAX, 9 },
      { INT_MAX, 5, 7, 9, INT_MAX },
  };

  // Print the solution
  KruskalMST(cost);

  return 0;
}
