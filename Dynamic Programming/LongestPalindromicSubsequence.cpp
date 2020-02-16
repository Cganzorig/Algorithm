#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
  return (x > y) ? x : y;
}

// Dynamic programming
int LPS(char *str) {
  int n = strlen(str);
  int L[n][n];
  // Diagonal is 1 if the length of substring is 1
  for(int i = 0; i < n; i++) {
    L[i][i] = 1;
  }

  // cl - length of substring
  for(int cl = 2; cl < n + 1; cl++) {
    // i is the first letter of the substring
    for(int i = 0; i < n - cl + 1; i++) {
      // j is the last letter of the substring
      int j = i + cl - 1;
      if(str[i] == str[j] && cl == 2) {
        L[i][j] = 2;
      } else if (str[i] == str[j]) {
        L[i][j] = 2 + L[i+1][j-1];
      } else {
        L[i][j] = max(L[i][j-1], L[i+1][j]);
      }
    }
  }
  return L[0][n-1];
}

int main() {
  char s[] = "GEEKS FOR GEEKS";
  cout << LPS(s) << endl;
  return 0;
}
