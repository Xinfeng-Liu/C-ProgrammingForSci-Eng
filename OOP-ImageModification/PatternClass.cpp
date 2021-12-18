#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

PatternClass :: PatternClass(){
  isFileValid = true;
  oneDPtr = 0;
}

PatternClass :: ~PatternClass(){
  delete [] oneDPtr;
  oneDPtr = 0; 
}

void PatternClass :: setPatternColor(int colorChoice){
  if (colorChoice == COLOR_RED){
    patternColor.setToRed();
  }else if(colorChoice == COLOR_GREEN){
    patternColor.setToGreen();
  }else if(colorChoice == COLOR_BLUE){
    patternColor.setToBlue();
  }else if(colorChoice == COLOR_BLACK){
    patternColor.setToBlack();
  }else if(colorChoice == COLOR_WHITE){
    patternColor.setToWhite();
  }
}

bool PatternClass :: readRowCol(ifstream &inFile, 
                                bool &isFileValid, 
                                int &patternRow, 
                                int &patternCol){
  isFileValid = false;
  while(!isFileValid){
    if(inFile.eof()){
      cout << "EOF before reading pattern file width and height!" << endl;
      return isFileValid;
    }else if(inFile.fail()){
      inFile.clear();
      inFile.ignore(FILE_IGNORE, '\n');
      cout << "Can't open pattern file!" << endl;
      return isFileValid;
    }else{
      isFileValid = true;
    }
  }
  inFile >> patternCol;
  inFile >> patternRow;
  if(patternRow < MIN_ROW_COL || patternCol < MIN_ROW_COL){
    cout << "The value of row and columns should be positive!" << endl;
    isFileValid = false;
  }
  return isFileValid;
}

//resubmit updated readBinaryInd
bool PatternClass :: readBinaryInd(ifstream &inFile,
                                   bool &isFileValid,
                                   const int &patternRow,
                                   const int &PatternCol){
  isFileValid = false;
  oneDPtr = new PatternClass[patternCol * patternRow];
  int oneDIndex;
  string isOtherInfo; 
  int currentValue;
  int elements = PIXEL_NUMBER;
  for(int i = 0; i < patternRow; i++){
    for(int j = 0; j < patternCol; j++){
      oneDIndex = i * patternCol + j;
      inFile >> currentValue;
      if(inFile.fail()){
        isFileValid = false;
        cout << "Pattern size does not match with provided size!";
        cout << "Please check and resubmit the pattern file!" << endl;
        //updated error handling
        return isFileValid;
      }else if((currentValue != PATTERN_MIN) && (currentValue != PATTERN_MAX)){
        isFileValid = false;
        cout << "Pattern element can only be ";
        cout << PATTERN_MIN << "or" << PATTERN_MAX;
        cout << "Detected other value!";
        cout << "Please check and resubmit the pattern file!" << endl;
        //updated error handling
        return isFileValid;
      }else{
        isFileValid = true;
        oneDPtr[oneDIndex].setIndicatorIndex(currentValue);
      }
    }
  }
  inFile >> isOtherInfo;
  if(!inFile.fail()){
    isFileValid = false;
    //updated error message
    cout << "Row and colum provided by the pattern file is incorrect!";
    cout << "Please check and resubmit the pattern file!" << endl;
  }
  return isFileValid;
}

bool PatternClass :: readPattern(string fileName){
  ifstream inFile;
  inFile.open(fileName.c_str());
  if(inFile.fail()){
    isFileValid = false;
    cout << "File does not exist!" << endl;
    return false;
  }
  if(!readRowCol(inFile, isFileValid, patternRow, patternCol)){
    return isFileValid;
  }
  if(!readBinaryInd(inFile, isFileValid, patternRow, patternCol)){
    return isFileValid;
  }
  inFile.close();
  return isFileValid;
}

//transfered setIndicatorIndex from ColorClass to PatternClass
void PatternClass :: setIndicatorIndex(int index){
  patternIndex = index;
}

//transfered getpatternIndex from ColorClass to PatternClass
int PatternClass :: getpatternIndex(){
  return patternIndex;
}

ColorClass PatternClass :: getPatternColor(){
  return patternColor;
}

int PatternClass :: getPatternCol(){
  return patternCol;
}

int PatternClass :: getPatternRow(){
  return patternRow;
}

PatternClass* PatternClass :: getpointer(){
  return oneDPtr;
}
