#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) {
  return (a>b)?a:b;
}

// Recursive
int LCS(char *a, int i, char *b, int j) {
  // if one of 2 strings ends
  if(a[i] == '\0' || b[j] == '\0') {
    return 0;
  // if two character match
  } else if(a[i] == b[j]) {
    return 1 + LCS(a, i+1, b, j+1);
  // otherwise, go left and right, get max of these two
  } else {
    return max(LCS(a, i+1, b, j), LCS(a, i, b, j+1));
  }
}

// Dynamic programming
int LCSDP(string a, string b) {
  int m = a.length();
  int n = b.length();
  int lookUp[m+1][n+1];
  for(int i = 0; i < m+1; i++) {
    lookUp[i][0] = 0;
  }
  for(int j = 0; j < n+1; j++) {
    lookUp[0][j] = 0;
  }

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(a[i] == b[j]) {
        lookUp[i][j] = 1 + lookUp[i-1][j-1];
      } else {
        lookUp[i][j] = max(lookUp[i-1][j], lookUp[i][j-1]);
      }
    }
  }
  return lookUp[m][n];
}

int main() {
  string x = "AGGTAB";
  string y = "GXTXAYB";
  cout << LCSDP(x, y) << endl;
  return 0;
}
