#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int max(int x, int y) {
  return (x > y) ? x: y;
}

bool isPalindrome(string s) {
  int i = 0;
  int j = s.length() - 1;
  while(i < j) {
    if(s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

// Dynamic programming
int PP(string s) {
  int n = s.length();
  int C[n][n];
  for(int i = 0; i < n; i++) {
    C[i][i] = 0;
  }
  // L - lenth of substring
  for(int L = 2; L < n + 1; L++) {
    // Starting index
    for(int i = 0; i < n - L + 1; i++) {
      // Ending index
      int j = i + L - 1;
      // if length is 2
      if(L == 2) {
        // if two char is same, no need to cut
        if(s[i] == s[j]) {
          C[i][j] = 1;
        } else {
          C[i][j] = 0;
        }
      }

      // If substring is palindrome, no need to cut
      if(isPalindrome(s.substr(i, j-i+1)) == true) {
        C[i][j] = 0;
      } else {
        // If substring is not palindrome, try to cut string (i, Wk) and (k+1, j)
        C[i][j] = INT_MAX;
        for(int k = i; k < j; k++) {
          if(C[i][j] > min(C[i][j], C[i][k] + C[k+1][j] + 1)) {
            C[i][j] = min(C[i][j], C[i][k] + C[k+1][j] + 1);
          }
        }
      }
    }
  }
  return C[0][n-1];
}
int main() {
  string s = "ababbbabbababa";
  cout << PP(s) << endl;
  return 0;
}
