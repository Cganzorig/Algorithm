#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
  return (x > y) ? x: y;
}

// Dynamic programming
// n - length of the rod
int CuttingRode(int price[], int n) {
  int C[n+1];
  C[0] = 0;

  for(int i = 1; i < n + 1; i++) {
    int maxValue = INT_MIN;
    for(int j = 0; j < i; j++){
      // if we cut j length, we have i-j-1 length left, so what is the best price for length i-j-1?
      maxValue = max(maxValue, price[j] + C[i-j-1]);
    }
    C[i] = maxValue;
  }

  return C[n];



  // int C[n][n+1];
  // for(int i = 1; i < n + 1; i++) {
  //   C[0][i] = i * price[0];
  // }
  // for(int i = 0; i < n; i++) {
  //   C[i][0] = 0;
  // }
  //
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n+1; j++) {
  //     if(j >= i) {
  //       C[i][j] = max(C[i-1][j], C[i][j-i]);
  //     } else {
  //       C[i][j] = C[i-1][j];
  //     }
  //   }
  // }
  // return C[n-1][n];

}
int main() {
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Maximum Obtainable Value is %d\n", CuttingRode(arr, size));

  return 0;
}
