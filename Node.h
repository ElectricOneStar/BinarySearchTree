#ifndef NODE_H
#define NODE_H
#include <iostream>
#include<cstring>
using namespace std;

class Node{
 public:
  Node();
  void setRight(Node* inputRight);
  void setLeft(Node* inputLeft);
  void setData(int* inputData);
  Node* getRight();
  Node* getLeft();
  int* getData();
 private:
  Node* right;
  Node* left;
  int* data = new int;
};
#endif
