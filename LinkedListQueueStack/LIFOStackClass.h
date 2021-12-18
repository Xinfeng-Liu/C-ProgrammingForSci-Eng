#ifndef _LIFOSTACKCLASS_H_
#define _LIFOSTACKCLASS_H_

#include "LinkedNodeClass.h"

//Operations on Last In First Out linked list data structure
class LIFOStackClass {
  private:
    LinkedNodeClass *head;
    LinkedNodeClass *tail;
  public:
    //Default Constructor.  Will properly initialize a stack to 
    //be an empty stack, to which values can be added. 
    LIFOStackClass();
    //Destructor.  Responsible for making sure any dynamic memory 
    //associated with an object is freed up when the object is 
    //being destroyed. 
    ~LIFOStackClass();
    //Inserts the value provided (newItem) into the stack.
    void push(const int &newItem);
    //Attempts to take the next item out of the stack.  If the 
    //stack is empty, the function returns false and the state 
    //of the reference parameter (outItem) is undefined.  If the 
    //stack is not empty, the function returns true and outItem 
    //becomes a copy of the next item in the stack, which is  
    //removed from the data structure.
    bool pop(int &outItem);
    void print() const;
    int getNumElems() const;
    void clear();
};

#endif