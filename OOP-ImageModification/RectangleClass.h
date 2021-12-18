#ifndef _RECTANGLE_CLASS_H_
#define _RECTANGLE_CLASS_H_
#include <string>

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

//setup rectangle positon and color based on customer's choice
class RectangleClass{
  private:
    RowColumnClass startPosition;
    RowColumnClass endPosition;
    ColorClass rectangleColor;
  public:
    //ctor: set rectangle sart and end position 
    RectangleClass(int rowStart, int colStart, int rowEnd, int colEnd);
    //set rectangle color
    void setRectangleColor(int colorChoice);
    //get rectangle color
    ColorClass getColor();
    //get retangle start postion
    RowColumnClass getStartPosition();
    //get rectangle end position
    RowColumnClass getEndPosition(); 
};

#endif