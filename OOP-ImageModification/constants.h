#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <string>

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Project 3 Resubmission
//Date: 11/10/2021 - 11/13/2021
//Purpose: using dynamic allocation, error checking, ftream etc.
//         to modify image with PPM format.

const int COLOR_MIN = 0;
const int COLOR_MAX = 255;
const int MIN_ROW_COL = 0;
const int ROW_COL_DEFAULT = 0;
const int CHOICE_INITIAL = 0;
const int PIXEL_MOVE_STEP = 1;
const int CHOICE_MIN = 1;
const int MAIN_CHOICE_MAX = 5;
const int RECT_CHOICE_MAX = 3;
//resubmit update: modified the main menue 
//related constant names to be more descriptive
const int ANNO_RECTANGLE = 1;
const int ANNO_PATTERN = 2;
const int INSERT_PPM = 3;
const int WRITE_IMAGE = 4;
const int EXIST_PROGM = 5;
//resubmit update: modified the rectangle related
//constant names to be more descriptive
const int UL_LR_RECTANGLE = 1;
const int UL_DIM_RECTANGLE = 2;
const int CENTER_RECTANGLE = 3;
const int FILE_IGNORE = 200;
const int PATTERN_MIN = 0;
const int PATTERN_MAX = 1;
const int COLOR_RED = 1;
const int COLOR_GREEN = 2;
const int COLOR_BLUE = 3;
const int COLOR_BLACK = 4;
const int COLOR_WHITE = 5;
const int RECTANGLE_UNFILL = 1;
const int RETANGLE_FILL = 2;
const int PIXEL_NUMBER = 0;
const std :: string MAGIC_NUMBER = "P3";

#endif
