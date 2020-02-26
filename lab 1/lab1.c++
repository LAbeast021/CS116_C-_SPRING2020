// This Little Program Converts from pound to kilograms
// Kiarash Hesampour
// 25978
// Lab 1

#include <iostream>
#include <string>
using namespace std;


int main(){
    string name;
    double pounds, kg;
    cout << "What Is Your Name (first name only) : ";
    cin >> name;
    cout << "How Many Pounds do you weight ? ";
    cin >> pounds;
    kg = pounds /2.205;
    cout << name << ", You Weight " << kg << endl;
    // system("pause");
    return 0;
}

/*
What Is Your Name (first name only) : Kiarash
How Many Pounds do you weight ? 131
Kiarash, You Weight 59.4104 
*/