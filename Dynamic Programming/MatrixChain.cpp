#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int MatrixChainOrder(int p[], int n) {
  int m[n][n];
  // Row 0, column 0, diagonal should be zeros
  for(int i = 0; i < n; i++) {
    m[i][0] = 0;
    m[0][i] = 0;
    m[i][i] = 0;
  }

  int j, min, q;
  // Difference between i and j should start from 1;
  for(int d = 1; d < n - 1; d++) {
    // i - row starts from 1 because 0th row is 0
    for(int i = 1; i < n - d; i++) {
      // j equals i plus difference
      j = i + d;
      min = INT_MAX;
      for(int k = 1; k < j; k++) {
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if(q < min) {
          min = q;
        }
      }
      m[i][j] = min;
    }
  }
  return m[1][n-1];
}

int main() {
  int arr[] = {1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Minimum number of multiplications is "
          << MatrixChainOrder(arr, size);

  getchar();

  return 0;
}
