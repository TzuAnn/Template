#include<iostream>
#include<string>
#include"Array.cpp"
using namespace std;
int main()
{
    Array<int> integers1(5);
    Array<int> integers2;
    cout << "Enter 15 int" << endl;
    cin >> integers1 >> integers2;
    cout << "\nAfter input, the Arrays contains: \n"<< "integers1\n"  << integers1 <<"intergers2:\n" << integers2;
    cout << "\nEvaluating: intergers1 != intergers2" << endl;
    
    if ( integers1 != integers2 )
    {
        cout << " not equal "<< endl;
    }
    Array <double> double1(10);
    cout << "\nEnter 10 double" << endl;
    cin >> double1;
    cout << "\n Create double2 initialized with double1: " << endl;
    Array <double> double2(double1);
    cout << "double1: \n"<< double1<< "double2: \n"<< double2;
    cout << "\nEvaluating: double1 == double2 " << endl;
    if ( double1 == double2 )
    {
        cout << "equal d1 d2" << endl;
    }
    cout << "\n\nAssigning 100.01 to double1[5]" << endl;
    double1[5] = 100.01;
    cout << "double1:\n" << double1 << endl;
    double1.swap(11, 0);
    double1.swap(-1, 9);
    cout << "double1[2] " << double1[2] << "  double1[8] " << double1[8] << endl; 
    Array<string> strA(4);
    cout << "\nEnter 4 strings" << endl;
    cin >> strA;
    cout << "strA[1] " << strA[1] << "strA[3] " << strA[3] << endl;
    double1.swap(2, 8);
    cout << "After swapping: strA[3]: " << strA[3] << " strA[1]: " << strA[1] << endl;
    cout << "\nAttempt assign \"abcd\" to strA[5]" << endl;
    strA[5] = "abcd";
    return 0;
}