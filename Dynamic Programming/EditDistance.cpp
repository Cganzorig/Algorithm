#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

// Dynamic programming
int EditDistance(string a, string b) {
  int m = a.length();
  int n = b.length();
  int lookUp[m+1][n+1];
  for(int i = 0; i < m+1; i++) {
    lookUp[i][0] = i;
  }
  for(int j = 0; j < n+1; j++) {
    lookUp[0][j] = j;
  }

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      // The reason i-1, j-1 is that first char starts at 0
      if(a[i-1] == b[j-1]) {
        // If 2 char is equal, get previous diagonal
        lookUp[i][j] = lookUp[i-1][j-1];
      } else {
        // Otherwise, get min of left, diagonal, right and plus 1
        lookUp[i][j] = 1 + min(lookUp[i-1][j], lookUp[i][j-1], lookUp[i-1][j-1]);
      }
    }
  }
  return lookUp[m][n];
}

int main() {
  string str1 = "food";
  string str2 = "money";
  cout << EditDistance(str1, str2) << endl;
  return 0;
}
