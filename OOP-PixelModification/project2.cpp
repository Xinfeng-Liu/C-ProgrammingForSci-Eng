#include <iostream>
#include <string>
using namespace std;

// Name: Xinfeng Liu; UMID: 16393614
// Project Period: 09/28/2021 - 10/12/2021
// Project Purpose: This project write a project contains three classes
// to deal with pixel and pixel color

//changed global variables to global constants
const int MIN_COLOR = 0; 
const int MAX_COLOR = 1000; 
const int ROW_COL_DEFAULT = -9999; 
const int ROW_MAX = 10;
const int COL_MAX = 18;
const int ROW_COL_MIN = 0;

//ColorClass dertermins the value of color red, color green,
//and color blue in a pixel.
class ColorClass{
  private:
    int inRed;
    int inGreen;
    int inBlue;
    //minChecker will check the minimum value of a target color,
    //if smaller than minimum, will set to minimum value and change the
    //clipping flag in clippingFunction to 1
    void minChecker(int& color, bool& clipping); //added new helper function
    //maxChecker will check the maximum value of a target color,
    //if greater than maximum, will set to maximum value and change the
    //clipping flag in clippingFunction to 1
    void maxChecker(int& color, bool& clipping); //added new helper function
    //check the ranges of input rgb colors and set values accrodingly
    //return 1 if max or min threshold is exceeded
    bool clippingFunction(int& inRed, int& inGreen, int& inBlue); 
  public:
    //ColorClass ctor will set the pixel to white by default
    ColorClass();
    //ColotClass ctor will set the pixel to input color
    ColorClass(int inputRed, int inputGreen, int inputBlue);
    //setToBlack will set the pixel to balck
    void setToBlack();
    //setToRed will set the pixel to red
    void setToRed();
    //setToGreen will set the pixel to green
    void setToGreen();
    //setToBlue will set the pixel to blue
    void setToBlue();
    //setToWhite will set the pixel to white
    void setToWhite();
    //setTo will set the pixel to inputed value of red, green, blue
    bool setTo(int inputRed, int inputGreen, int inputBlue);
    //setTo will set the pixel equals to the inputed colorclass object value
    bool setTo(ColorClass &inColor);
    //addColor will add the value of input colorclass object to the current
    //colorclass object
    bool addColor(ColorClass &rhs);
    //subtractColor will substract the value of input colorclass
    //object from the current colorclass object
    bool subtractColor(ColorClass &rhs);
    //adjustBrightness will increase or decrease the value proportional
    //to the adjFactor
    bool adjustBrightness(double adjFactor);
    //printComponentValues will print the value of red, green, blue in a pixel
    void printComponentValues();
};

//RowColumnClass sets row and column values
class RowColumnClass{
  private:
    int inRow;
    int inCol;
  public:
    //RowColumnClass ctor set row and column to default value
    RowColumnClass();
    //RowColumnClass ctor sets row and column to inputed value
    RowColumnClass(int inputRow, int inputCol);
    //setRowCol sets inputed value of row and column
    void setRowCol(int inputRow, int inputCol);
    //setRow sets row to inputed row value
    void setRow(int inputRow);
    //setCol sets column to inputed column value
    void setCol(int inputCol);
    //getRow returns the current row number
    int getRow();
    //getCol returns the current column number
    int getCol();
    //addRowColTo adds the value of input object to the current
    //row and column value
    void addRowColTo(RowColumnClass& inRowCol);
    //printRowCol prints out the current row and column value
    void printRowCol();
};

//ColorImageClass determins the color of each pixel for a whole 10*18 image
class ColorImageClass{
  private:
    ColorClass pixelArray[ROW_MAX][COL_MAX];
    //changed magic numbers to defined global consants
  public: 
    //ColorImageClass ctor set each pixel to black
    ColorImageClass();
    //initializeTo set the each pixel to input ColorClass object
    void initializeTo(ColorClass &inColor);
    //addImageTo performs pixel-wise addition, add value of each pixel
    //of input object to the current object
    bool addImageTo(ColorImageClass &rhsImg);
    //addImages sets the object's each pixel to the sum of input
    //objects' pixel value
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
    //setColorAtLocation sets the color for a specific position
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);  
    //getColorAtLocation returns the color value
    //of the specific pixel position
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);   
    //printImage prints out the value of each pixel for the whole image
    void printImage();
};

#ifdef ANDREW_TEST 
#include "andrewTest.h" 
#else 

int main(){
  ColorClass testColor;
  ColorClass testColorOther;
  RowColumnClass testRowCol;
  RowColumnClass testRowColOther(111, 222);
  ColorImageClass testImage;
  ColorImageClass testImages[3];

  //Test some basic ColorClass operations...
  cout << "Initial: ";
  testColor.printComponentValues();
  cout << endl;
  testColor.setToBlack();
  cout << "Black: ";
  testColor.printComponentValues();
  cout << endl;
  testColor.setToGreen();
  cout << "Green: ";
  testColor.printComponentValues();
  cout << endl;
  testColor.adjustBrightness(0.5);
  cout << "Dimmer Green: ";
  testColor.printComponentValues();
  cout << endl;

  //Test some basic RowColumnClass operations...
  cout << "Want defaults: ";
  testRowCol.printRowCol();
  cout << endl;
  testRowCol.setRowCol(2, 8);
  cout << "Want 2, 8: ";
  testRowCol.printRowCol();
  cout << endl;
  cout << "Want 111, 222: ";
  testRowColOther.printRowCol();
  cout << endl;
  testRowColOther.setRowCol(4, 2);
  testRowCol.addRowColTo(testRowColOther);
  cout << "Want 6, 10: ";
  testRowCol.printRowCol();
  cout << endl;

  //Test some basic ColorImageClass operations...
  testColor.setToRed();
  testImage.initializeTo(testColor);

  testRowCol.setRowCol(555, 5);
  cout << "Want: Color at [555, 5]: Invalid Index!" << endl;

  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if(testImage.getColorAtLocation(testRowCol, testColor)){
    testColor.printComponentValues();
  }else{
    cout << "Invalid Index!";
  }
  cout << endl;

  testRowCol.setRow(4);
  cout << "Want: Color at [4, 5]: R: 1000 G: 0 B: 0" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if(testImage.getColorAtLocation(testRowCol, testColor)){
    testColor.printComponentValues();
  }else{
    cout << "Invalid Index!";
  }
  cout << endl;

  //Set up an array of images of different colors
  testColor.setToRed();
  testColor.adjustBrightness(0.25);
  testImages[0].initializeTo(testColor);
  testColor.setToBlue();
  testColor.adjustBrightness(0.75);
  testImages[1].initializeTo(testColor);
  testColor.setToGreen();
  testImages[2].initializeTo(testColor);

  //Modify a few individual pixel colors
  testRowCol.setRowCol(4, 2);
  testColor.setToWhite();
  testImages[1].setColorAtLocation(testRowCol, testColor);


  testRowCol.setRowCol(2, 4);
  testColor.setToBlack();
  testImages[2].setColorAtLocation(testRowCol, testColor);

  //Add up all images in testImages array and assign result
  //to the testImage image
  testImage.addImages(3, testImages);

  //Check some certain values
  cout << "Added values:" << endl;
  for(int colInd = 0; colInd < 8; colInd += 2){
    testRowCol.setRowCol(4, colInd);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if(testImage.getColorAtLocation(testRowCol, testColor)){
      testColor.printComponentValues();
    }else{
      cout << "Invalid Index!";
    }
    cout << endl;
  }

  for(int rowInd = 0; rowInd < 8; rowInd += 2){
    testRowCol.setRowCol(rowInd, 4);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if(testImage.getColorAtLocation(testRowCol, testColor)){
      testColor.printComponentValues();
    }else{
      cout << "Invalid Index!";
    }
    cout << endl;
  }

  cout << "Printing entire test image:" << endl;
  testImage.printImage();

  return 0;
}

//changed #endif position to solve compile error
#endif

//added new helper function
void ColorClass :: minChecker(int &color, bool &clipping){
  if(color < MIN_COLOR){
    color = MIN_COLOR;
    clipping = 1;
  }
}

//added new helper function
void ColorClass :: maxChecker(int &color, bool &clipping){
  if(color > MAX_COLOR){
    color = MAX_COLOR;
    clipping = 1;
  }
}

//rewrote clippingFunction using new helper functions
bool ColorClass :: clippingFunction(int &inRed, int &inGreen, int &inBlue){
  bool isClipping = 0;
  minChecker(inRed, isClipping);
  minChecker(inGreen, isClipping);
  minChecker(inBlue, isClipping);
  maxChecker(inRed, isClipping);
  maxChecker(inGreen, isClipping);
  maxChecker(inBlue, isClipping);
  return isClipping;
}

ColorClass :: ColorClass(){
  setTo(MAX_COLOR, MAX_COLOR, MAX_COLOR);
}

ColorClass :: ColorClass(int inputRed, int inputGreen, int inputBlue){
  setTo(inputRed, inputGreen, inputBlue);
}

void ColorClass :: setToBlack(){
  setTo(MIN_COLOR, MIN_COLOR, MIN_COLOR );
}

void ColorClass :: setToRed(){
  setTo(MAX_COLOR, MIN_COLOR, MIN_COLOR );
}

void ColorClass :: setToGreen(){
  setTo(MIN_COLOR, MAX_COLOR, MIN_COLOR );
}

void ColorClass :: setToBlue(){
  setTo(MIN_COLOR, MIN_COLOR, MAX_COLOR );
}

void ColorClass :: setToWhite(){
  setTo(MAX_COLOR, MAX_COLOR, MAX_COLOR );
}

bool ColorClass :: setTo(int inputRed, int inputGreen, int inputBlue){
  inRed = inputRed;
  inGreen = inputGreen;
  inBlue = inputBlue;
  return clippingFunction(inRed, inGreen, inBlue);
}

//originaly return clippingFunction, now directly returen setTo()
bool ColorClass :: setTo(ColorClass &inColor){
  return setTo(inColor.inRed, inColor.inGreen, inColor.inBlue);
}

//originaly return clippingFunction, now directly returen setTo()
bool ColorClass :: addColor(ColorClass &rhs){
  return setTo(inRed += rhs.inRed, 
               inGreen += rhs.inGreen, 
               inBlue += rhs.inBlue);
}

//originaly return clippingFunction, now directly returen setTo()
bool ColorClass :: subtractColor(ColorClass &rhs){
  return setTo(inRed -= rhs.inRed, 
               inGreen -= rhs.inGreen, 
               inBlue -= rhs.inBlue);
}

//originaly return clippingFunction, now directly returen setTo()
bool ColorClass :: adjustBrightness(double adjFactor){
  return setTo(inRed *= adjFactor, 
               inGreen *= adjFactor, 
               inBlue *= adjFactor);
}

void ColorClass :: printComponentValues(){
  cout << "R: " << inRed << " " << "G: " << inGreen << " " << "B: " << inBlue;
}

RowColumnClass :: RowColumnClass(){
  setRowCol(ROW_COL_DEFAULT, ROW_COL_DEFAULT);
}

RowColumnClass :: RowColumnClass(int inputRow, int inputCol){
  setRowCol(inputRow, inputCol);
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

void RowColumnClass :: addRowColTo(RowColumnClass &inRowCol){
  setRowCol(inRow += inRowCol.inRow, inCol += inRowCol.inCol);
}

void RowColumnClass :: printRowCol(){
  cout << '[' << inRow << ',' << inCol << ']';
}

ColorImageClass :: ColorImageClass(){
  for(int i = 0; i < ROW_MAX; i++){
    for(int j = 0; j < COL_MAX; j++){
      pixelArray[i][j].setToBlack();
    }
  }
}    

void ColorImageClass :: initializeTo(ColorClass &inColor){
  for(int i = 0; i < ROW_MAX; i++){
    for(int j = 0; j < COL_MAX; j++){
      pixelArray[i][j].setTo(inColor);
    }
  }
}

bool ColorImageClass :: addImageTo(ColorImageClass &rhsImg){
  bool ifClipping = false;
  for(int i = 0; i < ROW_MAX; i++){
    for(int j = 0; j < COL_MAX; j++){
      pixelArray[i][j].addColor(rhsImg.pixelArray[i][j]);
      if(pixelArray[i][j].addColor(rhsImg.pixelArray[i][j])){
        ifClipping = true;
      }
    }
  }
  return ifClipping;
}

bool ColorImageClass :: addImages(int numImgsToAdd, 
                                  ColorImageClass imagesToAdd[]){
  bool ifClipping = false;
  for(int i = 0; i < ROW_MAX; i++){
    for(int j = 0; j < COL_MAX; j++){
      pixelArray[i][j].setTo(imagesToAdd[0].pixelArray[i][j]);
      for(int m = 1; m < numImgsToAdd; m++){
        if(pixelArray[i][j].addColor(imagesToAdd[m].pixelArray[i][j])){
          ifClipping = true;
        }
      }
    }
  }
  return ifClipping;
}

bool ColorImageClass :: setColorAtLocation(RowColumnClass &inRowCol, 
                                           ColorClass &inColor){
  bool ifClipping = false;
  pixelArray[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
  if(pixelArray[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor)){
    ifClipping = true;
  }
  return ifClipping;
}

bool ColorImageClass :: getColorAtLocation(RowColumnClass &inRowCol, 
                                           ColorClass &outColor){
  int row = inRowCol.getRow();
  int col = inRowCol.getCol();
  //changed magic number to defined global constant
  if(row < ROW_COL_MIN || row > ROW_MAX || col < ROW_COL_MIN || col > COL_MAX){
    return false;
  }else{
    outColor.setTo(pixelArray[row][col]);
    return true;
  }
}

void ColorImageClass :: printImage(){
  for(int i = 0; i < ROW_MAX; i++){
    for(int j = 0; j < COL_MAX - 1; j++){
      pixelArray[i][j].printComponentValues();
      cout << "--";
    }
    pixelArray[i][COL_MAX - 1].printComponentValues();
    cout << endl;
  }
}
