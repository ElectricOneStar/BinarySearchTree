#include<iostream>
#include<cstring>
#include "Node.h"
using namespace std;
Node::Node(){
    right = NULL;
  left = NULL;
  //pdata = NULL;
}
Node::~Node(){

  right = NULL;
   left = NULL;
  data = NULL;
  
}
void Node::setRight(Node* inputRight){
  right = inputRight;
}
Node* Node::getRight(){
  return right;
}
void Node::setLeft(Node* inputLeft){
  left = inputLeft;
}
Node* Node::getLeft(){
  return left;
}
void Node::setData(int* inputData){
  (*data) = (*inputData);
}
int* Node::getData(){
  return data;
}
