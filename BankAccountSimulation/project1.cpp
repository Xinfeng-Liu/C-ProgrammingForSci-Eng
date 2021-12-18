#include <iostream>
#include <string>
using namespace std;


// Name: Xinfeng Liu; UMID: 16393614
// Project Period: 09/15/2021 - 09/21/2021
// Project Purpose: This project will accrue interest for an investment account

bool accrueInterest(double& balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth);
bool accrueOneMonthsInterest(double& balanceAmt, const bool doPrintInfo);

#ifdef ANDREW_TEST 
#include "andrewTest.h" 
#else 

int main(){
  double initalBalance;
  int monthAsked;
  string dispayFormat;
  bool dispayFormatBool;
  
  cout << "Enter the initial balance of the account: " << endl;
  cin >> initalBalance;


  cout << "Enter the number of months to accure interest: " << endl;
  cin >> monthAsked;
  
  cout << "Show month-by-month result- 'y' for yes, ";
  cout << "any other for no: " << endl;
  cin >> dispayFormat;
  if(dispayFormat=="y"){
    dispayFormatBool = true;
  }else{
    dispayFormatBool = false;
  };

  accrueInterest(initalBalance,monthAsked,dispayFormatBool);
}

#endif 

bool accrueInterest(
     double& balanceAmt,
     const int numMonths,
     const bool doPrintEachMonth){
       float initialBalance = balanceAmt;
       float interestAccrued;
       if(numMonths<0){
         cout << "ERROR in accrueInterest: numMonths must be > 0, ";
         cout << "but the value"<<  numMonths << "was provided!" << endl;
         cout << "Sorry, an error was detected.";
         cout << "Unable to provide results!" << endl;
         return false;
       }
       if(balanceAmt<0){
         cout << "ERROR in balanceAmt: balanceAmt must be >= 0, ";
         cout << "but the value " <<  balanceAmt << " was provided!" << endl;
         cout << "Sorry, an error was detected. ";
         cout << "Unable to provide results!" << endl;
         return false;
       }else{
         for(int n=0; n<numMonths; n++){
           accrueOneMonthsInterest(balanceAmt,doPrintEachMonth);
         }
         }
      
       interestAccrued = balanceAmt - initialBalance;
      
       cout << "Interest accrued for " << numMonths << " months!" << endl;
       cout << endl;
       cout << "Initial balance: " << initialBalance << endl;
       cout << "Total interest accrued: " << interestAccrued << endl;
       cout << "Final balance: " << balanceAmt << endl;

       return true;
}


bool accrueOneMonthsInterest(double& balanceAmt, const bool doPrintInfo){
      float INTEREST_RATE;
      
      if(balanceAmt>=0 && balanceAmt<1000){
         INTEREST_RATE = 0.0015;
      }else if(balanceAmt>=15000){
         INTEREST_RATE = 0.004;
      }else if(1000<balanceAmt && balanceAmt<=15000){
        INTEREST_RATE = 0.00225;
      };
      
      float balanceAmtTemp = balanceAmt;
      float interestAccrued = INTEREST_RATE * balanceAmt;
      float newBalance = balanceAmt * (1 + INTEREST_RATE);
      balanceAmt = newBalance;
      
      if(doPrintInfo==true){
        cout << "Accruing interest for 1 month:" << endl;
        cout << "Initial balance: " << balanceAmtTemp << endl;
        cout << "Initial rate: " << INTEREST_RATE << endl;
        cout << "interestAccrued: " << interestAccrued << endl;
        cout << "newBalance: " << newBalance << endl;
      }     
      return true;
}