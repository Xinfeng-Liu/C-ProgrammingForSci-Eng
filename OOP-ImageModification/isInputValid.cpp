#include <iostream>
#include "isInputValid.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

bool isInputValid(int inputValue, int lower, int upper){
  if(inputValue > upper){
    return false;
  }
  if(inputValue < lower){
    return false;
  }
  return true;
}