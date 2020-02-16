#include <iostream>

using namespace std;

// Choose a pivot and pIndex
// Arrange array that all the element less than pivot should be on the left side of pivot
// And all the element greater than the pivot should be on the right side of pivot

void swap (int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// int Partition(int* a, int start, int end) {
//   int pivot = a[end];
//   int pIndex = start;
//   for (int i = start; i < end; i++) {
//     if (a[i] <= pivot) {
//       swap(a[i], a[pIndex]);
//       pIndex++;
//     }
//   }
//   swap(a[pIndex], a[end]);
//   return pIndex;
// }
//
//
// void QuickSort(int* a, int start, int end) {
//   if (start < end) {
//     int pIndex = Partition(a, start, end);
//     QuickSort(a, start, pIndex - 1);
//     QuickSort(a, pIndex + 1, end);
//   }
// }


int Partition(int a[], int start, int end) {
  int pivot = a[end];
  int pIndex = start;
  for(int i = start; i < end; i++) {
    if(a[i] <= pivot) {
      swap(a[i], a[pIndex]);
      pIndex++;
    }
  }
  swap(a[pIndex], a[end]);
  return pIndex;
}

void QuickSort(int a[], int start, int end) {
  if(start < end) {
    int pIndex = Partition(a, start, end);
    QuickSort(a, start, pIndex - 1);
    QuickSort(a, pIndex, end);
  }
}

int main() {
  int a[] = {7, 6, 5, 4, 3, 2, 1, 0};
  QuickSort(a, 0, 7);
  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
