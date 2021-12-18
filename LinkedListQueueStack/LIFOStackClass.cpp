#include <iostream>
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: 11/09/2021 - 11/18/2021
//Purpose: Develop functionalities of sorted linked list, queue, and stack.

LIFOStackClass :: LIFOStackClass(){
  head = 0;
  tail = 0;
}

LIFOStackClass :: ~LIFOStackClass(){
  clear();
}

void LIFOStackClass :: push(const int &newItem){
  LinkedNodeClass* newPtr;
  if(head == 0){
    newPtr = new LinkedNodeClass(0, newItem, 0);
    head = newPtr;
    tail = newPtr;
  }else{
    //insert from front
    newPtr = new LinkedNodeClass(0, newItem, head);
    newPtr -> setBeforeAndAfterPointers();
    head = newPtr;
  }
}

bool LIFOStackClass :: pop(int &outItem){
  if(head == 0){
    return false;
  }else{
    outItem = head -> getValue();
    LinkedNodeClass* tempPtr = head;
    if(tempPtr -> getNext()){
      head = tempPtr -> getNext();
      delete tempPtr;
      head -> setPreviousPointerToNull();
    }else{
      delete tempPtr;
      head = 0;
      tail = 0;
    }
    return true;
  }
}

void LIFOStackClass :: print() const{
  LinkedNodeClass* tempPtr = head;
  while(tempPtr != 0){
    cout << tempPtr -> getValue() << " ";
    tempPtr = tempPtr -> getNext();
  }
  cout << endl;
}

int LIFOStackClass :: getNumElems() const{
  int elemsCount = 0;
  LinkedNodeClass* tempPtr = head;
  if(head == 0){
    return elemsCount;
  }else{
    while(tempPtr != 0){
      elemsCount ++;
      tempPtr = tempPtr -> getNext();
    }
  }
  return elemsCount;
}

void LIFOStackClass :: clear(){
  LinkedNodeClass* tempPtr = head;
  LinkedNodeClass* toDeletePtr = head;
  if(head != 0){
    tempPtr = tempPtr -> getNext();
    delete toDeletePtr;
    toDeletePtr = tempPtr;
  }
  head = 0;
  tail = 0;
}