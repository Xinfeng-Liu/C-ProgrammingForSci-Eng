#include <iostream>
#include <string>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

RectangleClass :: RectangleClass(int rowStart, 
                                 int colStart, 
                                 int rowEnd, 
                                 int colEnd){
  startPosition.setRowCol(rowStart, colStart);
  endPosition.setRowCol(rowEnd, colEnd);
}

void RectangleClass :: setRectangleColor(int colorChoice){
  if (colorChoice == COLOR_RED){
    rectangleColor.setToRed();
  }else if(colorChoice == COLOR_GREEN){
    rectangleColor.setToGreen();
  }else if(colorChoice == COLOR_BLUE){
    rectangleColor.setToBlue();
  }else if(colorChoice == COLOR_BLACK){
    rectangleColor.setToBlack();
  }else{
    rectangleColor.setToWhite();
  }
}

ColorClass RectangleClass :: getColor(){
  return rectangleColor;
}

RowColumnClass RectangleClass :: getStartPosition(){
  return startPosition;
}

RowColumnClass RectangleClass :: getEndPosition(){
  return endPosition;
}