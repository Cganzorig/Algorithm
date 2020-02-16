#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// Dynamic programming
bool SubsetSum(int a[], int n, int m) {
  int T[n+1][m+1];
  for(int i = 1; i < m + 1; i++) {
    T[0][i] = false;
  }
  for(int i = 0; i < n + 1; i++) {
    T[i][0] = true;
  }
  for(int i = 1; i < n + 1; i++) {
    for(int j = 1; j < m + 1; j++) {
      if(a[i-1] > j) {
        T[i][j] = T[i-1][j];
      } else {
        T[i][j] = T[i-1][j] || T[i-1][j-a[i-1]];
      }
    }
  }
  return T[n][m];
}

bool partition(int arr[], int n) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
  }
  if(sum % 2 == 0 && SubsetSum(arr, n, sum/2) == true) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int arr[] = {3, 1, 5, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (partition(arr, n) == true) {
    cout << "Can be divided into two subsets "
                  "of equal sum";
  } else {
    cout << "Can not be divided into two subsets"
                " of equal sum";
  }
  return 0;
}
