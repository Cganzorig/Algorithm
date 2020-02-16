#include <iostream>

using namespace std;

// int n_to_power_k(int n, int k) {
//   if(k == 0) {
//     return 1;
//   } else {
//     return n * n_to_power_k(n, k-1);
//   }
// }

int sum(int n) {
  if(n == 1) {
    return 1;
  } else {
    return n + sum(n-1);
  }
}

int main() {
  int result;
  // 5 + 4 + 3 + 2 + 1
  result = sum(5);

  cout << result << endl;
  return 0;
}
