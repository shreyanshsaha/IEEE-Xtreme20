// NEW
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  long key;
  struct Node *left, *right;
};

Node* newNode(long item) {
  Node* temp = new Node;
  temp->key = item;
  temp->left = temp->right = nullptr;
  return temp;
}

Node* insert(Node* root, int key, int level) {
//  Node* x = root;
  Node* y = nullptr;

  while (root != nullptr) {
    ++level;
    y = root;
    root = (key <= root->key)? root->left:root->right;
  }
  cout << level << " ";
  Node* newnode = newNode(key);

  if (y == nullptr)
    y = newnode;
  else if (key <= y->key)
    y->left = newnode;
  else
    y->right = newnode;

  return y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  long a;
  Node* root = nullptr;

  cin >> n;
  cin >> a;
  root = insert(root, a, 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    insert(root, a, 1);
  }

  return 0;
}
