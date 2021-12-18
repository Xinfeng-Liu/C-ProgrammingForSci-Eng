#include <iostream>
#include <fstream>
#include <string> 
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "printMainMenue.h"
#include "isInputValid.h"
#include "colorOptions.h"

using namespace std;

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

int main(){
  string fileName;
  ColorImageClass initialImage;
  //load initial image
  cout << "Enter string for PPM image file name to load: ";
  cin >> fileName;
  if(initialImage.readFile(fileName)){
    int mainChoice = CHOICE_INITIAL;
    while(mainChoice != EXIST_PROGM){
      mainChoice = printMainMenue();
      if(mainChoice == ANNO_RECTANGLE){
        //choice 1: add rectangle
        int methodChoice;
        int rowStart; 
        int colStart;
        int rowEnd; 
        int colEnd;
        bool validSetup = false;
        cout << UL_LR_RECTANGLE;
        cout << ". Specify upper left and ";
        cout << "lower right corners of rectangle" << endl;
        cout << UL_DIM_RECTANGLE;
        cout << ". Specify upper left corner and ";
        cout << "dimensions of rectangle" << endl;
        cout << CENTER_RECTANGLE;
        cout << ". Specify extent from center of rectangle";
        cout << endl;
        cout << "Enter int for rectangle specification method: ";
        cin >> methodChoice;
        //check if input is valid
        if(cin.fail() || !isInputValid(methodChoice,
                                       CHOICE_MIN, 
                                       RECT_CHOICE_MAX)){
          cout << "Please enter valid method number from 1-3!";
          cout << "The program will return to the previous stage!";
          cout << endl;
        }else{
          //first two methods initial upperleft position
          if(methodChoice != CENTER_RECTANGLE){
            cout << "Enter upper left corner row and column: ";
            cin >> rowStart;
            if(cin.fail()){
              cout << "Please input valid integers of ";
              cout << "upper left row!" << endl;
            }else{
              cin >> colStart;
              if(cin.fail()){
                cout << "Please input valid integers of ";
                cout << "upper left column!" << endl;
              }else{
                //method 1 initialize lowerright
                if(methodChoice == UL_LR_RECTANGLE){
                  cout << "Enter lower right ";
                  cout << "corner row and column: ";
                //method 2 initialize row dimension
                }else{
                  cout << "Enter int for number of rows: ";
                }
                cin >> rowEnd;
                if(cin.fail()){
                  cout << "Please input valid integers ";
                  cout << "of rectangle row!" << endl;
                }else{
                  //method 2 initialize col dimension
                  if(methodChoice == UL_DIM_RECTANGLE){
                    cout << "Enter int for number of columns: ";
                  }
                  cin >> colEnd;
                  if(cin.fail()){
                    cout << "Please input valid integers ";
                    cout << "of rectangle column!";
                    cout << endl;
                  }else{
                    validSetup = true;
                    //resubmit update:
                    //show error for method one if rectangle lower right
                    //col or row value is samller than upper left col or row
                    if(methodChoice == UL_LR_RECTANGLE){
                      if(rowEnd < rowStart || colEnd < colStart){
                        validSetup = false;
                        cout << "Row and colum value of lower right ";
                        cout << "should be bigger than upper left!" << endl;
                      }
                    }
                    //method two convert row/col dimension
                    //to lower right position
                    if(methodChoice == UL_DIM_RECTANGLE){
                      rowEnd += rowStart;
                      colEnd += colStart;
                    }
                  }
                }
              }
            }
          }else{
            // method 3
            int centerRow; 
            int centerCol;
            int halfRow; 
            int halfCol;
            cout << "Enter rectangle center row and column: ";
            cin >> centerRow;
            if(cin.fail()){
              cout << "Please input valid integers for ";
              cout << "center row position!" << endl;
            }else{
              cin >> centerCol;
              if(cin.fail()){
                cout << "Please input valid integers for ";
                cout << "center column position!" << endl;
              }else{
                cout << "Enter int for half number of rows: ";
                cin >> halfRow;
                if(cin.fail()){
                  cout << "Please input valid integers ";
                  cout << "for half row extent!" << endl;
                }else{
                  cout << "Enter int for ";
                  cout << "half number of columns: ";
                  cin >> halfCol;
                  if(cin.fail()){
                    cout << "Please input valid integers ";
                    cout << "for half column extent!";
                    cout << endl;
                  }else{
                    validSetup = true;
                    //convert method 3 info to 
                    //upper-left&lower-right position
                    rowStart = centerRow - halfRow;
                    colStart = centerCol - halfCol;
                    rowEnd = centerRow + halfRow;
                    colEnd = centerCol + halfCol;
                  }
                }
              }
            }
          }
        }
        if(validSetup){
          //set up rectangle position
          //choose color and fill options
          int recColorChoice;
          int isFill;
          colorOptions("rectangle");
          cin >> recColorChoice;
          if(cin.fail() || !isInputValid(recColorChoice, 
                                         CHOICE_MIN, 
                                         COLOR_WHITE)){
            cout << "Invalid color choice!" << endl;
          }else{
            RectangleClass Rectangle(rowStart, 
                                     colStart, 
                                     rowEnd, 
                                     colEnd);
            Rectangle.setRectangleColor(recColorChoice);
            cout << RECTANGLE_UNFILL << ". No" << endl;
            cout << RETANGLE_FILL << ". Yes" << endl;
            cout << "Enter int for rectangle fill option: ";
            cin >> isFill;
            // Use start and end row col parameters to set up
            if(cin.fail() || !isInputValid(isFill, 
                                           RECTANGLE_UNFILL, 
                                           RETANGLE_FILL)){
              cout << "Invaild fill rectangle choice!" << endl;
            }else{
              if(isFill == RECTANGLE_UNFILL){
                initialImage.addRectangle(Rectangle, false);
              }
              if(isFill == RETANGLE_FILL){
                initialImage.addRectangle(Rectangle, true);
              }
            }
          }
        }
      }
          
      //choice 2: insert a pattern
      if(mainChoice == ANNO_PATTERN){
        string patternFileName;
        int pLeftRow;
        int pLeftCol;
        int patternColor;
        cout << "Enter string for file name containing pattern: ";
        cin >> patternFileName;
        PatternClass addedPattern;
        if(addedPattern.readPattern(patternFileName)){
          cout << "Enter upper left corner ";
          cout << "of pattern row and column: ";
          cin >> pLeftRow;
          //resubmit update: added error handling
          if(cin.fail()){
            cout << "Please input valid integers for ";
            cout << "pattern row position!" << endl;
          }else if(pLeftRow + addedPattern.getPatternRow() > 
                   initialImage.getHeight()){
            cout << "Part of pattern went out of range ";
            cout << "of the initial image" << endl;
            cout << "Please re-upload the pattern!" << endl;
          }else{
            cin >> pLeftCol;
            //resubmit update: added error checking
            if(cin.fail()){
              cout << "Please input valid integers for pattern ";
              cout << "column position!" << endl;
            }else if(pLeftCol + addedPattern.getPatternCol() > 
                     initialImage.getWidth()){
              cout << "Part of pattern went out of range";
              cout << "of the initial image" << endl;
              cout << "Please re-upload the pattern!" << endl;
            }else{
              colorOptions("pattern");
              cin >> patternColor;
              if(cin.fail() || !isInputValid(patternColor,
                                             CHOICE_MIN, 
                                             COLOR_WHITE)){
                cout << "Please choose from 1 to 5!" << endl;
              }else{
                addedPattern.setPatternColor(patternColor);
                initialImage.addPattern(addedPattern, 
                                        pLeftRow, 
                                        pLeftCol);
              }
            }
          }
        //corrected curly brace placement
        }else{ 
          cout << "Pattern file cannot be opened!" << endl;
        }
      }
          
      //choice 3: insert another image
      if(mainChoice == INSERT_PPM){
        string addedImage;
        int imageRowStart;
        int imageColStart;
        int imageColor;
        cout << "Enter string for file name of PPM image to insert: ";
        cin >> addedImage;
        ColorImageClass insertImage;
        if(insertImage.readFile(addedImage)){
          cout << "Enter upper left corner to ";
          cout << "insert image row and column: ";
          cin >> imageRowStart;
          //resubmit update: added error handling
          if(imageRowStart + insertImage.getHeight() > 
             initialImage.getHeight()){
            cout << "Part of inserted image is out of range of ";
            cout << "initial image!" << endl;
            cout << "Please re-upload the image!" << endl;
          }else if(cin.fail()){
            cout << "Please input valid integers for ";
            cout << "image row position!" << endl;
          }else{
            cin >> imageColStart;
            //resubmit update: added error handling
            if(imageColStart + insertImage.getWidth() > 
               initialImage.getWidth()){
              cout << "Part of inserted image is out of range of ";
              cout << "initial image!" << endl;
              cout << "Please re-upload the image!" << endl;
            }else if(cin.fail()){
              cout << "Please input valid integers for ";
              cout << "image column position!" << endl;
            }else{
              colorOptions("transparecy");
              cin >> imageColor;
              if(cin.fail() || !isInputValid(imageColor,
                                             CHOICE_MIN, 
                                             COLOR_WHITE)){
                cout << "Invalid input! " << endl;
                cout << "Please choose from 1 to 5!" << endl;
              }else{
                initialImage.addImage(insertImage,
                                      imageRowStart, 
                                      imageColStart);
              }
            }
          }
        }else{
          cout << "Image file cannot be opened!" << endl;
        }
      }
          
      //choice 4: write out the current image
      if(mainChoice == WRITE_IMAGE){
        string outputName;
        cout << "Enter string for PPM file name to output: ";
        cin >> outputName;
        initialImage.writeFile(outputName);
      }
      cin.clear();
      cin.ignore(FILE_IGNORE, '\n');
    }
      
    //choice 5: exit
    cout << "Thank you for using this program!" << endl;
  }else{
    cout << "Fail to load image! Program ends!" << endl;
  }
  return 0;
}