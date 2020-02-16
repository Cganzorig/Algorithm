#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// Print solution
int printSolution (int p[], int n) {
  int k;
  if (p[n] == 1) {
    k = 1;
  } else {
    k = printSolution(p, p[n]-1) + 1;
  }
  cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;
  return k;
}

// Dynamic programming
// l - lengths of different words
// n - size of legal
// M - width of line
int WordWrap(int l[], int n, int m) {
  // cost matrix
  int cost[n][n];
  // cost of optimal solution
  int minCost[n];
  // used to print solution
  int p[n];

  // Calculate extra spaces
  for(int i = 0; i < n; i++) {
    cost[i][i] = m - l[i];
    for(int j = i + 1; j < n; j++) {
      // fx: to find extra space for 0-2, extra space for 0-1 minus word j and 1 for space separation
      cost[i][j] = cost[i][j-1] - l[j] - 1;
    }
  }

  // Calculate cost
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      if(cost[i][j] < 0) {
        cost[i][j] = INT_MAX;
      } else {
        cost[i][j] = (cost[i][j] * cost[i][j]);
      }
    }
  }

  // Start from backwards
  for(int i = n-1; i >= 0; i--) {
    minCost[i] = cost[i][n-1];
    p[i] = n;
    for(int j = n-1; j > i; j--) {
      if(cost[i][j-1] == INT_MAX) {
        continue;
      }
      // Divide into (i, j-1) and (j)
      // cost[i][j-1]
      // minCost[j]
      if(minCost[i] > minCost[j] + cost[i][j-1]) {
        minCost[i] = minCost[j] + cost[i][j-1];
        p[i] = j;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
}

int main() {
  int l[] = {3, 2, 2, 5};
  int n = sizeof(l)/sizeof(l[0]);
  int M = 6;
  WordWrap (l, n, M);
  return 0;
}
