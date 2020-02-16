#include <iostream>

using namespace std;

// FOR LOOP used
// int BinSearch(int a[], int n, int key) {
//   int i = 0;
//   for (i; i < n; i++) {
//     if (key == a[i]) {
//       return i;
//     }
//   }
// }

// int BinSearch(int a[], int n, int key) {
//   int l = 0;
//   int h = n;
//   while (l <= h) {
//     int mid = (l + h)/2;
//     if (key==a[mid]) {
//       return mid;
//     }
//     if (key < a[mid]) {
//       h = mid - 1;
//     } else {
//       l = mid + 1;
//     }
//   }
//   return 0;
// }


// int BinSearch(int a[], int l, int h, int key) {
//   if (l == h) {
//     if (key == a[l]) {
//       return l;
//     }
//     return 0;
//   } else {
//     int mid = (l + h)/2;
//     if (key == a[mid]) {
//       return mid;
//     }
//     if (key < a[mid]) {
//       return BinSearch(a, l, mid-1, key);
//     } else {
//       return BinSearch(a, mid+1, h, key);
//     }
//   }
// }

int BinSearch(int a[], int l, int h, int k) {
  if(l == h) {
    if(a[l] == k) {
      return l;
    }
  }

  int mid = (l + h) / 2;
  if(a[mid] == k) {
    return mid;
  } else if(k < a[mid]) {
    return BinSearch(a, l, mid-1, k);
  } else {
    return BinSearch(a, mid+1, h, k);
  }
}

int main() {
  int list[6] = {5, 7, 8, 9, 10, 15};
  cout << "Program starts" << endl;
  int i = BinSearch(list, 0, 6, 7);
  cout << "Index at " << i << endl;
  return 0;
}
