/*  
  Hesampour Kiarash
  Jun / 3 / 2020 , Final
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>
using namespace std;

ifstream infile;

void inputHandler(int [],float [], int &);
void SearchDisplayHandler(int [],float [],float ,int, int );
void averageHandler(float [], float ,int, int );

int main() {
    int max = 25;
    int employee_id[max], i;
    float pay [max], total;
    int sizeOfArray ;
    char choice = 'Y';

    inputHandler(employee_id,pay, sizeOfArray);

    while(choice == 'Y' ){
        cout << " Please Enter the Employee Id You are Looking  for : " ;
        int current_employee_id;
        cin >> current_employee_id;
        SearchDisplayHandler(employee_id,pay,current_employee_id,sizeOfArray, i);
        cout << " Want to Search More ? if Yes Please type ' Y ' if not type  ' N ' : " ;
        cin >> choice;
        choice = toupper(choice);
    }
    averageHandler(pay, total ,sizeOfArray, i);
}

void inputHandler(int employee_id[],float pay[], int & sizeOfArray){

   infile.open("PayRates.txt");
   sizeOfArray = 0;

   infile >> employee_id[sizeOfArray] >> pay[sizeOfArray];
   while(!infile.eof()){

    sizeOfArray += 1; 
    infile >> employee_id[sizeOfArray] >> pay[sizeOfArray];

   }
}

void SearchDisplayHandler(int employee_id[],float pay[],float current_employee_id,int sizeOfArray, int i){
   char found = 'N' ;
   for( i = 0 ; i < sizeOfArray ; i++){

       if( employee_id[i] == current_employee_id ){

           cout << " Payrate of Employee with ID ' " << employee_id[i] << " ' : " << pay[i] << endl;
           found = 'Y';
           break;
       }
   }
   if ( found == 'N' ){
    cout << " Oops ! An Employee with Id " << current_employee_id << " Couldn't be Found . " << endl;
   }
};

void averageHandler(float pay[], float total ,int sizeOfArray, int i){

   total = 0;
   for( i = 0 ; i < sizeOfArray; i++){

       total = total + pay[i];
   }

   cout << "\nAverage = " << total / sizeOfArray << endl;
}
