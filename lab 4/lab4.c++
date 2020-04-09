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
  char redo = 'y';
    do
    {
    char drink_type[200];
    int caffeine_amount, hours;
    float reduce_percent, remaining_caffeine;
    
    bool condition1 = true;
    bool condition2 = true;
    bool condition3 = true;
      
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
        else if (caffeine_amount > 350 ){
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
          if (caffeine_amount == 0){
            cout << " No More caffeine Left " << endl;
            i = hours;
          }
        };
        redo = 'n';
        cout << " Do you Want to try again ? 'Y' for yes and 'N' for no : ";
        cin  >> redo;
    } while (redo == 'y' || redo == 'Y');
    return(0);


};
/*
Please Enter The Drink Type : Coke
Please Enter The Amount of caffeine : 500
Error--mgs too high try again 
Please Enter The Amount of caffeine : 
// _______________________________ //
Please Enter The Drink Type : Pepsi
 Please Enter The Amount of caffeine : ABC
 bad Credintials Try again . 
 Please Enter The Amount of caffeine : 
//  ____________________________ //
Please Enter The Drink Type : Pepsi
 Please Enter The Amount of caffeine : 200
 Please Enter How Many Hours :   -4
 Hours can't be 0 or a negative number try again  : 
 Please Enter How Many Hours :   
//  ______________________________ //
Please Enter The Drink Type : Coffee
 Please Enter The Amount of caffeine : 250
 Please Enter How Many Hours :   XXX
 bad Credintials Try again . 
 Please Enter How Many Hours : 
//  ____________________________ //
Please Enter The Drink Type : Coke zero
 Please Enter The Amount of caffeine :  0
 hehe try again  
 Please Enter The Amount of caffeine :
//  ______________________________ //
Please Enter The Drink Type : 16 oz Starbucks coffee
 Please Enter The Amount of caffeine : 310
 Please Enter How Many Hours :   10
 The Remaining Amount of Caffein After 1 Hour(s) in 16 oz Starbucks coffee is 270mg
 The Remaining Amount of Caffein After 2 Hour(s) in 16 oz Starbucks coffee is 230mg
 The Remaining Amount of Caffein After 3 Hour(s) in 16 oz Starbucks coffee is 190mg
 The Remaining Amount of Caffein After 4 Hour(s) in 16 oz Starbucks coffee is 150mg
 The Remaining Amount of Caffein After 5 Hour(s) in 16 oz Starbucks coffee is 110mg
 The Remaining Amount of Caffein After 6 Hour(s) in 16 oz Starbucks coffee is 70mg
 The Remaining Amount of Caffein After 7 Hour(s) in 16 oz Starbucks coffee is 30mg
 The Remaining Amount of Caffein After 8 Hour(s) in 16 oz Starbucks coffee is -10mg
 The Remaining Amount of Caffein After 9 Hour(s) in 16 oz Starbucks coffee is -50mg
 The Remaining Amount of Caffein After 10 Hour(s) in 16 oz Starbucks coffee is -90mg
 Do you Want to try again ? 'Y' for yes and 'N' for no : 
//  _________________________________________________ //
Please Enter The Drink Type : 5-hr Energy drink
 Please Enter The Amount of caffeine : 245
 Please Enter How Many Hours :   7
 The Remaining Amount of Caffein After 1 Hour(s) in 5-hr Energy drink is 214mg
 The Remaining Amount of Caffein After 2 Hour(s) in 5-hr Energy drink is 183mg
 The Remaining Amount of Caffein After 3 Hour(s) in 5-hr Energy drink is 152mg
 The Remaining Amount of Caffein After 4 Hour(s) in 5-hr Energy drink is 121mg
 The Remaining Amount of Caffein After 5 Hour(s) in 5-hr Energy drink is 90mg
 The Remaining Amount of Caffein After 6 Hour(s) in 5-hr Energy drink is 59mg
 The Remaining Amount of Caffein After 7 Hour(s) in 5-hr Energy drink is 28mg
 Do you Want to try again ? 'Y' for yes and 'N' for no : 
//  ________________________________________________ //
Please Enter The Drink Type : Black Tea       
 Please Enter The Amount of caffeine : 47
 Please Enter How Many Hours :   5
 The Remaining Amount of Caffein After 1 Hour(s) in Black Tea is 41mg
 The Remaining Amount of Caffein After 2 Hour(s) in Black Tea is 35mg
 The Remaining Amount of Caffein After 3 Hour(s) in Black Tea is 29mg
 The Remaining Amount of Caffein After 4 Hour(s) in Black Tea is 23mg
 The Remaining Amount of Caffein After 5 Hour(s) in Black Tea is 17mg
 Do you Want to try again ? 'Y' for yes and 'N' for no : 
//  ________________________________________________ //
Please Enter The Drink Type : Red Bull
 Please Enter The Amount of caffeine : 80
 Please Enter How Many Hours :   12
 The Remaining Amount of Caffein After 1 Hour(s) in Red Bull is 70mg
 The Remaining Amount of Caffein After 2 Hour(s) in Red Bull is 60mg
 The Remaining Amount of Caffein After 3 Hour(s) in Red Bull is 50mg
 The Remaining Amount of Caffein After 4 Hour(s) in Red Bull is 40mg
 The Remaining Amount of Caffein After 5 Hour(s) in Red Bull is 30mg
 The Remaining Amount of Caffein After 6 Hour(s) in Red Bull is 20mg
 The Remaining Amount of Caffein After 7 Hour(s) in Red Bull is 10mg
 The Remaining Amount of Caffein After 8 Hour(s) in Red Bull is 0mg
 No More caffeine Left 
 Do you Want to try again ? 'Y' for yes and 'N' for no : 
//  _____________________________________________ // 
*/
