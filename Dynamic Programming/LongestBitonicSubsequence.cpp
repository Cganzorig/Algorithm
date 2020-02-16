#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
  return (x > y) ? x: y;
}

// Dynamic programming
int LongestBitonicSubS(int a[], int n) {
  // Left to right longest increasing subsequence
  int left[n];
  for(int i = 0; i < n; i++) {
    left[i] = 1;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[j] < a[i]) {
        left[i] = max(left[i], 1 + left[j]);
      }
    }
  }

  // Right to left longest increasing subsequence
  int right[n];
  for(int i = 0; i < n; i++) {
    right[i] = 1;
  }

  for(int i = n-2; i >= 0; i--) {
    for(int j = n-1; j > i; j--) {
      if(a[j] > a[i]) {
        right[i] = max(left[i], 1 + left[j]);
      }
    }
  }

  // Find max
  int max = left[0] + right[0] - 1;
  for(int i = 1; i < n; i++) {
    if(max < left[i] + right[i] - 1) {
      max = left[i] + right[i] - 1;
    }
  }
  return max;
}
int main() {
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", LongestBitonicSubS(arr, n));
  return 0;
}
