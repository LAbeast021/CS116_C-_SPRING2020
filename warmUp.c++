#include <iostream>
#include <string>
using namespace std;


// int main ( # Warm Up 3/ 2/ 2020) {
//     int number;
//     cout << "Please Enter a Number : ";
//     cin  >> number;
//     if(100 <= number && number <= 199 )
//         cout << " The Book is in Basement ";
//     else if (200 <= number && number <= 500 || number > 900)
//         cout << " The Book is in the Main Floor ";   
//     else if (501 <= number && number <= 900 && !(700 <= number )&& !(number <= 750))
//         cout << " The Book is in Upper Floor ";
//     else if (700 <= number && number <= 750)
//         cout << " The Book is in Archives ";
//     return(0);
// };
// int main () {
//     int age;
//     string rating = "G";
//     // && Will Always go Before the || so be careful :);
//     if ((age <= 12 || age >= 65) && rating == "G")
//         cout << " whoooray Discount ;)  ";
// };

// int main () {
//     int counter = 0;
//     int code;
//     cout << "sag";
//     cin >> code;
//     switch (code)
//     {
//     case  1:
//         counter+=1;
//         break;
    
//     case  2:
//     case  4:
//         counter+=2;
//         break;
//     case 3:
//         counter +=3;
//     default:
//      counter = 10;
//      break;        
//     }
//     cout << counter;
// }
// int main(){
//     char pkg;
//     double hours;
//     if (pkg == 'A' || pkg == 'a') {
//         if(hours <= 10){
//             cout << "Less Than 10  ";
//         }
//         else if ( hours <= 200){
//             cout << " Between 10 and 200 ";
//         }
//         else {
//             cout << " greater than 200";
//         }
//     }
// };
int main(){
    int day =1;
    double pay = .01 , total = 0.01;
    do {
        cout << day << "/t" << pay << "/t" << total << endl;
        day++;
        pay = 2 * pay;
        total += pay;
    }
    while (day <= 3);
    cout << total << endl ;
    return 0; 
};
// cin.clear(); cin.ignore(200,'\n')