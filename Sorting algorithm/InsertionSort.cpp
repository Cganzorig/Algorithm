#include <iostream>

using namespace std;

void swap (int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void InsertionSort(int a[], int n) {
  for(int i = 1; i < n; i++) {
    int value = a[i];
    int hole = i;
    while(hole > 0 && a[hole - 1] >= value) {
      a[hole] = a[hole-1];
      hole--;
    }
    a[hole] = value;
  }
}


int main() {
  int a[] = {7, 6, 5, 4, 1, 8, 2, 0};
  InsertionSort(a, 8);
  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
