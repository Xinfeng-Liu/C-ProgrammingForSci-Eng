#include <iostream>
#include <fstream>
#include "constants.h"
#include "ColorClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

bool ColorClass :: isInDefinedRange(int val){
  if((val >= COLOR_MIN) && (val <= COLOR_MAX)){
    return true;
  }
  return false;
}

bool ColorClass :: isInFileRange(int val, int bound){
  if((val < COLOR_MIN) || (val > bound)){
    return false;
  }
  return true;
}

int ColorClass :: clippToVaild(int val){
  int result;
  if(isInDefinedRange(val)){
    result = val;
  }else if(val > COLOR_MAX){
    result = COLOR_MAX;
  }else{
    result = COLOR_MIN;
  }
  return result;
}

ColorClass :: ColorClass(){
  setTo(COLOR_MAX, COLOR_MAX, COLOR_MAX);
}

ColorClass :: ColorClass(int inputRed, int inputGreen, int inputBlue){
  setTo(inputRed, inputGreen, inputBlue);
}

void ColorClass :: setToBlack(){
  setTo(COLOR_MIN, COLOR_MIN, COLOR_MIN);
}

void ColorClass :: setToRed(){
  setTo(COLOR_MAX, COLOR_MIN, COLOR_MIN);
}

void ColorClass :: setToGreen(){
  setTo(COLOR_MIN, COLOR_MAX, COLOR_MIN);
}

void ColorClass :: setToBlue(){
  setTo(COLOR_MIN, COLOR_MIN, COLOR_MAX);
}

void ColorClass :: setToWhite(){
  setTo(COLOR_MAX, COLOR_MAX, COLOR_MAX);
}

void ColorClass :: setTo(ColorClass inColor){
  inRed = inColor.inRed;
  inGreen = inColor.inGreen;
  inBlue = inColor.inBlue;
}

bool ColorClass :: setTo(int inputRed, int inputGreen, int inputBlue){
  inRed = clippToVaild(inputRed);
  inGreen = clippToVaild(inputGreen);
  inBlue = clippToVaild(inputBlue);
  if(isInDefinedRange(inputRed) && 
     isInDefinedRange(inGreen) && 
     isInDefinedRange(inBlue)){
    return false;
  }
  return true;
}

bool ColorClass :: addColor(ColorClass &rhs){
  return setTo(int(inRed + rhs.inRed), 
               int(inGreen + rhs.inGreen), 
               int(inBlue + rhs.inBlue));
}

bool ColorClass :: adjustBrightness(double adjFactor){
  return setTo(int(adjFactor * inRed),
               int(adjFactor * inGreen),
               int(adjFactor * inBlue));
}

bool ColorClass :: readPixelFromFile(ifstream &inFile, int colorBound){
  inFile >> inRed >> inGreen >> inBlue;
  if(inFile.fail()){
    return false;
  }
  if(!isInFileRange(inRed, colorBound)){
    return false;
  }
  if(!isInFileRange(inGreen, colorBound)){
    return false;
  }
  if(!isInFileRange(inBlue, colorBound)){
    return false;
  }
  return true;
}

bool ColorClass :: writePixelToFile(ofstream &outFile){
  outFile << inRed << " " << inGreen << " " << inBlue << " ";
  return true;
}

bool ColorClass :: isColorSame(ColorClass colorCompare){
  if(inRed != colorCompare.inRed){
    return false;
  }else if(inGreen != colorCompare.inGreen){
    return false;
  }else if(inBlue != colorCompare.inBlue){
    return false;
  }
  return true;
}

int ColorClass :: getRed(){
  return inRed;
}
int ColorClass :: getGreen(){
  return inGreen;
}
int ColorClass :: getBlue(){
  return inBlue;
}
