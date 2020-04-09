/*  
  Hesampour Kiarash
  April / 6 / 2020 , Lab # 4
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    char drink_type[200];
    int caffeine_amount, hours;
    float reduce_percent, remaining_caffeine;
    char redo = 'y';
    bool condition1 = true;
    bool condition2 = true;
    bool condition3 = true;
    do
    {
      
    do
    {
      cout << " Please Enter The Drink Type : "  ;
      cin.getline(drink_type,sizeof(drink_type));
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else
        {
            condition1 = false;
        }
    }while(condition1 != false);
    do
    {
      cout << " Please Enter The Amount of caffeine : ";
      cin  >> caffeine_amount;
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(2000, '\n');
        }
        else if (caffeine_amount > 250 ){
          cout << "  Error--mgs too high try again " << endl;
        }
        else if (caffeine_amount <= 0) {
          cout << " hehe try again  " << endl;
        }
        else
        {
            condition2 = false;
        }
    }while(condition2 != false);
     reduce_percent = ((13 * caffeine_amount) / 100);
     do
    {
      cout << " Please Enter How Many Hours :   ";
      cin  >> hours;
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(2000, '\n');
        }
        else if (hours <= 0){
          cout << " Hours can't be 0 or a negative number try again  : " << endl;
        }
        else
        {
            condition3 = false;
        }
    }while(condition3 != false);

        for (int i = 0; i < hours; i++){
          caffeine_amount = caffeine_amount - reduce_percent;
          cout << " The Remaining Amount of Caffein After " << i+1 << " Hour(s) in " << drink_type << " is " << caffeine_amount << "mg" << endl;
        };
        redo = 'n';
        cout << " Do you Want to try again ? 'Y' for yes and 'N' for no : ";
        cin  >> redo;
    } while (redo == 'y' || redo == 'Y');
    return(0);


};
/*
Please Enter The Drink Type : coke
 Please Enter The Amount of caffeine : 46
 Please Enter How Many Hours :   5
 The Remaining Amount of Caffein After 1 Hour(s) in cokeis 41mg
 The Remaining Amount of Caffein After 2 Hour(s) in cokeis 36mg
 The Remaining Amount of Caffein After 3 Hour(s) in cokeis 31mg
 The Remaining Amount of Caffein After 4 Hour(s) in cokeis 26mg
 The Remaining Amount of Caffein After 5 Hour(s) in cokeis 21mg
 Do you Want to try again ? 'Y' for yes and 'N' for no

 Please Enter The Drink Type : pepsi
 Please Enter The Amount of caffeine : 500
  Error--mgs too high try again 
 Please Enter The Amount of caffeine : 


*/
