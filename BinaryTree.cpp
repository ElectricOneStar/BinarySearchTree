#include <iostream>
#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std;
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced);
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size);
void Add();
void Subtract();
void Print();
void Search();
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
  (*size) = 1;
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
      cout << "Input: " << input << endl;
  }
  else if(strcmp(inputType, "File") == 0){
    cout << "Please Enter the name of the file" << endl;
    cin.get(FileName, 500);
    cin.ignore();
      cin.clear();
      ifstream rfile;
      rfile.open(FileName);
      rfile.getline(input, 500);
      cout << "Input: " << input << endl;
  }
  maxSize( input, size);
  cout << "First Number: " << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
  BuildTree(input, index, counterOne, wordCounter, parced, size);
  do{
  cout << "The Binary tree is now created. you can ADD, SUBTRACT, SEARCH, or PRINT from the tree. You can also type QUIT if you want to quit the program" << endl;
  cin.get(inputFunction, 20);
  //cin.ignore();
  cin.clear();
    cin.ignore();
  if(strcmp(inputFunction, "ADD") == 0){
    // cout << "add" << endl;
       Add();
  }
    if(strcmp(inputFunction, "SUBTRACT") == 0){
      // cout << "subtract" << endl;
       Subtract();
    }
      if(strcmp(inputFunction, "SEARCH") == 0){
	//cout << "search" << endl;
	Search();
      }
        if(strcmp(inputFunction, "PRINT") == 0){
	  //  cout << "print" << endl;
	  Print();
	}
	if(strcmp(inputFunction, "QUIT") == 0){
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
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size){
  //Node* one = new Node;
      // (*one).setData(Parce(input, index, counterOne, wordCounter, parced));

  cout << "build tree" << endl;
  cout << (*size) << endl;
  do{
    Node* one = new Node;
    (*one).setData(Parce(input, index, counterOne, wordCounter, parced));
    cout << "data" << (*(*one).getData()) << endl;
    (*index)++;
  }
while((*index) != (*size)+1);
}
void Add(){
  cout << "add" << endl;
}

void Subtract(){
  cout << "subtract" << endl;
}

void Print(){
  cout << "print" << endl;
}

void Search(){
  cout << "search" << endl;
}
void maxSize(char* input, int* size){
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == ' '){
      (*size)++;
    }
  }
}
