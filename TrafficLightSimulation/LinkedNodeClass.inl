#include <iostream>
#include <fstream>
#include "LinkedNodeClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: November 30 2020
//Purpose: Develop functionalities of sorted linked list, queue, and stack.
template < class T >
LinkedNodeClass< T > :: LinkedNodeClass(LinkedNodeClass< T > *inPrev,
                                        const T &inVal,
                                        LinkedNodeClass< T > *inNext){
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
}

template < class T >
T LinkedNodeClass< T > :: getValue() const{
  return nodeVal;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T > :: getNext() const{
  return nextNode;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T > :: getPrev() const{
  return prevNode;
}

template < class T >
void LinkedNodeClass< T > :: setNextPointerToNull(){
  nextNode = NULL;
}

template < class T >
void LinkedNodeClass< T > :: setPreviousPointerToNull(){
  prevNode = NULL;
}

template < class T >
void LinkedNodeClass< T > :: setBeforeAndAfterPointers(){
  if(prevNode != NULL){
    prevNode -> nextNode = this;
  }
  if(nextNode != NULL){
    nextNode -> prevNode = this;
  }
}