#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;
};

Node* front;
Node* rear;

void push(int x) {
  Node* temp = new Node();
  temp->data = x;
  temp->next = NULL;

  // When there is no member
  if (front == NULL && rear == NULL) {
    front = temp;
    rear = temp;
  }
  rear->next = temp;
  rear = temp;
}

void pop() {
  Node* temp = front;
  if (front == NULL) return;
  if (front == rear) {
    front = NULL;
    rear = NULL;
  } else {
    front = temp->next;
  }
  delete temp;
}

void printList() {
  Node* temp = front;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

int main() {
  front = NULL;
  rear = NULL;
  push(2);
  push(5);
  push(6);
  printList();
  pop();
  printList();
  pop();
  printList();
  push(7);
  printList();



  return 0;
}
