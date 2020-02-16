#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define R 3
#define C 3

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

// Dynamic programming
// To reach (m, n)
int MinCostPath(int cost[R][C], int m, int n) {
  int a[R][C];
  a[0][0] = cost[0][0];
  // Filling up 1st column
  for(int i = 1; i <= m; i++) {
    a[i][0] = a[i-1][0] + cost[i][0];
  }
  // Filling up 1st row
  for(int j = 1; j <= n; j++) {
    a[0][j] = a[j-1][0] + cost[0][j];
  }

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      // Go to min of left, right, diagonal given i, j
      a[i][j] = cost[i][j] + min(a[i-1][j-1], a[i-1][j], a[i][j-1]);
    }
  }

  return a[m][n];
}

int main() {
  int cost[R][C] = { {1, 2, 3},
                     {4, 8, 2},
                     {1, 5, 3} };
  cout << MinCostPath(cost, 2, 2) << endl;
  return 0;
}
