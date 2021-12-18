#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_
#include <string>

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

//resubmit update: deleted patternIndex related method
//set up rgb color and read each pixel rgb from ppm
class ColorClass{
  private:
    int inRed;
    int inGreen;
    int inBlue;
    // int patternIndex;
    //retrun true if RGB > 0 and RGB < 255
    //return false otherwise
    bool isInDefinedRange(int val); 
    //return true if RGB > 0 and RGB < maximum value in PPM file
    //return false otherwise
    bool isInFileRange(int val, int bound);
    //if RGB valid go over the range, set it to definde min or max value
    int clippToVaild(int val);
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
    //setTo will set the pixel equals to the inputed colorclass object value 
    void setTo(ColorClass inColor);
    //set the pixel to inputed value of red, green, blue
    //return true if the set up value out of range
    //return false otherwise
    bool setTo(int inputRed, int inputGreen, int inputBlue);
    //add RGB value from the rhs colorcalss
    //return true if rgb value out of range
    //return false otherwise
    bool addColor(ColorClass &rhs);
    //adjust brightness of rgb value
    //return true if rgb valueout of range
    //return false otherwise
    bool adjustBrightness(double adjFactor); 
    //read each pixel rgb value from ppm file
    //return true if input file is valid or 
    //rgb value within PPM maximum color value
    //return false otherwise
    bool readPixelFromFile(ifstream &inFile, int colorBound);
    //write out each pixel rgb color
    bool writePixelToFile(ofstream &outFile);
    //compare two color class rgb value
    //return true rgb values are the same
    //return false otherwise
    bool isColorSame(ColorClass colorCompare);
    //return red value
    int getRed();
    //return green value
    int getGreen(); 
    //return blue value
    int getBlue();
};

#endif