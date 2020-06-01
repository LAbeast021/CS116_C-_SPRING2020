/*  
  Hesampour Kiarash
  May / 3 / 2020 , Lab # 6
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

ifstream infile;
ofstream outfile, errorfile;

void dataInput (char  &, char   &, int  &, int   &, int   &, double &, double &, int &, char &, char & );
double mealCostCalculator (char , int, int );
void taxAndTipCalculator (double , char ,double &, double &);
void outputHandler(int,int,int,char,char,double,double,double,double,double &);


int main(){
    

    errorfile.open ("./errorFile.txt");
        if(!errorfile.is_open()){
            cout << " An error occurd while opening the error file  . " << endl;
            return 1;
    };
    infile.open("./dataFile.txt");
        if(!infile.is_open()){
            cout << " An error occurd while opening the input file  . " << endl;
            return 1;
    };
    outfile.open ("./newDataFile.txt");
        if(!outfile.is_open()){
            cout << " An error occurd while opening the output file  . " << endl;
            return 1;
    };

    outfile << "|--" << " Party Id " << "--|--" << " # of Adults" << "--|--" << " # of Kids" 
    << "--|--" << " Meal Type" << "--|--" << " Is a Weekend?" <<"--|--" << " Deposit Amount" 
    << "--|--" << " Meal Cost" << "--|--" << " Tip/tax/surcharge" <<"--|--" << " Total Bill Due" << "--|" <<endl;

    while (!infile.fail() && !infile.eof()) {
        char meal_type, weekend, meal_type_error, weekend_error;
        int partyId, number_of_adults, number_of_kids, number_of_people_error;
        double deposit_amount, deposit_error , total_meal_cost, tip_tax_amount, surcharge_amount, total_amount;
        dataInput( meal_type , weekend,partyId, number_of_adults, number_of_kids, deposit_amount, deposit_error, number_of_people_error, meal_type_error,weekend_error);
        if(deposit_error && number_of_people_error && meal_type_error && weekend_error){
           total_meal_cost = mealCostCalculator(meal_type, number_of_adults, number_of_kids);
           taxAndTipCalculator(total_meal_cost, weekend, tip_tax_amount, surcharge_amount );
           outputHandler(partyId,number_of_adults,number_of_kids,meal_type,weekend,deposit_amount,total_meal_cost,tip_tax_amount,surcharge_amount,total_amount);
        }
    };
    if (!infile.eof()) {
        cout << "Input failure before reaching end of input file." << endl;
    };


    return 0;

};
void dataInput (char  & meal_type , char  & weekend, int  & partyId, int  & number_of_adults, int  & number_of_kids,
 double  & deposit_amount, double & deposit_error, int & number_of_people_error, char & meal_type_error, char & weekend_error){

    infile >> partyId >> number_of_adults >> number_of_kids >> meal_type >> weekend >> deposit_amount;

    deposit_error = deposit_amount >= 0;
    number_of_people_error = number_of_adults >= 0 && number_of_kids >= 0;
    meal_type_error = meal_type == 'S' || meal_type == 'D';
    weekend_error = weekend == 'Y' || weekend == 'N';

    if(!deposit_error) {
        errorfile << " in party id : " << partyId <<" Deposit cannot be a negative number .!!! " << endl;
    };
    if(!number_of_people_error) {
        errorfile << " in party id : " << partyId << " Number of people cannot be a negative number .!!! " << endl;
    };
    if(!meal_type_error) {
        errorfile << " in party id : " << partyId << " Invalid data, Meal Type should be either ' S ' or ' D ' .!!! " << endl; 
    };
    if(!weekend_error) {
        errorfile << " in party id : " << partyId << " Invalid data, weekwnd  should be either ' Y ' for yes or ' N ' for no .!!! " << endl; 
    };  
};

double mealCostCalculator (char meal_type, int number_of_adults, int number_of_kids){
    const double deluxe_per_adult = 25.80, standard_per_adult = 21.75;
    double total_cost_of_meal_for_adults, total_cost_of_meal_for_kids, total_meal_cost;
    if (meal_type == 'D') {
        total_cost_of_meal_for_adults = number_of_adults * deluxe_per_adult;
        total_cost_of_meal_for_kids = (number_of_kids * deluxe_per_adult) * 0.60;
        total_meal_cost = total_cost_of_meal_for_adults + total_cost_of_meal_for_kids;
    }
    else if (meal_type == 'S'){
        total_cost_of_meal_for_adults = number_of_adults * standard_per_adult;
        total_cost_of_meal_for_kids = (number_of_kids * standard_per_adult )* 0.60;
        total_meal_cost = total_cost_of_meal_for_adults + total_cost_of_meal_for_kids;
    }

    return total_meal_cost;
};

void taxAndTipCalculator (double total_meal_cost, char weekend, double & tip_tax_amount, double & surcharge_amount){
    const double tax = 0.18, Weekend_extra_tax = 0.07;
    if (weekend == 'N'){
        tip_tax_amount =  total_meal_cost * tax;
        surcharge_amount = 0;
    }
    else{
        tip_tax_amount =  total_meal_cost * tax;
        surcharge_amount = (total_meal_cost + tip_tax_amount ) * Weekend_extra_tax;
    }
};
void outputHandler (int partyId,int number_of_adults,int number_of_kids,char meal_type,char weekend,double deposit_amount,double total_meal_cost,double tip_tax_amount,double surcharge_amount,double & total_amount){
    total_amount = total_meal_cost + tip_tax_amount + surcharge_amount + deposit_amount;
    outfile  << "|-- " << setw(5) << partyId << setw(15) << number_of_adults << setw(15)  << number_of_kids << setw(15) << meal_type << setw(17)  << weekend  << setw(19)
        << " $ "<< deposit_amount << setw(15) << " $ " << total_meal_cost << setw(10)   << " $ " << tip_tax_amount+surcharge_amount << setw(10)   << "$ "<< total_amount << endl;
};

/*
|-- Party Id --|-- # of Adults--|-- # of Kids--|-- Meal Type--|-- Is a Weekend?--|-- Deposit Amount--|-- Meal Cost--|-- Tip/tax/surcharge--|-- Total Bill Due--|
|--     1             10              0              S                Y                 $ 100             $ 217.5        $ 57.1155        $ 374.615
|--     2             27              3              D                Y                 $ 57.5             $ 743.04        $ 195.122        $ 995.662
|--     3            125             17              D                N                 $ 0             $ 3488.16        $ 627.869        $ 4116.03
|--     4              4              0              S                N                 $ 25             $ 87        $ 15.66        $ 127.66
|--     5              0             25              S                Y                 $ 23.75             $ 326.25        $ 85.6732        $ 435.673
|--     6            250             43              D                N                 $ 500             $ 7115.64        $ 1280.82        $ 8896.46
|--     7              0              0              D                N                 $ 0             $ 0        $ 0        $ 0
|--    10              5              0              D                Y                 $ 275             $ 129        $ 33.8754        $ 437.875

*/
/*
in party id : 8 Invalid data, Meal Type should be either ' S ' or ' D ' .!!! 
 in party id : 9 Invalid data, weekwnd  should be either ' Y ' for yes or ' N ' for no .!!! 
 in party id : 11 Number of people cannot be a negative number .!!! 
 in party id : 12 Number of people cannot be a negative number .!!! 
 in party id : 13 Deposit cannot be a negative number .!!! 
 in party id : 13 Deposit cannot be a negative number .!!!
 */

/*

    <<    not using a file input >>
bool condition1 = true;
    bool condition2 = true;
    bool condition3 = true;
    bool condition4 = true;
    bool condition5 = true;
    bool condition6 = true;


    do
    {
      cout << " Please Enter the Party Id : "  ;
      cin >> *partyId;
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if (*partyId < 0){
            cout << " Party Id can't be a negative number" << endl;
        }
        else
        {
            condition1 = false;
        }
    }while(condition1 != false);
    do
    {
      cout << " Please Enter number of adults : "  ;
      cin >> *number_of_adults;
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if (*number_of_adults < 0){
            cout << " number of adults can't be a negative number" << endl;
        }
        else
        {
            condition2 = false;
        }
    }while(condition2 != false);
    do
    {
      cout << " Please Enter number of kids  : "  ;
      cin >> *number_of_kids;
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if (*number_of_kids < 0){
            cout << " number of kids can't be a negative number" << endl;
        }
        else
        {
            condition3 = false;
        }
    }while(condition3 != false);

    do
    {
      cout << " What is the type of the meal ? ' S ' or ' D '  ? :  "  ;
      cin >> *meal_type;
      *meal_type = toupper(*meal_type);
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if (*meal_type != 'S' && *meal_type != 'D'){
            cout << " Wrong type of meal. type of meal should be  either ' S ' or ' D ' . " << endl;
        }
        else
        {
            condition4 = false;
        }
    }while(condition4 != false);

    do
    {
      cout << " Is it on a weekend ? type ' Y ' for yes and ' N ' for no :  "  ;
      cin >> *weekend;
      *weekend = toupper(*weekend);
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if (*weekend != 'Y' && *weekend != 'N'){
            cout << " Wrong input please type ' Y ' for yes and ' N ' for no :   " << endl;
        }
        else
        {
            condition5 = false;
        }
    }while(condition5 != false);
    
    do
    {
      cout << " Please Enter the deposit amount  : "  ;
      cin >> *deposit_amount;
        if(cin.fail())
        {
            cout << " bad Credintials Try again . " << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else if (*deposit_amount < 0.0){
            cout << " Deposit Amount can't be a negative number" << endl;
        }
        else
        {
            condition6 = false;
        }
    }while(condition6 != false);

    
*/