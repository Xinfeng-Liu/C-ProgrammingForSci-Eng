#ifndef _ROWCOLUMN_CLASS_H_
#define _ROWCOLUMN_CLASS_H_

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

//set & get row/column values
class RowColumnClass{
  private:
    int inRow;
    int inCol;
  public:
    //default ctor: set row, col to defaule value
    RowColumnClass(); 
    //ctor: set row, col to input value
    RowColumnClass(int inputRow, int inputCol);
    //set row, col to input value
    void setRowCol(int inputRow, int inputCol); 
    //set row to input value
    void setRow(int inputRow); 
    //set col to input value
    void setCol(int inputCol);
    //get row number
    int getRow(); 
    //get col number
    int getCol(); 
};

#endif