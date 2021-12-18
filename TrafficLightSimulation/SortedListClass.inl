#include <iostream>
#include <fstream>
#include "SortedListClass.h"
#include "LinkedNodeClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: November 30 2020
//Purpose: Develop functionalities of sorted linked list, queue, and stack.
template < class T >
SortedListClass< T > :: SortedListClass(){
  head = 0;
  tail = 0;
}

template < class T >
SortedListClass< T > :: SortedListClass(const SortedListClass< T > &rhs){
  head = 0;
  tail = 0;
  for(int numNode = 0; numNode < rhs.getNumElems(); numNode ++){
    int currentNodeVal;
    if(rhs.getElemAtIndex(numNode, currentNodeVal)){
      insertValue(currentNodeVal);
    }
  }
}

template < class T >
SortedListClass< T > :: ~SortedListClass(){
  clear();
}

template < class T >
void SortedListClass< T > :: clear(){
  LinkedNodeClass< T >* tempPtr = head;
  LinkedNodeClass< T >* toDeletePtr = head;
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

template < class T >
void SortedListClass< T > :: insertValue(const T &valToInsert){
  if(head == 0){
    LinkedNodeClass< T >* newPtr = new LinkedNodeClass< T >(0, valToInsert, 0);
    head = newPtr;
    tail = newPtr;
  }else{
    LinkedNodeClass< T >* tempPtr = head;
    T currentNodeVal;
    currentNodeVal = head -> getValue();
    while((currentNodeVal <= valToInsert) && (tempPtr != 0)){
      if(tempPtr -> getNext() != 0){
        tempPtr = tempPtr -> getNext();
        currentNodeVal = tempPtr -> getValue();
      }else{
        tempPtr = 0;
      }
    }
    //insterted value smaller than the first value in the list
    if(tempPtr == head){
      LinkedNodeClass< T >* newPtr = new LinkedNodeClass< T >(0, 
                                                              valToInsert,
                                                              head);
      newPtr -> setBeforeAndAfterPointers();
      head = newPtr;
    //insterted value bigger than the last value in the list
    }else if(tempPtr == 0){
      LinkedNodeClass< T >* newPtr = new LinkedNodeClass< T >(tail, 
                                                              valToInsert, 
                                                              0);
      newPtr -> setBeforeAndAfterPointers();
      tail = newPtr;
    }else{
      LinkedNodeClass< T >* newPtr = 
      new LinkedNodeClass< T >(tempPtr -> getPrev(), valToInsert, tempPtr);
      newPtr -> setBeforeAndAfterPointers();
    }
  }
}

template < class T >
void SortedListClass< T > :: printForward() const{
  LinkedNodeClass< T >* tempPtr = head;
  cout << "Forward List Contents Follow:" << endl;
  while(tempPtr != 0){
    cout << "  " << tempPtr -> getValue() << endl;
    tempPtr = tempPtr -> getNext();
  }
  cout << "End Of List Contents" << endl;
}

template < class T >
void SortedListClass< T > :: printBackward() const{
  LinkedNodeClass< T >* tempPtr = tail;
  cout << "Backward List Contents Follow:" << endl;
  while(tempPtr != 0){
    cout << "  " << tempPtr -> getValue() << endl;
    tempPtr = tempPtr ->getPrev();
  }
  cout << "End Of List Contents" << endl;
}

template < class T >
bool SortedListClass< T > :: removeFront(T &theVal){
  if(head == 0){
    return false;
  }else{
    theVal = head -> getValue();
    LinkedNodeClass< T >* tempPtr = head;
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

template < class T >
bool SortedListClass< T > :: removeLast(T &theVal){
  if(tail == 0){
    return false;
  }else{
    theVal = tail -> getValue();
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
int SortedListClass< T > :: getNumElems() const{
  int elemsCount = 0;
  if(head == 0 && tail == 0){
    return elemsCount;
  }else{
    LinkedNodeClass< T >* tempPtr = head;
    while(tempPtr != 0){
      elemsCount ++;
      tempPtr = tempPtr -> getNext();
    }
    return elemsCount;
  }
}

template < class T >
bool SortedListClass< T > :: getElemAtIndex(const int index, T &outVal) const{
  if(index >= getNumElems()){
    return false;
  }else if(index < 0){
    return false;
  }else{
    int currentIndex = 0;
    LinkedNodeClass< T >* tempPtr = head;
    while(currentIndex < index){
      tempPtr = tempPtr -> getNext();
      currentIndex ++;
    }
    outVal = tempPtr -> getValue();
    return true;
  }
}