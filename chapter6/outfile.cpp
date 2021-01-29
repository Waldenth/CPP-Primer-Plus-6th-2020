#include <fstream>
#include <iostream>

#define SIZE 50

using namespace std;

int main() {
    char automobile[SIZE];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;
    outFile.open("testFileOutput.txt");

    cout << "Enter the make and model of auto mobile: ";
    cin.getline(automobile, SIZE);

    cout << "Enter the model year:";
    cin >> year;
    cout << "Enter the origianl asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    cout << fixed;//表示用一般的方式输出浮点数
    cout.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();
    return 0;
}