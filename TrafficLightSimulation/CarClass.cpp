#include "CarClass.h"

#include <iostream>
using namespace std;

//Programmer: Xinfeng Liu
//Unique Name: xinfengl
//Date: November 30 2020
//Purpose: Assign the static attribute used for auto-assigning unique ids
int CarClass::nextIdVal = 0;

ostream& operator<<(
     ostream& outStream,
     const CarClass &carToPrint
     )
{
  outStream << "Car id: " << carToPrint.uniqueId <<
               " traveling: " << carToPrint.travelDir <<
               " arrived: " << carToPrint.arrivalTime;

  return outStream;
}

