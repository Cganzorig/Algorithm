#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;
};

Node* createTree(int data) {
  Node* temp = new Node();
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}


Node* Insert(Node* root, int data) {
  if(root == NULL) {
    root = createTree(data);
  } else if (data <= root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
}


bool Search(Node* root, int data) {
  if(root == NULL) return false;

  if(root->data == data) {
    return true;
  } else if(root->data <= data) {
    return Search(root->left, data);
  } else {
    return Search(root->right, data);
  }
}


int FindMin(Node* root) {
  Node* temp = root;
  while(temp->left != NULL) {
    temp = temp->left;
  }
  return temp->data;
}


int FindMax(Node* root) {
  Node* temp = root;
  while(temp->right != NULL) {
    temp = temp->right;
  }
  return temp->data;
}


int FindHeight(Node* root) {
  if(root == NULL) return -1;
  int l = FindHeight(root->left);
  int r = FindHeight(root->right);
  return max(l, r) + 1;
}


void LevelOrder(Node* root) {
  if(root == NULL) {
    return;
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    Node* temp = q.front();
    cout << temp->data << endl;
    if(temp->left != NULL) {
      q.push(temp->left);
    }
    if(temp->right != NULL) {
      q.push(temp->right);
    }
    q.pop();
  }
}


void Preorder(Node* root) {
  if(root == NULL) {
    return;
  }
  cout << root->data << endl;
  Preorder(root->left);
  Preorder(root->right);
}


void Inorder(Node* root) {
  if(root == NULL) {
    return;
  }
  Inorder(root->left);
  cout << root->data << endl;
  Inorder(root->right);
}


void Postorder(Node* root) {
  if(root == NULL) {
    return;
  }
  Postorder(root->left);
  Postorder(root->right);
  cout << root->data << endl;
}





// class Node {
// public:
//   int data;
//   Node* left;
//   Node* right;
// };
//
//
// Node* createTree(int data) {
//   Node* temp = new Node();
//   temp->data = data;
//   temp->left = NULL;
//   temp->right = NULL;
//   return temp;
// }
//
// Node* Insert(Node* root, int data) {
//   if (root == NULL) {
//     root = createTree(data);
//   } else if (data <= root->data) {
//     root->left = Insert(root->left, data);
//   } else {
//     root->right= Insert(root->right, data);
//   }
//
//   return root;
// }
//
// bool Search(Node* root, int data) {
//   if (root == NULL) return false;
//
//   if (data == root->data) {
//     return true;
//   } else if (data < root->data) {
//     return Search(root->left, data);
//   } else {
//     return Search(root->right, data);
//   }
// }
//
// int FindMin(Node* root) {
//   Node* temp = root;
//   while(temp->left != NULL) {
//     temp = temp->left;
//   };
//   return temp->data;
// }
//
// int FindMax(Node* root) {
//   Node* temp = root;
//   while(temp->right != NULL) {
//     temp = temp->right;
//   };
//   return temp->data;
// }
//
// int FindHeight(Node* root) {
//   if (root == NULL)
//     return -1;
//
//   int left = FindHeight(root->left);
//   int right = FindHeight(root->right);
//   return max(left, right) + 1;
// }
//
// void LevelOrder(Node* root) {
//   if (root == NULL) {
//     return;
//   }
//   queue<Node*> Q;
//   Q.push(root);
//   // When there is at least one element
//   while(!Q.empty()){
//     Node* current = Q.front();
//     cout << current->data << " ";
//     if (current->left != NULL) {
//       Q.push(current->left);
//     }
//     if (current->right != NULL) {
//       Q.push(current->right);
//     }
//     Q.pop();
//   }
//
// }
// //  <root> <left> <right>
// void Preorder (Node* root) {
//   if (root == NULL) {
//     return;
//   }
//   cout << root->data << endl;
//   Preorder(root->left);
//   Preorder(root->right);
// }
//
// void Inorder (Node* root) {
//   if (root == NULL) {
//     return;
//   }
//   Preorder(root->left);
//   cout << root->data << endl;
//   Preorder(root->right);
// }
//
// void Postorder (Node* root) {
//   if (root == NULL) {
//     return;
//   }
//   Preorder(root->left);
//   Preorder(root->right);
//   cout << root->data << endl;
// }



int main() {
  Node* root = NULL;
  root = Insert(root, 5);
  root = Insert(root, 3);
  root = Insert(root, 4);
  root = Insert(root, 11);

  Preorder(root);

  return 0;
}
