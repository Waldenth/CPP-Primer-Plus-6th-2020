#include <iostream>
#define ZERO 0;
#include <climits>
int main() { 
    using namespace std;
    short sam = SHRT_MAX;
    unsigned short sue = sam;
    cout << "Sam has " << sam << "dollars and Sue has " << sue;
    cout << " dollars deposited." << endl
         << "Add $1 to each account." << endl << "Now";
    sam++;
    sue++;
    cout << "Sam has " << sam << "dollars and Sue has " << sue;
    cout << " dollars deposited.\n Poor Sam!" << endl;
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl
         << "Take $1 form each account." << endl << "Now";

    sam--;
    sue--;
    cout << "Sam has " << sam << "dollars and Sue has " << sue;
    cout << " dollars deposited.\n Lucky Sue!" << endl;

    system("PAUSE");
    return 0;
}