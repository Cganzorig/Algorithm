#include <iostream>
#include<bits/stdc++.h>

using namespace std;


// Dynamic programming
int CoinChange(int a[], int n, int c) {
  int table[n+1][c+1];
  memset(table, 0, sizeof(table));
  for(int i = 0; i < n + 1; i++) {
    table[i][0] = 1;
  }
  // Row - coins
  for(int i = 1; i < n + 1; i++) {
    // Column - 1 to value N
    for(int j = 1; j < c + 1; j++) {
      // When the coin is bigger than value j
      if(a[i-1] > j) {
        table[i][j] = table[i-1][j];
      } else {
        // With and without including the coin
        table[i][j] = table[i-1][j] + table[i][j - a[i-1]];
      }
    }
  }
  return table[n][c];

}

int main() {
  int arr[] = {1, 2, 3};
  int m = sizeof(arr)/sizeof(arr[0]);
  int n = 4;
  cout << CoinChange(arr, m, n) << endl;
  return 0;
}
