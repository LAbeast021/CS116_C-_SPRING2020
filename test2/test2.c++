/*  
  Hesampour Kiarash
  May / 4 / 2020 , test # 2
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

double billCalculator (string customerId, int number_of_text) {
    const int basic_monthly = 5;
    const double extra_charge = 0.05, tax = 0.12;
    double monthly_payment;
    int extra_messages;

    if (number_of_text < 0 || number_of_text > 300) {
        return 0;
    }
    else {
        if (number_of_text <= 60){
            monthly_payment = basic_monthly +  (basic_monthly * tax);
            return monthly_payment;
        }
        else {
            extra_messages = number_of_text - 60;
            monthly_payment = basic_monthly + (extra_messages * extra_charge);
            monthly_payment = monthly_payment + (monthly_payment * tax);
            return monthly_payment;
        }
    }

}; 

void output_handler (double monthly_payment, string customerId, int number_of_text){
    if (monthly_payment){
        cout << customerId << setw(10) << number_of_text << setw(10) << monthly_payment << endl;
    }
    else {
        cout << customerId << setw(10) << number_of_text << setw(13) << " Bad Data" << endl;
    }
}
int main(){
    string customerId;
    int number_of_text;
    double monthly_payment;

    ifstream infile;
    ofstream outfile;

    infile.open("./Temp.txt");
    if(!infile.is_open()){
    cout << " An error occurd while opening the input file  . " << endl;
    return 1;
    };

    cout << "Customer " << setw(5) << " Messages " << setw(5) << " Monthly Charge " << endl;

    infile >> customerId;
    infile >> number_of_text;
    while (!infile.fail() && !infile.eof()) {
        monthly_payment = billCalculator(customerId, number_of_text);
        output_handler(monthly_payment, customerId, number_of_text);
        infile >> customerId;
        infile >> number_of_text;
    }
    infile >> customerId;
    infile >> number_of_text;
    monthly_payment = billCalculator(customerId, number_of_text);
    output_handler(monthly_payment, customerId, number_of_text);
}
/*
Customer  Messages  Monthly Charge 
AAA        45       5.6
BBB       200     13.44
CCC       -10     Bad Data
DDD         0       5.6
*/