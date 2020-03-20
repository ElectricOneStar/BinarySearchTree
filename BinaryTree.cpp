/*
Binary Search Tree by Andrew Thomas 3/18/20. this code will take either a user input or a file input of 3 digit numbers separated by spaces. Then it will parce those numbers and put them in a tree. Once the tree is built the user can add, search, or delete nodes from the tree. The user can also print the tree and exit the program by inputting quit
 */
#include <iostream>
#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std;
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced); // functions
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header);
void Add(Node* header, Node* add);
//void Subtract();
void Subtract(Node* header, int* deleteThis, Node* previous, int* DCounter, int* skip, int* special);
void Print(Node* header, int length, int count, int i);
//void Search();
void Search(Node* header, int* searchData, bool* exists);
void maxSize(char* input, int* size);
Node* getRightMost(Node* header);
int main(){ // initialization of variables
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
  char* subtractInput = new char[20];
  Node* previous = new Node;
  int* DCounter = new int;
  (*DCounter) = 0;
  int* skip = new int;
  (*skip) = 0;
  int* special = new int;
  /*
  int* ones = new int;
  int* twos = new int;
  int* threes = new int;
  */
(*index) = 1;
  do{
  cout << "Welcome to Binary Tree Please Select your Input: User or File" << endl;
  cin.get(inputType, 20); // will continue to ask for type of input
  cin.clear();
  cin.ignore();
  }
  while(strcmp(inputType, "User") != 0 && strcmp(inputType, "File") != 0);
  if(strcmp(inputType, "User") == 0){ // USER INPUT
    cout << "Please Enter a series of number separated by spaces. Up to 100 numbers should be stored" << endl;
    cin.get(input, 500); // gets the user input
    cin.ignore();
      cin.clear();
      //cout << "Input: " << input << endl;
  }
  else if(strcmp(inputType, "File") == 0){ // FILE INPUT
    cout << "Please Enter the name of the file" << endl;
    cin.get(FileName, 500); // gets the file name
    cin.ignore();
      cin.clear();
      ifstream rfile;
      rfile.open(FileName);
      rfile.getline(input, 500); // gets input from file
      //cout << "Input: " << input << endl;
  }
  maxSize( input, size); // gets size of tree
  //cout << "First Number: " << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
  BuildTree(input, index, counterOne, wordCounter, parced, size, header); // builds the tree
  do{
  cout << "The Binary tree is now created. you can ADD, DELETE, SEARCH, or PRINT from the tree. You can also type QUIT if you want to quit the program" << endl; 
  cin.get(inputFunction, 20); // gets the function that the users want to do
  //cin.ignore();
  cin.clear();
    cin.ignore();
    if(strcmp(inputFunction, "ADD") == 0){ //add function that adds a node to the tree
    // cout << "add" << endl;
    cout << "Please enter the 3 digit value that you want to add to the tree" << endl;
    cin.get(additionInput, 20);
    cin.clear();
    cin.ignore();
    Node* two = new Node; // creates the new node
    (*two).setData(Parce(additionInput, index, counterOne, wordCounter, parced));
    //cout << "added data" << (*(*two).getData()) << endl;
    Add(header, two);
    cout << "Added" << endl;
  }
    if(strcmp(inputFunction, "DELETE") == 0){ // delete function that deletes a node form tree
      // cout << "subtract" << endl;
      cout << "Please enter the 3-digit number you would like to delete from the tree" << endl; 
      cin.get(subtractInput, 20); // which node do you want to delete
      cin.clear();
      cin.ignore();
      Search(header, Parce(subtractInput, index, counterOne, wordCounter, parced), exists);
	if((*exists) == true){ // it exists
	  // cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " exists in the tree" << endl;
	  //(*(*previous).getData()) = (*(*header).getData());
	  Subtract(header, Parce(subtractInput, index, counterOne, wordCounter, parced), header, DCounter, skip, special);
	  // (*size)--;
	  if((*special) == 1){
	    (*(*header).getData()) = (*skip);
	  }
	  (*special) = 0;
	  (*skip) = 0;
	  (*DCounter) = 0;
	  cout << "deleted" << endl;
	}
	if((*exists) == false){ // it does not exist
	  cout << (*Parce(subtractInput, index, counterOne, wordCounter, parced)) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
	// Subtract();
    }
    if(strcmp(inputFunction, "SEARCH") == 0){ // function that searches the binary tree and checks if a node exists or not
	//cout << "search" << endl;
	//int Length = (*size);
	cout << "Please enter the 3 digit number that you want to search for in the tree" << endl;
	cin.get(searchInput, 20); // what node should I search for
	cin.clear();
	cin.ignore();
	Search(header, Parce(searchInput, index, counterOne, wordCounter, parced), exists);
	if((*exists) == true){ // it exists
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " exists in the tree" << endl;
	  //cout << "deleted" << endl;
	}
	if((*exists) == false){ // it does not exist
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
      }
      if(strcmp(inputFunction, "PRINT") == 0){ // function that prints the tree in a way that clearly demonstrates the parent and child relationship
	  //  cout << "print" << endl;
	  int Length = (*size);
	  if(header == NULL){
	    cout << "tree is empty" << endl;
	  }
	  else{
	  Print(header, Length, 0, 1);
	  }
	  }
	if(strcmp(inputFunction, "QUIT") == 0){ // quit the program
	  quit = true;
	}
	//if(strcmp(inputFunction, "ADD") == 0){
	//  cout << "add" << endl;
	//  }

  }
  while(strcmp(inputFunction, "ADD") != 0 && strcmp(inputFunction, "SUBTRACT") != 0 && strcmp(inputFunction, "SEARCH") != 0 && strcmp(inputFunction, "PRINT") != 0 && strcmp(inputFunction, "QUIT") != 0 || quit == false); 
}
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced){ // this function pareces the input
  //cout << "parce" << endl;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] != ' ' && (*wordCounter) != 3){ // add to integer up to 3 digits
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
    if(input[i] == ' '){ // there is a space
      (*wordCounter) = 0;
      (*counterOne)++;
    }
    if((*counterOne) == (*index) || input[i+1] == '\0'){ // I want this number pareced
      (*wordCounter) = 0;
      (*counterOne) = 0;
      return parced; // returns parced integer
    }
  }
  //return index;
}
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header){ // this builds the tree
  //Node* one = new Node;
      // (*one).setData(Parce(input, index, counterOne, wordCounter, parced));

  // cout << "build tree" << endl;
  // cout << (*size) << endl;
  // Node* header = new Node;
  (*header).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the head
  (*index)++; 
  //cout << "head data" << (*(*header).getData()) << endl;
  do{
    Node* one = new Node;
    (*one).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the new node
    //cout << "data" << (*(*one).getData()) << endl;
    Add(header, one); // adds the new node
    (*index)++;
  }
  while((*index) != (*size)+1); // continues to do this until all the numbers from input are put into the tree
  //cout << "double jump value: " <<  (*(*(*(*header).getRight()).getRight()).getData())<< endl;
  //cout << "triple jump value: " <<  (*(*(*(*(*header).getRight()).getRight()).getRight()).getData())<< endl;
}
void Add(Node* header, Node* add){ // this funcitons adds a node to the list
  // cout << "add" << endl;
  if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() != NULL){ // this node should go to the left because it is <= current node
    Add((*header).getLeft(), add);
  }
  //if((*(*header).getData()) >= (*(*add).getData()) && (*header).getLeft() == NULL){
     if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() == NULL){
       (*header).setLeft(add);
     } // add it to the end

     //if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() != NULL){
     if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() != NULL){ // this node should go to the right because it is > than current node
	Add((*header).getRight(), add);
      } 
      // if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() == NULL){
  if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() == NULL){
    (*header).setRight(add);
  } // add it to the end
}
void Subtract(Node* header, int* deleteThis, Node* previous, int* DCounter, int* skip, int* special){ // this function deletes a node from the list
  // cout << "subtract" << endl;
   if((*header).getRight() == NULL && (*header).getLeft() == NULL){
     // if((*(*(*header).getRight()).getData()) == (*deleteThis) || (*(*(*header).getLeft()).getData()) == (*deleteThis)){
     if((*(*header).getData()) == (*deleteThis)){
       //cout << "no child" << endl;
     //cout << "Parent" << (*(*header).getData()) << endl;
    //}
    if((*DCounter) == 0){
      delete header;
      return;
    }
       
    else if((*(*header).getData()) > (*(*previous).getData())){
    (*previous).setRight(NULL);
    }
    else{
      (*previous).setLeft(NULL);
    }
    (*DCounter) = 0;
    delete header;
    return;
     }
   }
   if((*header).getRight() == NULL && (*header).getLeft() != NULL || (*header).getRight() != NULL && (*header).getLeft() == NULL){
     if((*header).getRight() != NULL && (*(*header).getData()) == (*deleteThis)){
       // cout << "one right child" << endl;
       // cout << "Parent" << (*(*header).getData()) << endl;
        if((*DCounter) == 0){
	  //(*(*header).getData()) = (*(*(*header).getRight()).getData());
	  (*DCounter) = 1;
	  (*special) = 1;
	  (*skip) = (*(*(*header).getRight()).getData());
	  //  cout << "woah: "<< (*(*(*header).getRight()).getData()) << endl;
	    Subtract((*header).getRight(), (*(*header).getRight()).getData(), header, DCounter, skip, special);
	    return;
    }

	if((*(*header).getData()) > (*(*previous).getData())){
      (*previous).setRight((*header).getRight());
      //	(*DCounter) = 0;
      //	(*skip) = 0;
	delete header;
	return;

    }
     if((*(*header).getData()) <= (*(*previous).getData()) ){
      (*previous).setLeft((*header).getRight());
      //	(*DCounter) = 0;
	//	(*skip) = 0;
	delete header;
    return;

    }
     //(*skip) = 0;
	//(*DCounter) = 0;
	//delete header;
   
	//  return;
     }
     if((*header).getLeft() != NULL && (*(*header).getData()) == (*deleteThis)){
       //cout << "one left child" << endl;
       // cout << "Parent" << (*(*header).getData()) << endl;
        if((*DCounter) == 0){
	  //cout << "here" << endl;
	  	  (*DCounter) = 1;
	  (*special) = 1;
	  (*skip) = (*(*(*header).getLeft()).getData());
	  //  cout << "woah: "<< (*(*(*header).getRight()).getData()) << endl;
	    Subtract((*header).getLeft(), (*(*header).getLeft()).getData(), header, DCounter, skip, special);
	    return;
	  // header = (*header).getLeft();
	  //(*(*header).getData()) = (*(*(*header).getLeft()).getData());
	  // (*DCounter) = 1;
	  //(*skip) = 1;
	  //	  Subtract(header, (*(*header).getLeft()).getData(), header, DCounter, skip, special);
	  //return;
    }

	if((*(*header).getData()) > (*(*previous).getData())){
      (*previous).setRight((*header).getLeft());
      	(*DCounter) = 0;
	delete header;
    return;

    }
	if((*(*header).getData()) <= (*(*previous).getData())){
      (*previous).setLeft((*header).getLeft());
      	(*DCounter) = 0;
	
	delete header;
    return;

    }
	//if((*skip) == 1){
	// (*skip) = 0;
	  // Subtract((*header).getLeft(), deleteThis, header, DCounter, skip);
	//	}
	//(*skip) = 0;
	//	(*DCounter) = 0;
	//	delete header;
	//return;
     }

   }
   if((*header).getRight() != NULL && (*header).getLeft() != NULL){
          if((*(*header).getData()) == (*deleteThis)){
	    // cout << "both child" << endl;
	    //cout << "Parent" << (*(*header).getData()) << endl;
    //   (*getRightMost((*header).getLeft())).setLeft(NULL);
    // (*getRightMost((*header).getLeft())).setRight(NULL);

    if((*DCounter) == 0){
	  return;
    }
    //	(*getRightMost((*header).getLeft())).setLeft(NULL);
    //	(*getRightMost((*header).getLeft())).setRight(NULL);
	else if((*(*header).getData()) > (*(*previous).getData())){
     //(*getRightMost((*header).getLeft())).setRight((*previous).getLeft());
	  (*previous).setRight(getRightMost((*header).getLeft()));
	  (*(*header).getLeft()).setRight(NULL);
	  // (*(*header).getLeft()).setRight((*(*previous).getLeft()).getLeft());
	  (*(*header).getLeft()).setRight((*(*previous).getLeft()).getLeft());
	  (*(*(*header).getLeft()).getRight()).setRight((*(*previous).getLeft()).getRight());
	  ///(*(*previous).getRight()).setRight(NULL);
	   (*(*previous).getRight()).setRight((*header).getRight());
	   (*(*previous).getRight()).setLeft((*header).getLeft());
     //(*previous).setRight(getRightMost(header));
     // (*header)
     //(*previous).setLeft((*header).getRight());
     //(*(*previous).get()).setRight();
   }
    else{
      (*previous).setLeft(getRightMost((*header).getLeft()));
      (*(*header).getLeft()).setRight(NULL);
      (*(*header).getLeft()).setRight((*(*previous).getLeft()).getLeft());
        (*(*(*header).getLeft()).getRight()).setRight((*(*previous).getLeft()).getRight());
      (*(*previous).getLeft()).setRight((*header).getRight());

      (*(*previous).getLeft()).setLeft((*header).getLeft());
       //  (*previous).setLeft(getRightMost(header));
      // (*previous).setRight((*header).getLeft());
    }
   (*DCounter) = 0;
   delete header;
    //}
    return;
     }

   }
  
   if((*header).getRight() != NULL && (*deleteThis) > (*(*header).getData())){
     (*DCounter) = 1;
     Subtract((*header).getRight(), deleteThis, header, DCounter, skip, special);
   }
       if((*header).getLeft() != NULL && (*deleteThis) <= (*(*header).getData())){
	 (*DCounter) = 1;
	 Subtract((*header).getLeft(), deleteThis, header, DCounter, skip, special);
	 
       }

}

void Print(Node* header, int length, int count, int i){ // this funciton prints the tree where the parent and child relationship is clear
  //cout << "print" << endl;
   int left = 2*i;
  int right = 2*i+1;
  // if(right <= length && (*header).getRight() != NULL){ // right child exist so recurse
      if((*header).getRight() != NULL){ // right child exist so recurse
    Print((*header).getRight(), length, count+1, right);
  }
  int current = count;
  while(count > 0){ // add spaces
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


void Search(Node* header, int* searchData, bool* exists){ // this function searches the tree for a node
  //cout << "search" << endl;
  if((*(*header).getData()) == (*searchData)){ // THIS IS THE NODE
	 (*exists) = true;
       }

  if((*header).getRight() != NULL && (*searchData) > (*(*header).getData())){ // not the node search rihgt
	 Search((*header).getRight(), searchData, exists);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
  */
  if((*header).getLeft() != NULL && (*searchData) <= (*(*header).getData())){ // not the node so search left
	 Search((*header).getLeft(), searchData, exists);
       }
}
void maxSize(char* input, int* size){ // this function gets the size of the tree
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == ' '){ // every time there is a space there should be a new node
      (*size)++;
    }
  }
}
Node* getRightMost(Node* header){
  if((*header).getRight() == NULL){
    return header;
  }
  else{
    getRightMost((*header).getRight());
  }
}
