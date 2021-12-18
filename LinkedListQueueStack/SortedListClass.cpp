#include <iostream>
#include <fstream>
#include "SortedListClass.h"
#include "LinkedNodeClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: 11/09/2021 - 11/18/2021
//Purpose: Develop functionalities of sorted linked list, queue, and stack.

SortedListClass :: SortedListClass(){
  head = 0;
  tail = 0;
}

SortedListClass :: SortedListClass(const SortedListClass &rhs){
  head = 0;
  tail = 0;
  for(int numNode = 0; numNode < rhs.getNumElems(); numNode ++){
    int currentNodeVal;
    if(rhs.getElemAtIndex(numNode, currentNodeVal)){
      insertValue(currentNodeVal);
    }
  }
}

SortedListClass :: ~SortedListClass(){
  clear();
}

void SortedListClass :: clear(){
  LinkedNodeClass* tempPtr = head;
  LinkedNodeClass* toDeletePtr = head;
  if(tempPtr != 0){
    while(tempPtr != 0){
      tempPtr = tempPtr -> getNext();
      delete toDeletePtr;
      toDeletePtr  = tempPtr;
    }
  }
  head = 0;
  tail = 0;
}

void SortedListClass :: insertValue(const int &valToInsert){
  if(head == 0){
    LinkedNodeClass* newPtr = new LinkedNodeClass(0, valToInsert, 0);
    head = newPtr;
    tail = newPtr;
  }else{
    LinkedNodeClass* tempPtr = head;
    int currentNodeVal;
    currentNodeVal = head -> getValue();
    while((currentNodeVal < valToInsert) && (tempPtr != 0)){
      if(tempPtr -> getNext() != 0){
        tempPtr = tempPtr -> getNext();
        currentNodeVal = tempPtr -> getValue();
      }else{
        tempPtr = 0;
      }
    }
    //insterted value smaller than the first value in the list
    if(tempPtr == head){
      LinkedNodeClass* newPtr = new LinkedNodeClass(0, valToInsert, head);
      newPtr -> setBeforeAndAfterPointers();
      head = newPtr;
    //insterted value bigger than the last value in the list
    }else if(tempPtr == 0){
      LinkedNodeClass* newPtr = new LinkedNodeClass(tail, valToInsert, 0);
      newPtr -> setBeforeAndAfterPointers();
      tail = newPtr;
    }else{
      LinkedNodeClass* newPtr = new LinkedNodeClass(tempPtr -> getPrev(), 
                                                    valToInsert, 
                                                    tempPtr);
      newPtr -> setBeforeAndAfterPointers();
    }
  }
}

void SortedListClass :: printForward() const{
  LinkedNodeClass* tempPtr = head;
  cout << "Forward List Contents Follow:" << endl;
  while(tempPtr != 0){
    cout << "  " << tempPtr -> getValue() << endl;
    tempPtr = tempPtr -> getNext();
  }
  cout << "End Of List Contents" << endl;
}

void SortedListClass :: printBackward() const{
  LinkedNodeClass* tempPtr = tail;
  cout << "Backward List Contents Follow:" << endl;
  while(tempPtr != 0){
    cout << "  " << tempPtr -> getValue() << endl;
    tempPtr = tempPtr ->getPrev();
  }
  cout << "End Of List Contents" << endl;
}

bool SortedListClass :: removeFront(int &theVal){
  if(head == 0){
    return false;
  }else{
    theVal = head -> getValue();
    LinkedNodeClass* tempPtr = head;
    if(head -> getNext() != 0){
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

bool SortedListClass :: removeLast(int &theVal){
  if(tail == 0){
    return false;
  }else{
    theVal = tail -> getValue();
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

int SortedListClass :: getNumElems() const{
  int elemsCount = 0;
  if(head == 0 && tail == 0){
    return elemsCount;
  }else{
    LinkedNodeClass* tempPtr = head;
    while(tempPtr != 0){
      elemsCount ++;
      tempPtr = tempPtr -> getNext();
    }
    return elemsCount;
  }
}

bool SortedListClass :: getElemAtIndex(const int index, int &outVal) const{
  if(index >= getNumElems()){
    return false;
  }else if(index < 0){
    return false;
  }else{
    int currentIndex = 0;
    LinkedNodeClass* tempPtr = head;
    while(currentIndex < index){
      tempPtr = tempPtr -> getNext();
      currentIndex ++;
    }
    outVal = tempPtr -> getValue();
    return true;
  }
}