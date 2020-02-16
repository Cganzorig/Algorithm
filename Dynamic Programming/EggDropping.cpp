#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
  return (x > y) ? x : y;
}

// Dynamic programming
int EggDrop(int n, int k) {
  int egg[n+1][k+1];
  // One trial for one floor and 0 trial for 0 floor
  for(int i = 1; i < n + 1; i++) {
    egg[i][0] = 0;
    egg[i][1] = 1;
  }
  //j trials for j th floor for one egg
  for(int j = 1; j < k + 1; j++) {
    egg[1][j] = j;
  }

  int res;
  // n - the number of eggs
  // k - the number of floors
  for(int i = 2; i < n + 1; i++) {
    for(int j = 2; j < k + 1; j++) {
      egg[i][j] = INT_MAX;
      for(int x = 1; x < j + 1; x++) {
        // egg[i-1][j-1] - if egg breaks, try one less egg and one less floor
        // egg[i][j-x] - if egg does not break, try same number of eggs and remaining floor
        res = 1 + max(egg[i-1][j-1], egg[i][j-x]);
        if(res < egg[i][j]) {
          egg[i][j] = res;
        }
      }
    }
  }
  return egg[n][k];
}
int main() {
  int n = 2, k = 36;
  cout << "Minimum number of trials in worst case with "
       << n << " eggs and " << k << " floors is "
       << EggDrop(n, k) << endl;
  return 0;
}
