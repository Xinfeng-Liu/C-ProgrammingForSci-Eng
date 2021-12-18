#include <iostream>
#include "printMainMenue.h"
#include "constants.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

int printMainMenue(){
  bool isInputValid = false;
  int choice;
  cout << ANNO_RECTANGLE << ". Annotate image with rectangle" << endl;
  cout << ANNO_PATTERN << ". Annotate image with pattern from file" << endl;
  cout << INSERT_PPM << ". Insert another image" << endl;
  cout << WRITE_IMAGE << ". Write out current image" << endl;
  cout << EXIST_PROGM << ". Exit the program" << endl;
  cout << "Enter int for main menu choice: ";
  while(!isInputValid){
    cin >> choice;
    if(cin.fail() || (choice > MAIN_CHOICE_MAX) || (choice < CHOICE_MIN)){
      cin.clear();
      cin.ignore(FILE_IGNORE, '\n');
      cout << "Please enter valid choice number from 1-5!" << endl;
      cout << "Re-enter a valid option here: ";
    }else{
      isInputValid = true;
    }
  }
  return choice;
}