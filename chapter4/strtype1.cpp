#include <iostream>
#include <string.h>
using namespace std;
int main() { 
    char charr1[20];
    char charr2[20]="jaguar";
    string str1;
    string str2 = "pantner";

    cout << "Enter a kind of feline: ";
    cin >> charr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;
    cout << "Here are some felines :\n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 <<endl;
    cout << "The third letter in " << charr2 << " is " 
         << charr2[2] << endl;

    cout << "The third letter in "<< str2 <<" is "
         << str2[2] <<endl;

    return 0;
}