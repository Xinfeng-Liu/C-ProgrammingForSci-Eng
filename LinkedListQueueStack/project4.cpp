#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: 11/09/2021 - 11/18/2021
//Purpose: Develop functionalities of sorted linked list, queue, and stack.

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main(){
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.
  cout << "-------------Test Sorted List Functionality-------------" << endl;
  SortedListClass testList;
  // print empty list
  testList.printForward();
  testList.printBackward();
  // insert values and print forward & backward
  testList.insertValue(8);
  testList.insertValue(30);
  testList.insertValue(24);
  testList.insertValue(50);
  testList.insertValue(50);
  testList.insertValue(4);
  testList.insertValue(12);
  cout << "Print Forward: " << endl;
  testList.printForward();
  cout << "Print Backward: " << endl;
  testList.printBackward();
  cout << "----get ele at index----" << endl;
  int outputVal = -9999;
  int index1 = -2;
  int index2 = 0;
  int index3 = 3;
  int index4 = 7;
  cout << "If successful: ";
  cout << testList.getElemAtIndex(index1, outputVal) << endl;
  cout << "Value at index " << index1 << " is: ";
  cout << outputVal << endl;
  
  cout << "If successful: ";
  cout << testList.getElemAtIndex(index2, outputVal) << endl;
  cout << "Value at index " << index2 << " is: ";
  cout << outputVal << endl;
  
  cout << "If successful: ";
  cout << testList.getElemAtIndex(index3, outputVal) << endl;
  cout << "Value at index " << index3 << " is: ";
  cout << outputVal << endl;

  cout << "If successful: ";
  cout << testList.getElemAtIndex(index4, outputVal) << endl;
  cout << "Value at index " << index4 << " is: ";
  cout << outputVal << endl;
  
  // remove some values and print them out
  int val1, val2;
  cout << "----Remove from the front----" << endl;
  //remove first(smallest)
  testList.removeFront(val1);
  cout << "Remove val is: " << val1 << endl;
  cout << "Now List has " << testList.getNumElems() << " elements" << endl;
  cout << "Now the list has: " << endl;
  testList.printForward();
  //remove second(second smallest)
  testList.removeFront(val1);
  cout << "Remove val is: " << val1 << endl;
  cout << "Now List has " << testList.getNumElems() << " elements" << endl;
  cout << "Now the list has: " << endl;
  testList.printForward();
  cout << "----Remove from the last----" << endl;
  //remove last(biggest)
  testList.removeLast(val2);
  cout << "Remove val is: " << val2 << endl;
  cout << "Now List has " << testList.getNumElems() << " elements" << endl;
  cout << "Now the list has: " << endl;
  testList.printForward();
  cout << "Now remove all" << endl;
  testList.removeLast(val2);
  testList.removeLast(val2);
  testList.removeLast(val2);
  testList.removeLast(val2);
  cout << "Now List has " << testList.getNumElems() << " elements" << endl;
  cout << "Now the list has: " << endl;
  testList.printForward();
  // print after clear
  cout << "----Test Clear----" << endl;
  testList.insertValue(1);
  testList.insertValue(3);
  testList.insertValue(5);
  testList.clear();
  testList.printForward();
  testList.printBackward();
  // add some value after clear them
  cout << "----Insert After Clear----" << endl;
  testList.insertValue(-1);
  testList.insertValue(12);
  testList.insertValue(6);
  testList.insertValue(0);
  testList.printForward();
  testList.printBackward();
  cout << "----Test testCopy----" << endl;
  // copy list
  SortedListClass testCopy(testList);
  cout << "Copied list has: " << endl;
  testCopy.printForward();
  cout << "test copy has " << testCopy.getNumElems() << " elements" << endl;
  // print the original list
  cout << "original list has: " << endl;  
  testList.printForward();
  testList.printBackward();
  cout << "insert a value in the copy list" << endl;
  testCopy.insertValue(6);
  cout << "Now copied list has: " << endl;
  testCopy.printForward();
  testCopy.printBackward();

  //test FIFOQueueClass
  cout << "-----------Test FIFOQueueClass Functionality-----------" << endl;
  FIFOQueueClass testQueue;
  testQueue.enqueue(12);
  testQueue.enqueue(2);
  testQueue.enqueue(7);
  cout << "Now List has " << testQueue.getNumElems() << " elements" << endl;
  cout << "Current list has: ";
  testQueue.print();
  
  int outValue;
  cout << "if poped successfully: " << testQueue.dequeue(outValue) << endl;
  cout << "dequeued value: " << outValue << endl;
  cout << "Current list has: ";
  testQueue.print();
  
  cout << "if poped successfully: " << testQueue.dequeue(outValue) << endl;
  cout << "dequeued value: " << outValue << endl;
  cout << "Current list has: ";
  testQueue.print();
  
  cout << "if poped successfully: " << testQueue.dequeue(outValue) << endl;
  cout << "dequeued value: " << outValue << endl;
  cout << "Current list has: ";
  testQueue.print();
  testQueue.clear();
  cout << "Current list has: ";
  testQueue.print();

  //test LIFOStackClass
  cout << "-----------Test LIFOStackClass Functionality-----------" << endl;
  LIFOStackClass testStack;
  testStack.push(12);
  testStack.push(2);
  testStack.push(7);
  cout << "Now List has " << testStack.getNumElems() << " elements" << endl;
  cout << "Current list has: ";
  testStack.print();

  int outVal1;
  cout << "if poped successfully: " << testStack.pop(outVal1) << endl;
  cout << "poped element is: " << outVal1 << endl;
  cout << "Now List has " << testStack.getNumElems() << " elements" << endl;
  cout << "Current list has: ";
  testStack.print();
  
  cout << "if poped successfully: " << testStack.pop(outVal1) << endl;
  cout << "poped element is: " << outVal1 << endl;
  cout << "Now List has " << testStack.getNumElems() << " elements" << endl;
  cout << "Current list has: ";
  testStack.print();

  cout << "if poped successfully: " << testStack.pop(outVal1) << endl;
  cout << "poped element is: " << outVal1 << endl;
  cout << "Now List has " << testStack.getNumElems() << " elements" << endl;
  cout << "Current list has: ";
  testStack.print();

  cout << "if poped successfully: " << testStack.pop(outVal1) << endl;
  testStack.clear();

  return 0;
}

#endif