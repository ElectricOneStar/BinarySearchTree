/*
Header Node file by Andrew Thomas 3/19/20. This is a node with a right and left node and data with it
 */
#ifndef NODE_H
#define NODE_H
#include <iostream> 
#include<cstring>
using namespace std;

class Node{
 public:
  Node(); // constructor
  ~Node(); // destructor
  void setRight(Node* inputRight); // setters
  void setLeft(Node* inputLeft);
  void setData(int* inputData);
  Node* getRight(); // getters
  Node* getLeft();
  int* getData();
private: // right left and data storage
  Node* right;
  Node* left;
  int* data = new int;
};
#endif
