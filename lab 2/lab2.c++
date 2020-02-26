//  Hesampour Kiarash
// Feb / 26 / 2020 , Lab #2
//  Section : 25978 , Mon,Wed 8:55 - 10:55

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    cout << fixed << showpoint << setprecision(2);
    string name;
    double hoursOfLabor, taxAmount, costOfPartAndSupplies, costOfLabor,totalAmount;
    const  double tax_rate = 0.09;
    const  double labor_charge_per_hour = 35;

    cout << " Please Enter Your Name : ";
    cin  >> name;
    cout << " Enter The Amount of Time that Labor Worked : ";
    cin  >> hoursOfLabor;
    cout << " Enter The Cost Of Parts And Supplies : ";
    cin  >> costOfPartAndSupplies;

    costOfLabor = hoursOfLabor * labor_charge_per_hour;
    totalAmount = costOfLabor + costOfPartAndSupplies;
    taxAmount   = costOfPartAndSupplies * tax_rate;
    totalAmount = totalAmount + taxAmount;

    cout 
     << " Customer Name : "  << setw(20) << name  << endl
     << " Hours of labor : " << setw(19) << hoursOfLabor  << endl
     << " Cost for labor: "  << setw(20) << costOfLabor  << endl
     << " Parts and Supplies : " << setw(15) << costOfPartAndSupplies  << endl
     << " Tax : " << setw(30) << taxAmount  << endl
     << " Total Amount Due : " << setw(17) << totalAmount  << endl;

    return 0;

};

/* 
 Customer Name :               Kiarash
 Hours of labor :                 4.50
 Cost for labor:                157.50
 Parts and Supplies :            97.00
 Tax :                            8.73
 Total Amount Due :             263.23
*/
/* 
 Customer Name :                  Lee
 Hours of labor :                3.00
 Cost for labor:               105.00
 Parts and Supplies :            0.00
 Tax :                           0.00
 Total Amount Due :            105.00
*/








































/*
    // ///// VARIABLES ///////////////
    step1: Declare  Name(string), hours_of_labor(double), cost part and supplies(double), and total amount due(double);
    step2: set the constant value for the tax_rate (0.09%) and labor_charge_per_hour(35);
        string name:
        double hoursOfLabor;
        double tax_amount;
        double costOfPartAndSupplies;
        const double tax_rate = 0.09;
        const double labor_charge_per_hour = 35;
    /////// INPUT ////////////////////

    step3: Ask User To Enter the values for the variables (name, Hours of Labor, cost part and supplies);
    step4: create cin for each of those variables;
        cout << "enter your name";
        cin >> name;
        cout << "enter the hours labor worked";
        cin >> hoursOfLabor;
        cout << "enter the cost of supplies";
        cin >> costOfPartAndSupplies;

    ////// PROCCESSING //// /////////

    step5: calculate the price of labor by multiplying the Hours of Labor(double) by labor charge per hour(double) and set it to the cost of Labor ;
         cost_of_Labor = labor_charge_per_hour * hoursOfLabor;
    step6: Add the cost part and supplies(double) to price of labor and set it to total_amount_due;
         total_amount_due = costOfPartAndSupplies + cost_of_Labor
    step7: calculate the tax by multiplying tax rate by total cost of labor and cost part and supplies(double);
    tax_amount = total_amount_due * tax_rate
    step8: set the result of adding tax + cost of labor and cost part and supplies(double) to the total amount due;
     total_amount_due = total_amount_due + tax_amount

    // ////// OUTPUT //////////////////
    output the name, hoursOfLabor, cost_of_Labor, costOfPartAndSupplies, tax_amount, total_amount_due;
    step9: cout << name;
    step9: cout << hoursOfLabor; 
    step9: cout << cost_of_Labor, 
    step9: cout << costOfPartAndSupplies;
    step9: cout << tax_amount;
    step9: cout << total_amount_due; 


*/