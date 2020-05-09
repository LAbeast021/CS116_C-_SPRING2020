/*  
  Hesampour Kiarash
  Test 1 , Part 2
  April / 1 / 2020 , Lab # 3
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void DisplayParameters (int &x, int y);
int CalcValue (int x, int y);
            int main (){
            int A = 5, B = 3;

            DisplayParameters (A,B);

            cout << "A= " << A << endl;

            cout << "B = " << B << endl;

             };    

void DisplayParameters (int  &x ,  int y){
                cout << "Values are " << x << " and " << y << endl;

                  x = x + 3;

                 y = y +7;

                cout << "Calc Value is " << CalcValue (x,y) << endl;
                 };

int CalcValue (int x, int y){
    return x * y; 
     };
/*
Please Enter The  Number of Calories  :  100
 Please Enter The  Number of Fat Grams :  3
   27% Fat ,  The Food Is Low In Fat .

Please Enter The  Number of Calories  :  200
 Please Enter The  Number of Fat Grams :  12
   54% Fat . 

Please Enter The  Number of Calories  :  50
 Please Enter The  Number of Fat Grams :  0
    0% Fat ,  The Food Is Low In Fat .

Please Enter The  Number of Calories  :  90
 Please Enter The  Number of Fat Grams :  -5
 Sorry The Number Of Fat Grams Must be Greater Than 0 . 
 Please Try Again : 
 Please Enter The  Number of Calories  :            

Please Enter The  Number of Calories  :  45
 Please Enter The  Number of Fat Grams :  8
 Sorry The Number Of Calories Can Not Be Greater Than The Total Number Of Calories 
 Either The Number Of Calories Or Fat Grams Were Entered Wrong .
 Please Try Again : 
 Please Enter The  Number of Calories  :  
*/
 // float calories, calories_from_fat,fatGrams,percentage_of_calories_from_fat;
    // int caloriesPerFat = 9;
          
    // cout << " Please Enter The  Number of Calories  :  ";
    // cin >> calories;

    // if (calories > 0){

    //     cout << " Please Enter The  Number of Fat Grams :  ";
    //     cin >> fatGrams;

    //     if (fatGrams >= 0){
    //         calories_from_fat = (fatGrams * caloriesPerFat);
    //         percentage_of_calories_from_fat = (calories_from_fat / calories) * 100;
            
    //         if (calories_from_fat > calories){
    //             cout 
    //             << " Sorry The Number Of Calories Can Not Be Greater Than The Total Number Of Calories. " << endl
    //             << " Either The Number Of Calories Or Fat Grams Were Entered Wrong ." << endl
    //             << " Please Try Again : " << endl;
    //             main();
    //         }
    //         else{
    //             if (percentage_of_calories_from_fat < 30 ) {
    //                 cout 
    //                 << setw(5) << percentage_of_calories_from_fat << "% " << "Fat , " << setw(3) << " The Food Is Low In Fat ." << endl; 
    //             }
    //             else {
    //                 cout 
    //                 << setw(5) << percentage_of_calories_from_fat << "% " << "Fat . " << endl; 
    //             }
    //         }
    //     }
    //     else{
    //         cout 
    //         << " Sorry The Number Of Fat Grams Must be Greater Than 0 . " << endl
    //         << " Please Try Again : " << endl;
    //         main();
    //     }
    // }
    // else{
    //     cout 
    //         << " Sorry The Number Of Calories Must be Greater Than 0 . " << endl
    //         << " Please Try Again : " << endl;
    //         main();
    // }