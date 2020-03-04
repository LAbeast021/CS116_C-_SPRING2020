/*  
  Hesampour Kiarash
  Mar / 5 / 2020 , Lab # 3
  Section : 25978 , Mon,Wed 8:55 - 10:55
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
  double userHours, extraPrice, total, userPackagePrice, userAdditionalHours;
  char userPackage;
  double package_A_price = 9.95, package_B_price = 14.95, package_C_price = 19.95;
  double package_A_hour  = 10, package_B_hour  = 20;
  double package_A_extra_hour = 2 ,package_B_extra_hour = 1;

  cout << " Please Enter which package you have purchased ; A, B, or C ?  :  ";
  cin >> userPackage;
  userPackage = toupper(userPackage);
  cout << " Please Enter the hours you used the package : ";
  cin >> userHours;

  if ( (userPackage == 'A' || userPackage == 'B' || userPackage == 'C') && userHours <= 200 ){ 
    if ( userPackage == 'A'){
      if( (userHours - package_A_hour) > 0 )
        extraPrice = ((userHours - package_A_hour) * package_A_extra_hour);
      else extraPrice = 0;
    userPackagePrice = package_A_price;
    userAdditionalHours = package_A_extra_hour;
    total = extraPrice + package_A_price;
    }
    else if ( userPackage == 'B'){
      if( (userHours - package_B_hour) > 0 )
        extraPrice = ((userHours - package_B_hour) * package_B_extra_hour);
      else extraPrice = 0;
    userPackagePrice = package_B_price;
    userAdditionalHours = package_B_extra_hour;
    total = extraPrice + package_B_price;
    }
    else {
      userPackagePrice = package_C_price;
      userAdditionalHours = 0;
      total = package_C_price;
    }
  cout
  << " Customer Package : " << setw(20) << " Package " << userPackage << endl
  << " Hours Used : " << setw(20) << userHours << endl
  << " Package Price : " << setw(20) << userPackagePrice << "/ Month" << endl
  << " Additional Hour Price : " << setw(8) << userAdditionalHours << " Per Hour" << endl
  << " Customer Total Bill : " << setw(14) << total  << endl;
  }
  else if ( userHours > 200) {
    cout << " Hours Entered can not exeed 200 hours. please try again  ";
    main();
  }
  else {
    cout << " Package You Entered does not exist please try again ";
    main();
  }
};
/*
  Please Enter which package you have purchased ; A, B, or C ?  :  a
  Please Enter the hours you used the package : 12
  Customer Package :             Package A
  Hours Used :                   12
  Package Price :                 9.95/ Month
  Additional Hour Price :        2 Per Hour
  Customer Total Bill :          13.95
 */

/*
  Please Enter which package you have purchased ; A, B, or C ?  :  d
  Please Enter the hours you used the package : 10
  Package You Entered does not exist please try again  Please Enter which package you have purchased ; A, B, or C ?  :  c
  Please Enter the hours you used the package : 300
  Hours Entered can not exeed 200 hours. please try again   Please Enter which package you have purchased ; A, B, or C ?  :  
*/





/*
    // /////////// Variables ////////////////// // 
    string package;
    double package_A_Price = 9.95 , package_B_Price = 14.95, package_C_Price = 19.95;
    double package_A_extra_hour = 2 ,package_B_extra_hour = 1;
    double package_A_hour_provided = 10, package_A_hour_provided = 20,
    string userPackage;
    double userHoursUsed;
    double extra_price;
    double total;

    // ////////// INPUT ///////////// // 
    prompt the user to enter what package they purchased and set it to userPackage;
    prompt the user to enter the hours they used the package and set it to userHourUsed

    /////////////// PROCCESSING //// /////////
    first we check if the userHoursUsed is less than 200;
    check if the packages are either A,B, or C;
    subtract userHourUsed by userPackage hour provided if it is positive multiply that number by userpackage extra hour price and set it to extra_price;
    add up the package price and extra charge and set it to total

    // //////////////////// OUTPUT ////////////////// //
    display the user package , hours they used the package , price of each price, the hourly charge and the total amount

*/
