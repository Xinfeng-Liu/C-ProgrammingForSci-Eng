#include <iostream>
#include <string>
#include "colorOptions.h"
#include "constants.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

void colorOptions(string type){
  bool validInputFound_color = false;
  cout << COLOR_RED << ". Red" << endl;
  cout << COLOR_GREEN << ". Green" << endl;
  cout << COLOR_BLUE << ". Blue" << endl;
  cout << COLOR_BLACK << ". Black" << endl;
  cout << COLOR_WHITE << ". White" << endl;
  if(type == "rectangle"){
    cout << "Enter int for rectangle color: ";
  }
  if(type == "transparecy"){
    cout << "Enter int for transparecy color: ";
  }
  if(type == "pattern"){
    cout << "Enter int for pattern color: ";
  }
}