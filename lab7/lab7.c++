/*  
  Hesampour Kiarash
  May / 19 / 2020 , Lab # 6
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>
using namespace std;

ifstream infile;
ofstream outfile;

void highAndLow (int [],int,int, int &, int &, double &);
void outfileHandler(int [], int [],int, int ,int,int,int,int,int,int, double , double);

int main(){

    int even_length = 100, odd_length = 100, num, i, j, even_highest, odd_highest, even_lowest, odd_lowest ;
    int evenArray[even_length], oddArray[odd_length];
    double even_average, odd_average;

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
    
    infile >>  num ;
    while (!infile.fail() && !infile.eof()) {
        
        if (num % 2 == 0) {
            evenArray[even_length - 100] = num;
            even_length += 1;
        }
        else {
            oddArray[odd_length - 100] = num;
            odd_length += 1;
        }
        infile >>  num ;
    };
    if (!infile.eof()) {
        cout << "Input failure before reaching end of input file." << endl;
    };

    highAndLow (evenArray, even_length,i,even_highest,even_lowest, even_average);
    highAndLow (oddArray ,odd_length,i,odd_highest,odd_lowest, odd_average );

    outfileHandler(evenArray, oddArray,even_length, odd_length, i, j , even_highest, odd_highest, even_lowest, odd_lowest,even_average,odd_average);

};

void highAndLow (int array [], int length, int i , int & highest, int & lowest, double & average){
    highest = array[0];
    lowest = array[0];
    average = 0;

    for (i = 0 ; i < length - 100 ; i++){
        average += array[i];
        if(array[i] > highest) {
            highest = array[i];
        }
        if(array[i] < lowest) {
            lowest = array[i];
        }
    };
    average = average / (length - 100);
};

void outfileHandler(int even_array [], int odd_array [],int even_length, int odd_length, int i, int j , int even_highest, int odd_highest, int even_lowest, int odd_lowest, double even_average, double odd_average){

    outfile << " Array of Even Numbers : [ ";
    for (i=0 ; i < even_length - 100 ; i++){
        outfile << even_array[i] << " , " ;
    };
    outfile << "] " << endl;
    outfile << " Highest Even Number -> " << even_highest << " . " << endl;
    outfile << " Lowest Even Number -> " << even_lowest << " . " << endl;
    outfile << " Average of the Even Array -> " << even_average << " . " << endl;
    outfile << " Numbers larger than the average -> " ;
    for (i=0 ; i < even_length - 100 ; i++){
        if (even_array[i] > even_average){
        outfile << even_array[i] << " , " ;
        }
    };
    outfile << " . " << endl;
    outfile << " __________________________________________________________" << endl;


    outfile << " Array of odd Numbers : [ ";
    for (j=0 ; j < odd_length - 100 ; j++){
        outfile << odd_array[j] << " , " ;
    };
    outfile << "] " << endl;
    outfile << " Highest Odd Number -> " << odd_highest << " . " << endl;
    outfile << " Lowest Odd Number -> " << odd_lowest << " . " << endl;
    outfile << " Average of the Odd Array -> " << odd_average << " . " << endl;
    outfile << " Numbers larger than the average -> " ;
    for (j=0 ; j < odd_length - 100 ; j++){
        if (odd_array[j] > odd_average){
        outfile << odd_array[j] << " , " ;
        }
    };
    outfile << " . " << endl;
    outfile << " __________________________________________________________" << endl;
};
/*
Array of Even Numbers : [ 46 , 30 , 82 , 90 , 56 , 16 , 48 , 26 , 4 , 58 , 0 , 78 , 92 , 60 , 12 , 90 , 14 , 52 , 16 , 80 , 102 , 34 , 10 , 92 , 88 , 66 , 64 , 92 , 66 , 64 , ] 
 Highest Even Number -> 102 . 
 Lowest Even Number -> 0 . 
 Average of the Even Array -> 54.2667 . 
 Numbers larger than the average -> 82 , 90 , 56 , 58 , 78 , 92 , 60 , 90 , 80 , 102 , 92 , 88 , 66 , 64 , 92 , 66 , 64 ,  . 
 __________________________________________________________
 Array of odd Numbers : [ 17 , 95 , 21 , 63 , 47 , 19 , 41 , 85 , -9 , 71 , 79 , 51 , 95 , 79 , 95 , 61 , 89 , 63 , 39 , 5 , ] 
 Highest Odd Number -> 95 . 
 Lowest Odd Number -> -9 . 
 Average of the Odd Array -> 55.3 . 
 Numbers larger than the average -> 95 , 63 , 85 , 71 , 79 , 95 , 79 , 95 , 61 , 89 , 63 ,  . 
 __________________________________________________________
*/
