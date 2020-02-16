#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Pair {
public:
  int a;
  int b;
};

int max_element(int a[], int n) {
  int max = a[0];
  for(int i = 1; i < n; i++) {
    if(a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

// Dynamic programming
int MaxChainLength(Pair arr[], int n) {
  int lis[n];
  for(int i = 0; i < n; i++ ) {
    lis[i] = 1;
  }

  for(int i = 1; i < n; i++ ) {
    for(int j = 0; j < i; j++ ) {
      if(arr[i].a > arr[j].b) {
        if(lis[i] < lis[j] + 1) {
          lis[i] = lis[j] + 1;
        }
      }
    }
  }
  
  return max_element(lis, n);
}

int main() {
  Pair arr[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Length of maximum size chain is " << MaxChainLength(arr, n);
  return 0;
}
