#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;
};

Node* top;

void push(int x) {
  Node* temp = new Node();
  temp->data = x;
  temp->next = top;
  top = temp;
}

void pop() {
  Node* temp = new Node();
  if (temp == NULL) return;
  temp = top;
  top = temp->next;
  delete temp;
}

void printList() {
  Node* temp = top;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}


int main() {
  top = NULL;
  push(2);
  push(5);
  push(6);
  pop();
  printList();

  return 0;
}
