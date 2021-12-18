#ifndef _LINKEDNODECLASS_H_
#define _LINKEDNODECLASS_H_
#include <string>

using namespace std;

//operations on creating doubly linked list
class LinkedNodeClass{
  private:
    LinkedNodeClass *prevNode;
    int nodeVal;
    LinkedNodeClass *nextNode;
  public:
    //The ONLY constructor for the linked node class - it takes in the  
    //newly created node's previous pointer, value, and next pointer,  
    //and assigns them. 
    LinkedNodeClass(LinkedNodeClass *inPrev,
                    const int &inVal,
                    LinkedNodeClass *inNext);
    //Returns the value stored within this node. 
    int getValue() const;
    //Returns the address of the node that follows this node.  
    LinkedNodeClass* getNext() const;
    //Returns the address of the node that comes before this node.  
    LinkedNodeClass* getPrev() const;
    //Sets the object’s next node pointer to NULL.
    void setNextPointerToNull();
    //Sets the object's previous node pointer to NULL. 
    void setPreviousPointerToNull();
    //This function DOES NOT modify "this" node. Instead, it uses  
    //the pointers contained within this node to change the previous  
    //and next nodes so that they point to this node appropriately.  
    //In other words, if "this" node is set up such that its prevNode  
    //pointer points to a node (call it "A"), and "this" node's  
    //nextNode pointer points to a node (call it "B"), then calling  
    //setBeforeAndAfterPointers results in the node we're calling  
    //"A" to be updated so its "nextNode" points to "this" node, and  
    //the node we're calling "B" is updated so its "prevNode" points  
    //to "this" node, but "this" node itself remains unchanged.  
    void setBeforeAndAfterPointers();
};

#endif