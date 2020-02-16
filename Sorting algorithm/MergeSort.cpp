#include <iostream>

using namespace std;
// l - low
// m - mid
// h - high
// void Merge(int a[], int l, int m, int h) {
//   int i, j, k;
//
//   int n1 = m - l + 1;
//   int n2 = h - m;
//
//   int left[n1], right[n2];
//
//   for(i = 0; i < n1; i++) {
//     left[i] = a[l + i];
//   }
//   for(j = 0; j < n2; j++) {
//     right[j] = a[m + 1 + j];
//   }
//
//   i = 0;
//   j = 0;
//   k = l;
//   while (i < n1 && j < n2) {
//     if (left[i] <= right[j]) {
//       a[k] = left[i];
//       i++;
//       // k++;
//     } else {
//       a[k] = right[j];
//       j++;
//       // k++;
//     }
//     k++;
//   }
//
//   while (i < n1) {
//     a[k] = left[i];
//     i++;
//     k++;
//   }
//
//   while (j < n2) {
//     a[k] = right[j];
//     j++;
//     k++;
//   }
// }
//
// void MergeSort(int a[], int l, int h) {
//   if (l < h) {
//     // int mid = (l + h)/2;
//     int mid = l + (h - l)/2;
//     MergeSort(a, l, mid);
//     MergeSort(a, mid+1, h);
//     Merge(a, l, mid, h);
//   }
// }

void Merge(int a[], int l, int m, int h) {
  int i, j, k;

  // Creating 2 separate sets

  // fx: { 0, 1, 2, 3, 4, 5, 6, 7} and l = 0; h = 7; m = 3
  // set1 : 0, 1, 2, 3
  // set2 : 4, 5, 6, 7
  int n1 = m - l + 1; // n1 = 4 because 0 to m
  int n2 = h - m;     // n2 = 4 because (m+1) to h

  int left[n1], right[n2];

  for(i = 0; i < n1; i++) {
    left[i] = a[l + i];
  }
  for(j = 0; j < n2; j++) {
    right[j] = a[m + j + 1];
  }


  // Merging 2 sets
  i = 0;
  j = 0;
  k = l;

  while(i < n1 && j < n2) {
      if(left[i] <= right[j]) {
        a[k] = left[i];
        i++;
        k++;
      } else {
        a[k] = right[j];
        j++;
        k++;
      }
    }

    while(i < n1) {
      a[k] = left[i];
      i++;
      k++;
    }
    while(j < n2) {
      a[k] = right[j];
      j++;
      k++;
    }
  }

  void MergeSort(int a[], int l, int h) {
    if(h > l) {
      int mid = l + (h - l) / 2;
      MergeSort(a, l, mid);
      MergeSort(a, mid + 1, h);
      Merge(a, l, mid, h);
    }
  }

int arr[51];

// 0 1 1 2 3 5 8
int fibonacci(int n) {
  if(n <= 1) {
    return n;
  }
  if(arr[n] != -1) {
    return arr[n];
  }
  arr[n] = fibonacci(n-1) + fibonacci(n-2);
  return arr[n];
}

int main () {
  // int arr[] = {12, 11, 13, 5, 6, 7};
  // int size = sizeof(arr)/sizeof(arr[0]);
  // cout << (0 + size - 1) /2 << endl;
  // MergeSort(arr, 0, size - 1);
  // for (int i = 0; i < size; i++) {
  //   cout << arr[i] << " ";
  // }
  // return 0;

  for(int i = 0; i < 51; i++) {
    arr[i] = -1;
  }
  int n = fibonacci(40);
  cout << n << endl;
}
