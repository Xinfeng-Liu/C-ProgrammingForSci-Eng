#include <iostream>
#include <string>
#include <fstream>
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

ColorImageClass :: ColorImageClass(){
  isFileValid = true;
  imageOneDPtr = 0;
}

ColorImageClass :: ~ColorImageClass(){
  delete [] imageOneDPtr;
  imageOneDPtr = 0; 
}

bool ColorImageClass :: readMagicNumber(ifstream &inFile, 
                                        bool &isFileValid, 
                                        string &magicNum){
  isFileValid = false;
  while(!isFileValid){
    if(inFile.eof()){
      cout << "EOF before reading magic number of PPM file!" << endl;
      return isFileValid;
    }else if(inFile.fail()){
      inFile.clear();
      inFile.ignore(FILE_IGNORE, '\n');
      cout << "Fail to read magic number!" << endl;
      return isFileValid;
    }else{
      isFileValid = true;
    }
  }
  inFile >> magicNum;
  if(magicNum != MAGIC_NUMBER){
    cout << "The magic number is not P3, invalid file format!" << endl;
    isFileValid = false;
  }
  return isFileValid;
}

bool ColorImageClass :: readImageRowCol(ifstream &inFile, 
                                        bool &isFileValid,
                                        int &imageRow, 
                                        int &imageCol){
  isFileValid = false;
  while(!isFileValid){
    if(inFile.eof()){
      cout << "EOF before reading PPM image width and height!" << endl;
      return isFileValid;
    }else if(inFile.fail()){
      inFile.clear();
      inFile.ignore(FILE_IGNORE, '\n');
      cout << "Can't read PPM width and height!" << endl;
      return isFileValid;
    }else{
      isFileValid = true;
    }
  }
  inFile >> imageCol;
  inFile >> imageRow;
  if(imageRow < MIN_ROW_COL || imageCol < MIN_ROW_COL){
    cout << "The value of row and columns should be positive!" << endl;
    isFileValid = false;
  }
  return isFileValid;
}

bool ColorImageClass :: readImageMaxVal(ifstream &inFile, 
                                        bool &isFileValid,
                                        int &colorMaxVal){
  isFileValid = false;
  while(!isFileValid){
    if(inFile.eof()){
      cout << "EOF before reading PPM image max color value!" << endl;
      return isFileValid;
    }else if(inFile.fail()){
      inFile.clear();
      inFile.ignore(FILE_IGNORE, '\n');
      cout << "Can't read PPM max color value!" << endl;
      return isFileValid;
    }else{
      isFileValid = true;
    }
  }
  inFile >> colorMaxVal;
  if(colorMaxVal < COLOR_MIN || colorMaxVal > COLOR_MAX){
    cout << "The range of PPM image color value exceeds the valid range.";
    cout << "It should between 0 and 255!" << endl;
    isFileValid = false;
  }
  return isFileValid;
}

bool ColorImageClass :: readPixelRGB(ifstream &inFile, 
                                     bool &isFileValid,
                                     const int imageRow, 
                                     const int imageCol){
  isFileValid = false;
  imageOneDPtr = new ColorClass[imageCol * imageRow];
  int oneDIndex;
  string isOtherInfo; 
  int elements = PIXEL_NUMBER;
  for(int i = 0; i < imageRow; i++){
    for(int j = 0; j < imageCol; j++){
      oneDIndex = findOneDIndex(i, imageCol, j);
      //resbumit updated
      //updated error check
      if(!imageOneDPtr[oneDIndex].readPixelFromFile(inFile, colorMaxVal)){
        if(!inFile.eof()){
          cout << "RBG value exceed the maximum provided by PPM image ";
          cout << "in Row: " << i << ", Col: " << j << endl;
          return isFileValid;
        }
      }else{
        elements += PIXEL_MOVE_STEP;
      }
    }
  }
  //resubmit updated
  //added error handling 
  if(elements < imageRow * imageCol){
    isFileValid = false;
    cout << "Number of reading pixel is less than row column given pixel!" << endl;
    return isFileValid;
  }
  isFileValid = true;
  inFile >> isOtherInfo;
  if(!inFile.fail()){
    //update error message
    cout << "Row and colum provided by the PPM file is incorrect!" << endl;
    isFileValid = false;
  }
  return isFileValid;
}

bool ColorImageClass :: readFile(string fileName){
  ifstream inFile;
  inFile.open(fileName.c_str());
  if(inFile.fail()){
    isFileValid = false;
    cout << "File does not exist!" << endl;
    return false;
  }
  if(!readMagicNumber(inFile, isFileValid, magicNum)){
    return isFileValid;
  }
  if(!readImageRowCol(inFile, isFileValid, imageRow, imageCol)){
    return isFileValid;
  }
  if(!readImageMaxVal(inFile, isFileValid, colorMaxVal)){
    return isFileValid;
  }
  if(!readPixelRGB(inFile, isFileValid, imageRow, imageCol)){
    return isFileValid;
  }
  inFile.close();
  return isFileValid;
}

bool ColorImageClass :: isIndexInRange(int RowIndex, int ColIndex){
  if((RowIndex >= 0) && (RowIndex < imageRow)){
    if((ColIndex >= 0) && (ColIndex < imageCol)){
      return true;
    }
  }
  return false;
}

bool ColorImageClass :: writeFile(string &fileName){
  ofstream outFile;
  int oneDIndex;
  outFile.open(fileName.c_str());
  if(outFile.fail()){
    cout << "Fail to write the file!" << endl;
  }else{
    outFile << magicNum << endl;
    outFile << imageCol << " " << imageRow << endl;
    outFile << colorMaxVal << endl;
    for(int i = 0; i < imageRow; i++){
      for(int j = 0; j < imageCol; j++){
        oneDIndex = findOneDIndex(i, imageCol, j);
        imageOneDPtr[oneDIndex].writePixelToFile(outFile);
      }
      outFile << endl;
    }
  }
  outFile.close();
  return true;
}

void ColorImageClass :: setTransparency(int colorChoice){
  if(colorChoice == COLOR_RED){
    transparency.setToRed();
  }else if(colorChoice == COLOR_GREEN){
    transparency.setToGreen();
  }else if(colorChoice == COLOR_BLUE){
    transparency.setToBlue();
  }else if(colorChoice == COLOR_BLACK){
    transparency.setToBlack();
  }else if(colorChoice == COLOR_WHITE){
    transparency.setToWhite();
  }
}

int ColorImageClass :: findOneDIndex(int rowInd, int colNum, int colInd){
  return rowInd * colNum + colInd;
}

void ColorImageClass :: addRectangle(RectangleClass &rec, bool isFilled){
  int oneDIndex;
  int startRow;
  int startCol;
  int endRow;
  int endCol;
  startRow = rec.getStartPosition().getRow();
  endRow = rec.getEndPosition().getRow();
  startCol = rec.getStartPosition().getCol();
  endCol = rec.getEndPosition().getCol();
  if(isFilled == true){
    for(int i = (startRow - 1); i < endRow; i++){
      for(int j = (startCol - 1); j < endCol; j++){
        oneDIndex = findOneDIndex(i, imageCol, j);
        if(isIndexInRange(i, j)){
          imageOneDPtr[oneDIndex].setTo(rec.getColor());
        }
      }
    }
  }
  if(isFilled == false){
    for(int j = (startCol - 1); j < endCol; j++){
      oneDIndex = findOneDIndex((startRow - 1), imageCol, j);
      if(isIndexInRange(startRow - 1, j)){
        imageOneDPtr[oneDIndex].setTo(rec.getColor());
      }
      oneDIndex = (endRow - 1) * imageCol + j;
      if(isIndexInRange(endRow - 1, j)){
        imageOneDPtr[oneDIndex].setTo(rec.getColor());
      }
    }
    for(int i = (startRow - 1); i < endRow; i++){
      oneDIndex = findOneDIndex(i, imageCol, (startCol - 1));
      if(isIndexInRange(i, startCol - 1)){
        imageOneDPtr[oneDIndex].setTo(rec.getColor());
      }
      oneDIndex = findOneDIndex(i, imageCol,(endCol - 1));
      if(isIndexInRange(i, endCol - 1)){
        imageOneDPtr[oneDIndex].setTo(rec.getColor());
      }
    }
  }
}

void ColorImageClass :: addPattern(PatternClass &pat, 
                                   int pRowStart, 
                                   int pColStart){
  int patOneDIndex;
  int imageOneDIndex;
  for(int i = 0; i < pat.getPatternRow(); i++){
    for(int j = 0; j < pat.getPatternCol(); j++){
      patOneDIndex = findOneDIndex(i, pat.getPatternCol(), j);
      if((pat.getpointer() + patOneDIndex) -> getpatternIndex() == 1){
        imageOneDIndex = findOneDIndex((pRowStart + i - 1), 
                                       (imageCol), 
                                       (pColStart + j - 1));
        if(isIndexInRange(pRowStart + i - 1, pColStart + j - 1)){
          imageOneDPtr[imageOneDIndex].setTo(pat.getPatternColor());
        }
      }
    }
  }
}

void ColorImageClass :: addImage(ColorImageClass &insertImg,
                                 int rowStart, 
                                 int colStart){
  int addedOneDIndex;
  int currentOneDIndex;
  for(int i = 0; i < insertImg.imageRow; i++){
    for(int j = 0; j < insertImg.imageCol; j++){
      addedOneDIndex = findOneDIndex(i, insertImg.imageCol, j);
      if(!(insertImg.getPtr() + addedOneDIndex) -> 
         isColorSame(insertImg.transparency)){
        currentOneDIndex = findOneDIndex((rowStart + i - 1),
                                         (imageCol),
                                         (colStart + j - 1));
        if(isIndexInRange(rowStart + i - 1, colStart + j - 1)){
          imageOneDPtr[currentOneDIndex].setTo(*(insertImg.getPtr() + 
                                                 addedOneDIndex));
        }
      }
    }
  }
}

int ColorImageClass :: getWidth(){
  return imageCol;
}

int ColorImageClass :: getHeight(){
  return imageRow;
}

int ColorImageClass :: getColorMax(){
  return colorMaxVal;
}

string ColorImageClass :: getMagicNum(){
  return magicNum;
}

ColorClass* ColorImageClass :: getPtr(){
  return imageOneDPtr;
}