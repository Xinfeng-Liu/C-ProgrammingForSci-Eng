#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "random.h"

//Name: Xinfeng Liu
//Unique Name: xinfengl
//Date: November 30 2020
void IntersectionSimulationClass::readParametersFromFile(
     const string &paramFname
     )
{
  bool success = true;;
  ifstream paramF;

  paramF.open(paramFname.c_str());

  //Check that the file was able to be opened...
  if (paramF.fail())
  {
    success = false;
    cout << "ERROR: Unable to open parameter file: " << paramFname << endl;
  }
  else
  {
    //Now read in all the params, according to the specified format of
    //the text-based parameter file.
    if (success)
    {
      paramF >> randomSeedVal;
      if (paramF.fail() ||
          randomSeedVal < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set random generatsor seed" << endl;
      }
    }

    if (success)
    {
      paramF >> timeToStopSim;
      if (paramF.fail() ||
          timeToStopSim <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set simulation end time" << endl;
      }
    }

    if (success)
    {
      paramF >> eastWestGreenTime >> eastWestYellowTime;
      if (paramF.fail() ||
          eastWestGreenTime <= 0 ||
          eastWestYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east-west times" << endl;
      }
    }

    if (success)
    {
      paramF >> northSouthGreenTime >> northSouthYellowTime;
      if (paramF.fail() ||
          northSouthGreenTime <= 0 ||
          northSouthYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north-south times" << endl;
      }
    }

    if (success)
    {
      paramF >> eastArrivalMean >> eastArrivalStdDev;
      if (paramF.fail() ||
          eastArrivalMean <= 0 ||
          eastArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> westArrivalMean >> westArrivalStdDev;
      if (paramF.fail() ||
          westArrivalMean <= 0 ||
          westArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set west arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> northArrivalMean >> northArrivalStdDev;
      if (paramF.fail() ||
          northArrivalMean <= 0 ||
          northArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> southArrivalMean >> southArrivalStdDev;
      if (paramF.fail() ||
          southArrivalMean <= 0 ||
          southArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set south arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> percentCarsAdvanceOnYellow;
      if (paramF.fail() || 
          percentCarsAdvanceOnYellow < 0 ||
          percentCarsAdvanceOnYellow > 100)
      {
        success = false;
        cout << "ERROR: Unable to read/set percentage yellow advance" << endl;
      }

      //Use the specified seed to seed the random number generator
      setSeed(randomSeedVal);
    }

    paramF.close();
  }

  //Let the caller know whether things went well or not by printing the
  if (!success)
  {
    cout << "ERROR: Parameter file was NOT read in successfully, so the " <<
            "simulation is NOT setup properly!" << endl;
    isSetupProperly = false;
  }
  else
  {
    cout << "Parameters read in successfully - simulation is ready!" << endl;
    isSetupProperly = true;
  }
}

void IntersectionSimulationClass::printParameters() const
{
  cout << "===== Begin Simulation Parameters =====" << endl;
  if (!isSetupProperly)
  {
    cout << "  Simulation is not yet properly setup!" << endl;
  }
  else
  {
    cout << "  Random generator seed: " << randomSeedVal << endl;
    cout << "  Simulation end time: " << timeToStopSim << endl;

    cout << "  East-West Timing -" <<
            " Green: " << eastWestGreenTime << 
            " Yellow: " << eastWestYellowTime <<
            " Red: " << getEastWestRedTime() << endl;

    cout << "  North-South Timing -" <<
            " Green: " << northSouthGreenTime << 
            " Yellow: " << northSouthYellowTime <<
            " Red: " << getNorthSouthRedTime() << endl;

    cout << "  Arrival Distributions:" << endl;
    cout << "    East - Mean: " << eastArrivalMean << 
            " StdDev: " << eastArrivalStdDev << endl;
    cout << "    West - Mean: " << westArrivalMean << 
            " StdDev: " << westArrivalStdDev << endl;
    cout << "    North - Mean: " << northArrivalMean << 
            " StdDev: " << northArrivalStdDev << endl;
    cout << "    South - Mean: " << southArrivalMean << 
            " StdDev: " << southArrivalStdDev << endl;

    cout << "  Percentage cars advancing through yellow: " <<
            percentCarsAdvanceOnYellow << endl;
  }
  cout << "===== End Simulation Parameters =====" << endl;
}

void IntersectionSimulationClass :: scheduleArrivalHelper(
     int &dictionCurrentTime, 
     int dirctMean, int dirctSt, 
     int &directionTime, 
     int &currentTypeId, 
     int eventArrivalDirct){
  cout << "Time: " << dictionCurrentTime << " Scheduled ";
  dictionCurrentTime += getPositiveNormal(dirctMean, dirctSt);
  directionTime = dictionCurrentTime;
  currentTypeId = eventArrivalDirct;
}

void IntersectionSimulationClass::scheduleArrival(
     const string &travelDir
     )
{
  int directionTime;
  int currentTypeId = EVENT_UNKNOWN;
  //handling four event directions
  if(travelDir == EAST_DIRECTION){
    scheduleArrivalHelper(eastCurrentTime, 
                          eastArrivalMean, eastArrivalStdDev, 
                          directionTime, 
                          currentTypeId, 
                          EVENT_ARRIVE_EAST);
  }else if(travelDir == WEST_DIRECTION){
    scheduleArrivalHelper(westCurrentTime, 
                          westArrivalMean, westArrivalStdDev, 
                          directionTime, 
                          currentTypeId,  
                          EVENT_ARRIVE_WEST);
  }else if(travelDir == NORTH_DIRECTION){
    scheduleArrivalHelper(northCurrentTime, 
                          northArrivalMean, northArrivalStdDev, 
                          directionTime, 
                          currentTypeId,  
                          EVENT_ARRIVE_NORTH);
  }else{
    scheduleArrivalHelper(southCurrentTime, 
                          southArrivalMean, southArrivalStdDev, 
                          directionTime, 
                          currentTypeId, 
                          EVENT_ARRIVE_SOUTH);
  }
  EventClass newEvent(directionTime, currentTypeId);
  eventList.insertValue(newEvent);
  cout << newEvent << endl;
}

void IntersectionSimulationClass :: scheduleLightChange(
     )
{
  int currentTypeId = EVENT_UNKNOWN;
  cout << "Time: " << currentTime << " Scheduled ";
  //handling four types of light change
  if(currentLight == LIGHT_GREEN_EW){
    currentTime += eastWestGreenTime;
    currentTypeId = EVENT_CHANGE_YELLOW_EW;
  }else if(currentLight == LIGHT_YELLOW_EW){
    currentTime += eastWestYellowTime;
    currentTypeId = EVENT_CHANGE_GREEN_NS;
  }else if(currentLight == LIGHT_GREEN_NS){
    currentTime += northSouthGreenTime;
    currentTypeId = EVENT_CHANGE_YELLOW_NS;
  }else{
    currentTime += northSouthYellowTime;
    currentTypeId = EVENT_CHANGE_GREEN_EW;
  }
  EventClass newEvent(currentTime, currentTypeId);
  eventList.insertValue(newEvent);
  cout << newEvent << endl;
}

void IntersectionSimulationClass :: handleNextArrival(
     const std::string dirction, 
     int dirctCurrentTime, 
     FIFOQueueClass< CarClass >& dirctQueue, 
     int& maxDirctQueueLength){
  CarClass currentCar(dirction, dirctCurrentTime);
  dirctQueue.enqueue(currentCar);
  cout << "Car #" << currentCar.getId() << " arrives "<< dirction << "-bound";
  cout << " - queue lenghth: " << dirctQueue.getNumElems() << endl;
  scheduleArrival(dirction);
  int dirctQueueLength = dirctQueue.getNumElems();
  if(dirctQueueLength > maxDirctQueueLength){
    maxDirctQueueLength = dirctQueueLength;
  }
}

int IntersectionSimulationClass :: handleNextGreenLight(
    FIFOQueueClass< CarClass >& dirctQueue,
    int dirctColorLightTime,
    std::string direction,
    int& numTotalAdvancedDirct){
  int dirctAdvancedCarNum = 0;
  int dirctAdvnceLen = dirctQueue.getNumElems();
  if(dirctAdvnceLen > 0){
    for(int i = 0; i < dirctAdvnceLen; i ++){
      if(i < dirctColorLightTime){
        CarClass currentCar;
        dirctQueue.dequeue(currentCar);
        cout << "  Car #" << currentCar.getId();
        cout << " advances " << direction << "-boud" << endl;
        numTotalAdvancedDirct ++;
        dirctAdvancedCarNum ++;
      }
    }
  }
  return dirctAdvancedCarNum;
}

int IntersectionSimulationClass :: handleNextYellowLight(
    FIFOQueueClass< CarClass >& dirctQueue,
    int dirctCurrentTime,
    std::string direction,
    int& numTotalAdvancedDirct){                                                      
  int dirctAdvancedCarNum = 0;
  int dirctAdvnceLen = dirctQueue.getNumElems();
    if(dirctAdvnceLen > 0){
      for(int i = 0; i < dirctAdvnceLen; i ++){
        if(i < dirctCurrentTime){
          int randomDirctYellowAdvance = getUniform(UNIFORM_MIN, UNIFORM_MAX);
          if(randomDirctYellowAdvance <= percentCarsAdvanceOnYellow){
            CarClass currentCar;
            dirctQueue.dequeue(currentCar);
            cout << "  Next " << direction;
            cout << "-bound car will advance on yellow" << endl; 
            cout << "  Car #" << currentCar.getId();
            cout << " advances " << direction << "-bound" << endl;
            numTotalAdvancedDirct ++;
            dirctAdvancedCarNum ++;
          }else{
            cout << "  Next " << direction;
            cout <<  "-bound car will NOT advance on yellow" << endl;
            break;
          }
        }
      }
    }
  return dirctAdvancedCarNum;
}

bool IntersectionSimulationClass::handleNextEvent(
     )
{
  EventClass activeEvent;
  eventList.removeFront(activeEvent);
  int currentType = activeEvent.getType();
  int currentTimeOccurs = activeEvent.getTimeOccurs();
  if(currentTimeOccurs > timeToStopSim){
    cout << "Next event occurs AFTER the simulation end time";
    cout << "(" << activeEvent << ")!" << endl;
    isFinished = false;
    return isFinished;
  }
  cout << "Handling " << activeEvent << endl;

  //=============Car Arrival Event Change=============
  if(currentType == EVENT_ARRIVE_EAST ||
     currentType == EVENT_ARRIVE_WEST ||
     currentType == EVENT_ARRIVE_NORTH ||
     currentType == EVENT_ARRIVE_SOUTH){
    cout  << "Time: " << currentTimeOccurs << " ";
    if(currentType == EVENT_ARRIVE_EAST){
      handleNextArrival(EAST_DIRECTION, 
                        eastCurrentTime, 
                        eastQueue, 
                        maxEastQueueLength);
    }else if(currentType == EVENT_ARRIVE_WEST){
      handleNextArrival(WEST_DIRECTION, 
                        westCurrentTime, 
                        westQueue, 
                        maxWestQueueLength);
    }else if(currentType == EVENT_ARRIVE_NORTH){
      handleNextArrival(NORTH_DIRECTION, 
                        northCurrentTime, 
                        northQueue, 
                        maxNorthQueueLength);
    }else{
      handleNextArrival(SOUTH_DIRECTION, 
                        southCurrentTime, 
                        southQueue, 
                        maxSouthQueueLength);
    }

   //=============Light Event Change=============
  }else if(currentType == EVENT_CHANGE_GREEN_EW ||
           currentType == EVENT_CHANGE_YELLOW_EW ||
           currentType == EVENT_CHANGE_GREEN_NS ||
           currentType == EVENT_CHANGE_YELLOW_NS){
    //===Yellow East-West Light===
    if(currentType == EVENT_CHANGE_YELLOW_EW){
      cout << "Advancing cars on east-west green" << endl;
      //east
      int eastAdvancedCarNum = handleNextGreenLight(eastQueue, 
                                                    eastWestGreenTime, 
                                                    EAST_DIRECT, 
                                                    numTotalAdvancedEast);
      //west
      int westAdvancedCarNum = handleNextGreenLight(westQueue, 
                                                    eastWestGreenTime, 
                                                    WEST_DIRECT, 
                                                    numTotalAdvancedWest);
      cout << "East-bound cars advanced on green: " << eastAdvancedCarNum;
      cout << " Remaining queue: " << eastQueue.getNumElems() << endl;
      cout << "West-bound cars advanced on green: " << westAdvancedCarNum;
      cout << " Remaining queue: " << westQueue.getNumElems() << endl;
      currentLight = LIGHT_YELLOW_EW;
      scheduleLightChange();
     
     //===Green North-East Light===
    }else if(currentType == EVENT_CHANGE_GREEN_NS){
      cout << "Advancing cars on east-west yellow" << endl;
      //east
      int eastAdvancedCarNum = handleNextYellowLight(eastQueue, 
                                                     eastWestYellowTime, 
                                                     EAST_DIRECT, 
                                                     numTotalAdvancedEast);
      if(eastQueue.getNumElems() == 0){
        cout << "  No east-bound cars waiting to advance on yellow" << endl;
      }
      //west
      int westAdvancedCarNum = handleNextYellowLight(westQueue, 
                                                     eastWestYellowTime, 
                                                     WEST_DIRECT, 
                                                     numTotalAdvancedWest);
      if(westQueue.getNumElems() == 0){
        cout << "  No west-bound cars waiting to advance on yellow" << endl;
      }
      cout << "East-bound cars advanced on yellow: " << eastAdvancedCarNum;
      cout << " Remaining queue: " << eastQueue.getNumElems() << endl;
      cout << "West-bound cars advanced on yellow: " << westAdvancedCarNum;
      cout << " Remaining queue: " << westQueue.getNumElems() << endl;
      currentLight = LIGHT_GREEN_NS;
      scheduleLightChange();
     
     //===Yellow North-South Light===
    }else if(currentType == EVENT_CHANGE_YELLOW_NS){
      cout << "Advancing cars on north-south green" << endl;
      //north
      int northAdvancedCarNum = handleNextGreenLight(northQueue, 
                                                     northSouthGreenTime, 
                                                     NORTH_DIRECT, 
                                                     numTotalAdvancedNorth);
      //south
      int southAdvancedCarNum = handleNextGreenLight(southQueue, 
                                                     northSouthGreenTime, 
                                                     SOUTH_DIRECT, 
                                                     numTotalAdvancedSouth);
      cout << "North-bound cars advanced on green: " << northAdvancedCarNum;
      cout << " Remaining queue: " << northQueue.getNumElems() << endl;
      cout << "South-bound cars advanced on green: " << southAdvancedCarNum;
      cout << " Remaining queue: " << southQueue.getNumElems() << endl;
      currentLight = LIGHT_YELLOW_NS;
      scheduleLightChange();
     
     //===Green East-West Light===
    }else{
      cout << "Advancing cars on north-south yellow" << endl;
      //north
      int northAdvancedCarNum = handleNextYellowLight(northQueue, 
                                                      northSouthYellowTime, 
                                                      NORTH_DIRECT, 
                                                      numTotalAdvancedNorth);
      if(northQueue.getNumElems() == 0){
        cout << "  No north-bound cars waiting to advance on yellow" << endl;
      }
      //south
      int southAdvancedCarNum = handleNextYellowLight(southQueue, 
                                                      northSouthYellowTime, 
                                                      SOUTH_DIRECT, 
                                                      numTotalAdvancedSouth);
      if(southQueue.getNumElems() == 0){
        cout << "  No south-bound cars waiting to advance on yellow" << endl;
      }
      cout << "North-bound cars advanced on green: " << northAdvancedCarNum;
      cout << " Remaining queue: " << northQueue.getNumElems() << endl;
      cout << "South-bound cars advanced on green: " << southAdvancedCarNum;
      cout << " Remaining queue: " << southQueue.getNumElems() << endl;
      currentLight = LIGHT_GREEN_EW;
      scheduleLightChange();
    }
  }
  cout << endl;
  return isFinished;
}

void IntersectionSimulationClass::printStatistics(
     ) const
{
  cout << "===== Begin Simulation Statistics =====" << endl;
  cout << "  Longest east-bound queue: " << maxEastQueueLength << endl;
  cout << "  Longest west-bound queue: " << maxWestQueueLength << endl;
  cout << "  Longest north-bound queue: " << maxNorthQueueLength << endl;
  cout << "  Longest south-bound queue: " << maxSouthQueueLength << endl;
  cout << "  Total cars advanced east-bound: " <<
          numTotalAdvancedEast << endl;
  cout << "  Total cars advanced west-bound: " <<
          numTotalAdvancedWest << endl;
  cout << "  Total cars advanced north-bound: " <<
          numTotalAdvancedNorth << endl;
  cout << "  Total cars advanced south-bound: " <<
          numTotalAdvancedSouth << endl;
  cout << "===== End Simulation Statistics =====" << endl;
}
