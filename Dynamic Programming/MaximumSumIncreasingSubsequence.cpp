#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
  return (x > y) ? x: y;
}

// Dynamic programming
int MaxSumIS(int a[], int n) {
  int sum[n];
  for(int i = 0; i < n; i++) {
    sum[i] = a[i];
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[j] < a[i]) {
        sum[i] = max(sum[i], a[i] + sum[j]);
      }
    }
  }

  int max = sum[0];
  for(int i = 1; i < n; i++) {
    if(max < sum[i]) {
      max = sum[i];
    }
  }
  return max;
}
int main() {
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Sum of maximum sum increasing "
          "subsequence is " << MaxSumIS(arr, n) << endl;
  return 0;
}
