#include <iostream>
#include <fstream>
#include "LinkedNodeClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: 11/09/2021 - 11/18/2021
//Purpose: Develop functionalities of sorted linked list, queue, and stack.

LinkedNodeClass :: LinkedNodeClass(LinkedNodeClass *inPrev,
                                   const int &inVal,
                                   LinkedNodeClass *inNext){
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
}

int LinkedNodeClass :: getValue() const{
  return nodeVal;
}

LinkedNodeClass* LinkedNodeClass :: getNext() const{
  return nextNode;
}

LinkedNodeClass* LinkedNodeClass :: getPrev() const{
  return prevNode;
}

void LinkedNodeClass :: setNextPointerToNull(){
  nextNode = NULL;
}

void LinkedNodeClass :: setPreviousPointerToNull(){
  prevNode = NULL;
}

void LinkedNodeClass :: setBeforeAndAfterPointers(){
  if(prevNode != NULL){
    prevNode -> nextNode = this;
  }
  if(nextNode != NULL){
    nextNode -> prevNode = this;
  }
}