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

struct household{
    char idcode[4];
    float annualincome;
    int members;
};

void printAllData(household households[], int, int );
void printAboveAverage(household households[], int, int );
void printBelowPoverty(household households[], int, int );
void printallsortedincome(household households[], int, int, int);
void printmedian(household households[], int, int, int );

int main() {
    ifstream inFile;
    ofstream outFile;
    int i, j ,  lngth = 10, userChoice;
    bool tru;
    household households[lngth];
    
    inFile.open ("./dataFile.txt");
    if (inFile.fail()) {
        cout << " There Was a Problem Opening the File " << endl;
        return 1;
    }

    while(!inFile.eof()) {
        inFile >> households[lngth - 10].idcode;
        inFile >> households[lngth - 10].annualincome;
        inFile >> households[lngth - 10].members;

        lngth += 1;
    };
    inFile.close();

    tru = true;
    while (tru) {

        cout << endl <<  "Here is the list of the Options :" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Print All the Data" << endl;
        cout << "2. Print Above Average Incomes" << endl;
        cout << "3. Print Below Poverty Households" << endl;
        cout << "4. Print All Sorted by Income" << endl;
        cout << "5. Print median Income" <<  endl;
        cout << "6. exit the program " << endl;
        cout << " Please Enter the Number Of Your Choice :  ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                printAllData(households, lngth, i);
                break;
            case 2:
                printAboveAverage(households, lngth, i);
                break;
            case 3:
                printBelowPoverty(households, lngth, i);
                break;
            case 4:
                printallsortedincome(households, lngth, i, j);
                break;
            case 5:
                printmedian(households, lngth, i, j);
                break;
            case 6:
                cout<<"goodbye"<< endl;
                tru = false;
                break;

            default:
                cout << "Wrong Input Please Try Again . ";

        }
    }
    
    return 0;
}

void printAllData(household households[], int lngth, int i) {
    cout << endl << " CODE\tINCOME\tMEMBERS" << endl;
    cout << " _____\t______\t_______\n" << endl;
    for( i=0; i < 16; i++) {
        cout<<i+1 << ':' << households[i].idcode<<"\t"<< households[i].annualincome<<"\t" << households[i].members<<endl;
    }
};

void printAboveAverage(household households[], int lngth, int i) {
    float averageIncome = 0;

    for( i=0; i < lngth - 10; i++) {
        averageIncome += households[i].annualincome;
    }
    averageIncome = averageIncome / lngth - 10;

    cout << endl << " CODE\tINCOME\tMEMBERS" << endl;
    cout << " _____\t______\t_______\n" << endl;
    for( i=0; i < lngth - 10; i++) {
        if(households[i].annualincome >= averageIncome)
            cout << i+1 << ':'<< households[i].idcode<<"\t"<< households[i].annualincome<<"\t" << households[i].members<<endl;
    }

};

void printBelowPoverty(household households[], int lngth, int i) {

    cout << endl << " CODE\tINCOME\tMEMBERS" << endl;
    cout << " _____\t______\t_______\n" << endl;
    for( i=0; i < lngth - 10; i++) {
        float P = 8000.00 + 500.00 * ( households[i]. members - 2);
        if(households[i].annualincome < P)
            cout <<i+1 << ':'<<households[i].idcode<<"\t"<< households[i].annualincome<<"\t" << households[i].members<<endl;
    }

};

void printallsortedincome(household households[], int lngth, int i , int j) {
    for( i = 0; i < lngth - 10; i++) {
        for( j=i+1; j < 16; j++) {
            if(households[i].annualincome > households[j].annualincome) {
                household temp;
                temp = households[i];
                households[i] = households[j];
                households[j] = temp;
            }

        }
    }

    cout << endl << " CODE\tINCOME\tMEMBERS" << endl;
    cout << " _____\t______\t_______\n" << endl;
    for( i = 0; i < lngth - 10; i++) {
        cout <<i+1 << ':'<<households[i].idcode<<"\t"<< households[i].annualincome<<"\t" << households[i].members<<endl;
    }

};

void printmedian(household households[], int lngth, int i, int j) {
    float median;
    for( i = 0; i < lngth - 10; i++) {
        for(int j=i+1; j < lngth - 10; j++) {
            if(households[i].annualincome > households[j].annualincome) {
                household temp;
                temp = households[i];
                households[i] = households[j];
                households[j] = temp;
            }

        }
    }
    if (lngth % 2 == 0) {
        median = (households[(lngth / 2) - 1].annualincome + households[lngth / 2].annualincome)/2;
    }
    else {
        int aprxLngth = lngth + 1;
        median = (households[(aprxLngth / 2) - 1].annualincome + households[aprxLngth / 2].annualincome)/2;
    }
    
    cout<<"Median: " << median;
}