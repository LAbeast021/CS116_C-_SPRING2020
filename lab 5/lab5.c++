/*  
  Hesampour Kiarash
  April / 19 / 2020 , Lab # 5
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
int main(){

ifstream infile;
ofstream outfile;

int i , row = 0;
int const col = 7;
int num, highest_num, lowest_num, total_sum = 0, total_highest_num = 0, total_lowest_num = 5000, number_count = 0;
int sum_of_row = 0;
double average_of_row, total_average;

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

outfile << " ______________________________________________________________" << "\n" <<endl;

while (!infile.fail() && !infile.eof()) {
    row +=1;
    infile >> num;
    number_count += 1;
    highest_num = num;
    lowest_num = num;
    outfile << " Row " << row << " : ";

    for(i=1 ; i < col ; i++ ){
        sum_of_row += num;
        outfile << num << " - ";
        infile >> num;
        number_count += 1;
        if (num > highest_num){
            highest_num = num;
        };
        if (num < lowest_num){
            lowest_num = num;
        };
        
    }
    sum_of_row += num;
    outfile << num  << endl;
    average_of_row = sum_of_row / col;
    outfile << "\t" << " Highest Number : " << highest_num << " . " << endl;
    outfile << "\t" << " Lowest  Number : " << lowest_num  << " . " << endl; 
    outfile << "\t" << " The Sum of the row is : " << sum_of_row << " . " << endl;
    outfile << "\t" << " The Average of the row is : " << average_of_row << " . " << endl;
    outfile << " ______________________________________________________________" << "\n" << endl;

    total_sum += sum_of_row;

    if (total_highest_num < highest_num){
            total_highest_num = highest_num;
        };
    if (total_lowest_num > lowest_num){
            total_lowest_num = lowest_num;
        };

    sum_of_row = 0;


}

if (!infile.eof()) {
    cout << "Input failure before reaching end of input file." << endl;
}

total_average = total_sum / number_count;

outfile << " There are " << number_count << " numbers in this file . " << number_count / 7  << " rows of numbers . " << endl;
outfile << " The Highest number among them is " << total_highest_num << " . " << endl;
outfile << " The Lowest number among them is " << total_lowest_num << " . " << endl;
outfile << " The total sum is " << total_sum << " . " << endl;
outfile << " The Average for all the numbers is " << total_average << " . " << endl;
outfile << " ________________________________________________________________________________________________" << "\n" << endl;


infile.close();
outfile.close();
return 0;

}
/*
 ______________________________________________________________

 Row 1 : 346 - 130 - 982 - 90 - 656 - 117 - 595
	 Highest Number : 982 . 
	 Lowest  Number : 90 . 
	 The Sum of the row is : 2916 . 
	 The Average of the row is : 416 . 
 ______________________________________________________________

 Row 2 : 415 - 948 - 126 - 4 - 558 - 571 - 87
	 Highest Number : 948 . 
	 Lowest  Number : 4 . 
	 The Sum of the row is : 2709 . 
	 The Average of the row is : 387 . 
 ______________________________________________________________

 Row 3 : 42 - 360 - 412 - 721 - 463 - 47 - 119
	 Highest Number : 721 . 
	 Lowest  Number : 42 . 
	 The Sum of the row is : 2164 . 
	 The Average of the row is : 309 . 
 ______________________________________________________________

 Row 4 : 441 - 190 - 985 - 214 - 509 - 2 - 571
	 Highest Number : 985 . 
	 Lowest  Number : 2 . 
	 The Sum of the row is : 2912 . 
	 The Average of the row is : 416 . 
 ______________________________________________________________

 Row 5 : 77 - 81 - 681 - 651 - 995 - 93 - 74
	 Highest Number : 995 . 
	 Lowest  Number : 74 . 
	 The Sum of the row is : 2652 . 
	 The Average of the row is : 378 . 
 ______________________________________________________________

 Row 6 : 310 - 9 - 995 - 561 - 92 - 14 - 288
	 Highest Number : 995 . 
	 Lowest  Number : 9 . 
	 The Sum of the row is : 2269 . 
	 The Average of the row is : 324 . 
 ______________________________________________________________

 Row 7 : 466 - 664 - 892 - 8 - 766 - 34 - 639
	 Highest Number : 892 . 
	 Lowest  Number : 8 . 
	 The Sum of the row is : 3469 . 
	 The Average of the row is : 495 . 
 ______________________________________________________________

 Row 8 : 151 - 64 - 98 - 813 - 67 - 834 - 369
	 Highest Number : 834 . 
	 Lowest  Number : 64 . 
	 The Sum of the row is : 2396 . 
	 The Average of the row is : 342 . 
 ______________________________________________________________

 There are 56 numbers in this file . 8 rows of numbers . 
 The Highest number among them is 995 . 
 The Lowest number among them is 2 . 
 The total sum is 21487 . 
 The Average for all the numbers is 383 . 
 ________________________________________________________________________________________________
*/