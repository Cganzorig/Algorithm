#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct Node* head;

// Insert a node at the beginning
// void insert(int x) {
//   Node* temp = new Node();
//   temp->data = x;
//   temp->next = head;
//   head = temp;
// }

// Insert a node at the N th position
void insert (int x, int n) {
  Node* temp = new Node();
  temp->data = x;
  temp->next = NULL;

  // head - 1 - 2; when you put a new number at the beginning, 1) temp (next) -> head 2) head -> temp
  if (n == 1) {
    temp->next = head;
    head = temp;
    return;
  }

  Node* temp1 = head;
  // Loop until node that links to n-1
  for (int i = 0; i < n - 2; i++) {
    temp1 = temp1->next;
  }
  temp->next = temp1->next;
  temp1->next = temp;

}

void Delete(int n) {
  Node* temp = head;

  if (n == 1) {
    head = temp->next;
    delete temp;
    return;
  }
  // 1 1 1 4 1 1 1
  for (int i = 0; i < n - 2; i++) {
    temp = temp->next;
  } // temp points to N-1
  Node* temp1 = temp->next; // temp1 points to N
  temp->next = temp1->next; // temp points to N+1
  delete temp1;
}

void print() {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}


int main() {
  head = NULL;

  // Node* temp = new Node(); // Temp is POINTER to a NODE!!!
  // temp->data = 2;
  // temp->next =NULL;

  insert(5, 1);
  insert(3, 1);
  insert(2, 2);
  print();
  Delete(2);
  print();


  return 0;
}
