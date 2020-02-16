#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) {
  return (a>b)?a:b;
}

int max_element(int a[], int n) {
  int max = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

// Dynamic programming
int LIS(int a[], int n) {
  int lis[n];
  for(int i = 0; i < n; i++) {
    lis[i] = 1;
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[i] > a[j]) {
        if(lis[i] < lis[j] + 1) {
          lis[i] = lis[j] + 1;
        }
      }
    }
  }
  return max_element(lis, n);
}



int main() {
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of lis is %d\n",
         LIS(arr, n ));
  return 0;
}
