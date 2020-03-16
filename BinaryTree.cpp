#include <iostream>
#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std;
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced);
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header);
void Add(Node* header, Node* add);
void Subtract();
void Print(Node* header, int length, int count, int i);
//void Search();
void Search(Node* header, int* searchData, bool* exists);
void maxSize(char* input, int* size);
int main(){
  char* inputType = new char[20];
  char* input = new char[500];
  char* FileName = new char[20];
  char* inputFunction = new char[20];
  bool quit = false;
  int* index = new int;
  int* parced = new int;
  int* counterOne = new int;
  (*counterOne) = 0;
  int* wordCounter = new int;
  (*wordCounter) = 0;
  int* size = new int;
  Node* header = new Node;
  (*size) = 1;
  char* additionInput = new char[20];
  bool* exists = new bool;
  (*exists) = false;
  // Node* one = new Node;
  //(*one).setData(Parce(input, index, counterOne, wordCounter, parced));
  char* searchInput = new char[20];
  /*
  int* ones = new int;
  int* twos = new int;
  int* threes = new int;
  */
(*index) = 1;
  do{
  cout << "Welcome to Binary Tree Please Select your Input: User or File" << endl;
  cin.get(inputType, 20);
  cin.clear();
  cin.ignore();
  }
  while(strcmp(inputType, "User") != 0 && strcmp(inputType, "File") != 0);
  if(strcmp(inputType, "User") == 0){
    cout << "Please Enter a series of number separated by spaces. Up to 100 numbers should be stored" << endl;
    cin.get(input, 500);
    cin.ignore();
      cin.clear();
      //cout << "Input: " << input << endl;
  }
  else if(strcmp(inputType, "File") == 0){
    cout << "Please Enter the name of the file" << endl;
    cin.get(FileName, 500);
    cin.ignore();
      cin.clear();
      ifstream rfile;
      rfile.open(FileName);
      rfile.getline(input, 500);
      //cout << "Input: " << input << endl;
  }
  maxSize( input, size);
  //cout << "First Number: " << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
  BuildTree(input, index, counterOne, wordCounter, parced, size, header);
  do{
  cout << "The Binary tree is now created. you can ADD, SUBTRACT, SEARCH, or PRINT from the tree. You can also type QUIT if you want to quit the program" << endl;
  cin.get(inputFunction, 20);
  //cin.ignore();
  cin.clear();
    cin.ignore();
    if(strcmp(inputFunction, "ADD") == 0){ //works
    // cout << "add" << endl;
    cout << "Please enter the 3 digit value that you want to add to the tree" << endl;
    cin.get(additionInput, 20);
    cin.clear();
    cin.ignore();
        Node* two = new Node;
    (*two).setData(Parce(additionInput, index, counterOne, wordCounter, parced));
    //cout << "added data" << (*(*two).getData()) << endl;
    Add(header, two);
    cout << "Added" << endl;
  }
    if(strcmp(inputFunction, "SUBTRACT") == 0){
      // cout << "subtract" << endl;
      Subtract();
    }
    if(strcmp(inputFunction, "SEARCH") == 0){ // works
	//cout << "search" << endl;
	//int Length = (*size);
	cout << "Please enter the 3 digit number that you want to search for in the tree" << endl;
	  cin.get(searchInput, 20);
	cin.clear();
	cin.ignore();
	Search(header, Parce(searchInput, index, counterOne, wordCounter, parced), exists);
	if((*exists) == true){
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " exists in the tree" << endl;
	}
	if((*exists) == false){
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
      }
      if(strcmp(inputFunction, "PRINT") == 0){ // works
	  //  cout << "print" << endl;
	  int Length = (*size);
	  Print(header, Length, 0, 1);
	}
	if(strcmp(inputFunction, "QUIT") == 0){ // works
	  quit = true;
	}
	//if(strcmp(inputFunction, "ADD") == 0){
	//  cout << "add" << endl;
	//  }

  }
  while(strcmp(inputFunction, "ADD") != 0 && strcmp(inputFunction, "SUBTRACT") != 0 && strcmp(inputFunction, "SEARCH") != 0 && strcmp(inputFunction, "PRINT") != 0 && strcmp(inputFunction, "QUIT") != 0 || quit == false); 
}
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced){
  //cout << "parce" << endl;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] != ' ' && (*wordCounter) != 3){
      (*wordCounter)++;
	if((*wordCounter) == 1){
	  (*parced) = (int)input[i]-48;
	}
      	if((*wordCounter) == 2){
	  (*parced) = (int)input[i]-48 + (*parced)*10;
	}
	if((*wordCounter) == 3){
	  (*parced) = (int)input[i]-48 + (*parced)*10;
	}

      
    }
    if(input[i] == ' '){
      (*wordCounter) = 0;
      (*counterOne)++;
    }
    if((*counterOne) == (*index) || input[i+1] == '\0'){
      (*wordCounter) = 0;
      (*counterOne) = 0;
      return parced;
    }
  }
  //return index;
}
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header){
  //Node* one = new Node;
      // (*one).setData(Parce(input, index, counterOne, wordCounter, parced));

  // cout << "build tree" << endl;
  // cout << (*size) << endl;
  // Node* header = new Node;
  (*header).setData(Parce(input, index, counterOne, wordCounter, parced));
  (*index)++;
  //cout << "head data" << (*(*header).getData()) << endl;
  do{
    Node* one = new Node;
    (*one).setData(Parce(input, index, counterOne, wordCounter, parced));
    //cout << "data" << (*(*one).getData()) << endl;
    Add(header, one);
    (*index)++;
  }
while((*index) != (*size)+1);
  //cout << "double jump value: " <<  (*(*(*(*header).getRight()).getRight()).getData())<< endl;
  //cout << "triple jump value: " <<  (*(*(*(*(*header).getRight()).getRight()).getRight()).getData())<< endl;
}
void Add(Node* header, Node* add){
  // cout << "add" << endl;
  if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() != NULL){
    Add((*header).getLeft(), add);
  }
  //if((*(*header).getData()) >= (*(*add).getData()) && (*header).getLeft() == NULL){
     if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() == NULL){
       (*header).setLeft(add);
     }

     //if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() != NULL){
      if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() != NULL){
	Add((*header).getRight(), add);
  }
      // if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() == NULL){
  if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() == NULL){
    (*header).setRight(add);
  }
}
void Subtract(){
  cout << "subtract" << endl;
}

void Print(Node* header, int length, int count, int i){
  //cout << "print" << endl;
   int left = 2*i;
  int right = 2*i+1;
  // if(right <= length && (*header).getRight() != NULL){ // right child exist so recurse
      if((*header).getRight() != NULL){ // right child exist so recurse
    Print((*header).getRight(), length, count+1, right);
  }
  int current = count;
  while(count > 0){
    cout << "    ";
    count--;
  }
  cout << (*(*header).getData()) << endl;
  //cout << sortedHeap[i-1 << endl; // print current with some number of idenetation
  // if(left <= length && (*header).getLeft() != NULL){ // left child exists so recurse
      if((*header).getLeft() != NULL){ // left child exists so recurse
    Print((*header).getLeft(), length, current + 1, left);
  }
}


void Search(Node* header, int* searchData, bool* exists){
  //cout << "search" << endl;
         if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }

  if((*header).getRight() != NULL && (*searchData) > (*(*header).getData())){
	 Search((*header).getRight(), searchData, exists);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
  */
       if((*header).getLeft() != NULL && (*searchData) <= (*(*header).getData())){
	 Search((*header).getLeft(), searchData, exists);
       }
}
void maxSize(char* input, int* size){
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == ' '){
      (*size)++;
    }
  }
}
