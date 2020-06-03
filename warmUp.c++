
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
// int main(){
    // int day =1;
    // double pay = .01 , total = 0.01;
    // do {
    //     cout << day << "/t" << pay << "/t" << total << endl;
    //     day++;
    //     pay = 2 * pay;
    //     total += pay;
    // }
    // while (day <= 3);
    // cout << total << endl ;
//      int   A = 3,    B = 2,     C = 5,  D = 15;

//                          if  ((A > B ) &&  A * B  <  C  ||  A * C  >=  D)

//                               cout << "true";

//                      else   cout << "false";
//     return 0; 
// };
// cin.clear(); cin.ignore(200,'\n')
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

/* to read data from user and load to array */
// int read(int employee_id[],float pay[])
// {
//    fstream fp;
//    fp.open("PayRates.txt");
//    int i = 0;
//    while(!fp.eof())
//    {
//        fp>>employee_id[i]>>pay[i];
//        i++;  
//    }
//    return i;
// }

// /* to search and display the payrate of the given employee id */
// void Search_display(int employee_id[],float pay[],float emp_id,int size)
// {
//    int flag = 0;
//    for(int i=0;i<size;i++)
//    {
//        if(employee_id[i]==emp_id)
//        {
//            cout<<"Employee : "<<employee_id[i]<<" Payrate : "<<pay[i]<<endl;
//            flag = 1;
//            break;
//        }
//    }
//    if(flag==0)
//    {
//        cout<<"Not found\n";
//    }
// }

// /* To compute and output average of pay rate */
// void avg(float pay[],int size)
// {
//    float sum;
//    for(int i = 0;i<size;i++)
//    {
//        sum+=pay[i];
//    }
//    cout<<"\nAverage = "<<sum/size;
// }

// /* Driver Function */
int main()
{
    int Big = 4, Small = 0;
    cout << Big -- << "  " << Small ++;
            if (--Big == ++ Small)
                        cout << Big << " Equal  " << Small << endl;
            else  cout <<  Big << " Not Equal  " << Small << endl;
}
// int employee_id[25];
//    float pay [25];
//    int size = read(employee_id,pay);
//    char choice = 'Y';
//    while(choice == 'Y')
//    {
//        cout<<"Enter Employee Id to search for : ";
//        int emp_id;
//        cin>>emp_id;
//        Search_display(employee_id,pay,emp_id,size);
//        cout<<"\nWant to Search More : ";
//        cin>>choice;
//    }
//    avg(pay,size);