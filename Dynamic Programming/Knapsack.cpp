#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

// Dynamic programming
// Returns the maximum value that can be put in a knapsack of capacity W
// W - knapsack capacity
// wt[] - weights
// val[] - corresponding value
// n is size of wt[] amd val[]
int knapSack(int W, int wt[], int val[], int n) {
  int i, w;
  int K[n+1][W+1];

  for(int i = 0; i < W + 1; i++) {
    K[0][i] = 0;
  }

  for(int i = 0; i < n + 1; i++) {
    K[i][0] = 0;
  }

  // Row - weight and value
  for(i = 1; i <= n; i++) {
    // Column - knapsack capacity
    for(w = 1; w <= W; w++) {
      if (wt[i-1] <= w) {
        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
      } else {
        K[i][w] = K[i-1][w];
      }
    }
   }
   return K[n][W];
}
int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int  W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  printf("%d", knapSack(W, wt, val, n));
  return 0;
}
