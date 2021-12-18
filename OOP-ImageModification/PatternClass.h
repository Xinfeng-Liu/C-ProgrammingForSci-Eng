#ifndef _PATTERN_CLASS_H_
#define _PATTERN_CLASS_H_
#include <string>

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

//class PatternClass declarations: used to represent the pattern
class PatternClass{
  private:
    int patternCol;
    int patternRow;
    bool isFileValid;
    //updated oneDPtr
    PatternClass* oneDPtr;
    ColorClass patternColor;
    int patternIndex;

  public:
    //ctor: set file status and pointer to null
    PatternClass();
    //dctor: delete oneDPtr
    ~PatternClass();
    //set pattern color based on customer choice
    void setPatternColor(int colorChoice); 
    //read row and col value in the pattern txt file
    //return true if can be read successfully
    //return false otherwise
    bool readRowCol(ifstream &inFile, 
                    bool &isFileValid, 
                    int &patternRow, 
                    int &patternCol);
    //read binary indicator from the pattern txt file
    //return true if each indicator can be read successfully
    //return false otherwise
    bool readBinaryInd(ifstream &inFile,
                       bool &isFileValid,
                       const int &patternRow,
                       const int &PatternCol);
    //read the pattern file
    //return true if the file can be read successfully
    //return false otherwise
    bool readPattern(string file_name);
    //get pattern color
    ColorClass getPatternColor();
    //set indicator index
    void setIndicatorIndex(int index);
    //get pixel index
    int getpatternIndex(); 
    //get pattern col number
    int getPatternCol();
    //get pattern row number
    int getPatternRow();
    //resubmit updated: get one D pointer
    PatternClass* getpointer();
};

#endif