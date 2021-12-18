#ifndef _COLORIMAGE_CLASS_H_
#define _COLORIMAGE_CLASS_H_
#include <string>

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

//class ColorImageClass declarations: used to represent a small image
class ColorImageClass {
  private:
    string magicNum;
    int imageCol;
    int imageRow;
    int colorMaxVal;
    bool isFileValid;
    ColorClass* imageOneDPtr;
    ColorClass transparency;
  public:
    //ctor: set ifFileValid status at true, and Colorclass ptr to 0
    ColorImageClass(); 
    //dtor: delete oneD poniter
    ~ColorImageClass();
    //read ppm file magic numer
    //return true if read magic number successfully
    //return false otherwise
    bool readMagicNumber(ifstream &inFile, 
                         bool &isFileValid, 
                         string &magicNum);
    //read ppm file row and column number
    //return true if read row and col number successfully
    //return false otherwise
    bool readImageRowCol(ifstream &inFile, 
                         bool &isFileValid, 
                         int &imageRow, 
                         int &imageCol);
    //read ppm file max rgb value
    //return true if successfully read the max value
    //return false otherwise
    bool readImageMaxVal(ifstream &inFile, 
                         bool &isFileValid,
                         int &colorMaxVal);
    //read rgb value of each pixel ppm file
    //retrun true if file is valid and rgb value within range
    //return false otherwise
    bool readPixelRGB(ifstream &inFile, 
                      bool &isFileValid, 
                      const int imageRow, 
                      const int imageCol);
    //read the whole image, and do error check using previous methods
    bool readFile(string fileName);
    //write out current ppm image
    //return true if the image can be written successfully
    bool writeFile(string &fileName);
    //check if index within the ppm image range
    //return true if within range
    //return false otherwise
    bool isIndexInRange(int RowIndex, int ColIndex);
    //set image transparency color according to choice
    void setTransparency(int colorChoice);
    //find oneDindex based on 2D array
    int findOneDIndex(int rowInd, int colNum, int colInd);
    // add rectangle to image
    void addRectangle(RectangleClass &rec, bool isFilled);
    // add pattern to image
    void addPattern(PatternClass &pat, int pRowStart, int pColStart);
    // add another ppm image
    void addImage(ColorImageClass &insertImg, int rowStart, int colStart);
    //get ppm image width(column value)
    int getWidth(); 
    //get ppm image height(row value)
    int getHeight();
    //get ppm image max color valu
    int getColorMax(); 
    //get ppm image magic number
    string getMagicNum(); 
    //get oneDptr
    ColorClass* getPtr(); 
};

#endif