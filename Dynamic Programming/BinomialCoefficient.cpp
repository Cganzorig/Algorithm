#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

// Dynamic programming
int BinomialCoefficient(int n, int k) {
  int c[n+1][k+1];
  // n - row, k - column
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      // Combinatorics (kCn) - if k equals 0 or n, it is 1;
      if(j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        // kCn = (k-1)C(n-1) + (k)C(i-1) - Theorem
        c[i][j] = c[i-1][j-1] + c[i-1][j];
      }
    }
  }
  return c[n][k];
}
int main() {
  int n = 5, k = 2;
  cout << "Value of C[" << n << "][" << k << "] is " << BinomialCoefficient(n, k);
  return 0;
}
