#include <iostream>

using namespace std;

void swap (char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

void SelectionSort(int a[], int n) {
  int minIndex;
  for(int i = 0; i < n - 1; i++) {
    minIndex = i;
    for(int j = i + 1; j < n; j++) {
      if(a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    swap(a[i], a[minIndex]);
  }
}



string no_repetition(string s) {
  // start from the end
  for (int i = s.length() - 1; i > 0; i--) {
    // compare each letter with previous letters starting from the beginning
    for (int j = 0; j < i; j++) {
      // if a same letter exists, it deletes latter at i and shift left all the letter after i
      if (s[i] == s[j]) {
        for (int k = i; s[k] != '\0'; k++) {
          s[k] = s[k+1];
        }
      }
    }
  }
  return s;
}


int main() {
  // string s = "This string contains repeated characters";
  // s = no_repetition(s);
  // cout << s << endl;

  int a[] = {7, 6, 5, 4, 1, 8, 2, 0};
  SelectionSort(a, 8);
  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
