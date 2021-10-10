#include <iostream>
int main() {
    using namespace std;
    int rats = 101;

    int& rodents = rats;
    cout << "rats=" << rats << ",rodents=" << rodents << endl;
    rodents++;
    cout << "rats=" << rats << ",rodents=" << rodents << endl;
}