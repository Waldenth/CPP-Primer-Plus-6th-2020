#include <iostream>
#include <fstream>
#include <cstdlib>
const int SIZE = 50;

using namespace std;

int main() { 
    char fileName[SIZE];
    ifstream inFile;
    cout << "Enter name of data file: ";
    cin.getline(fileName, SIZE);
    inFile.open(fileName);
    if(!inFile.is_open()){
        cout << "Could not open the file " << fileName << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    string data;
    char buffer;
    double sum = 0.0;
    int count = 0;
    while(inFile.good()){
        count++;
        buffer=inFile.get();
        data += buffer;
        //cout << data << endl;
    }
    if(inFile.eof()){
        cout << "End of file reached.\n";
    }else if(inFile.fail())
        cout << "Input terminated by data mismatch" << endl;
    else{
        cout << "Input terminated for unknown reason" << endl;
    }
    if(count==0)
        cout << "No data processed.\n";
    else{
        cout << data << endl;
    }
    inFile.close();
    return 0;
}