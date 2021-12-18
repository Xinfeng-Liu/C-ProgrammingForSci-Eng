#include <iostream>
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: 11/09/2021 - 11/18/2021
//Purpose: Develop functionalities of sorted linked list, queue, and stack.

FIFOQueueClass :: FIFOQueueClass(){
  head = 0;
  tail = 0;
}

FIFOQueueClass :: ~FIFOQueueClass(){
  clear();
}

void FIFOQueueClass :: enqueue(const int &newItem){
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

bool FIFOQueueClass :: dequeue(int &outItem){
  if(head == 0){
    return false;
  }else{
    outItem = tail -> getValue();
    LinkedNodeClass* tempPtr = tail;
    if(tail -> getPrev() != 0){
      tail = tempPtr -> getPrev();
      delete tempPtr;
      tail -> setNextPointerToNull();
    }else{
      delete tempPtr;
      head = 0;
      tail = 0;
    }
    return true;
  }
}

void FIFOQueueClass :: print() const{
  LinkedNodeClass* tempPtr = head;
  while(tempPtr != 0){
    cout << tempPtr -> getValue() << " ";
    tempPtr = tempPtr -> getNext();
  }
  cout << endl;
}

int FIFOQueueClass :: getNumElems() const{
  int elemsCount = 0;
  LinkedNodeClass* tempPtr = head;
  if(head == 0){
    return elemsCount;
  }else{
    while(tempPtr != 0){
      elemsCount ++;
      tempPtr =  tempPtr -> getNext();
    }
  }
  return elemsCount;
}

void FIFOQueueClass :: clear(){
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