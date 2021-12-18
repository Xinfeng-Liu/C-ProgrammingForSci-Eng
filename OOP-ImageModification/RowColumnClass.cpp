#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

RowColumnClass :: RowColumnClass(){
  inRow = ROW_COL_DEFAULT;
  inCol = ROW_COL_DEFAULT;
}

RowColumnClass :: RowColumnClass(int inputRow, int inputCol){
  inRow = inputRow;
  inCol = inputCol;
}

void RowColumnClass :: setRowCol(int inputRow, int inputCol){
  inRow = inputRow;
  inCol = inputCol;
}

void RowColumnClass :: setRow(int inputRow){
  inRow = inputRow;
}

void RowColumnClass :: setCol(int inputCol){
  inCol = inputCol;
}

int RowColumnClass :: getRow(){
  return inRow;
}

int RowColumnClass :: getCol(){
  return inCol;
}