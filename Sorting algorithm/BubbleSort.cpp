#include <iostream>

using namespace std;

// void swap (int& a, int& b) {
//   int temp = a;
//   a = b;
//   b = temp;
// }
//
//
// void BubbleSort(int* a, int n) {
//   for (int i = 0; i < n - 1; i++) {
//     for (int j = 0; j < n - i - 1; j++) {
//       if (a[j] > a[j+1]) {
//         swap(a[j], a[j+1]);
//       }
//     }
//   }
// }

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

void BubbleSort(int a[], int n) {
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
      }
    }
  }
}

int main() {
  int a[] = {7, 6, 5, 4, 1, 5, 2, 0};
  BubbleSort(a, 8);
  for (int i = 0; i < 8; i++) {
    cout << a[i];
  }
  return 0;
}
