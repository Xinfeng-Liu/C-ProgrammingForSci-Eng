#include <iostream>
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: November 30 2020
//Purpose: Develop functionalities of sorted linked list, queue, and stack.
template < class T >
FIFOQueueClass< T > :: FIFOQueueClass(){
  head = 0;
  tail = 0;
}

template < class T >
FIFOQueueClass< T > :: ~FIFOQueueClass(){
  clear();
}

template < class T >
void FIFOQueueClass< T > :: enqueue(const T &newItem){
  LinkedNodeClass< T >* newPtr;
  if(head == 0){
    newPtr = new LinkedNodeClass< T >(0, newItem, 0);
    head = newPtr;
    tail = newPtr;
  }else{
    //insert from front
    newPtr = new LinkedNodeClass< T >(0, newItem, head);
    newPtr -> setBeforeAndAfterPointers();
    head = newPtr;
  }
}

template < class T >
bool FIFOQueueClass< T > :: dequeue(T &outItem){
  if(head == 0){
    return false;
  }else{
    outItem = tail -> getValue();
    LinkedNodeClass< T >* tempPtr = tail;
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

template < class T >
void FIFOQueueClass< T > :: print() const{
  LinkedNodeClass< T >* tempPtr = head;
  while(tempPtr != 0){
    cout << tempPtr -> getValue() << " ";
    tempPtr = tempPtr -> getNext();
  }
  cout << endl;
}

template < class T >
int FIFOQueueClass< T > :: getNumElems() const{
  int elemsCount = 0;
  LinkedNodeClass< T >* tempPtr = head;
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

template < class T >
void FIFOQueueClass< T > :: clear(){
  if(head != 0){
    LinkedNodeClass< T >* tempPtr = head;
    LinkedNodeClass< T >* toDeletePtr = head;
    while(tempPtr != 0){
      tempPtr = tempPtr -> getNext();
      delete toDeletePtr;
      toDeletePtr = tempPtr;
    }
  }
  head = 0;
  tail = 0;
}