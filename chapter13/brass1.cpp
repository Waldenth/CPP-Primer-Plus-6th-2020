#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass(const string& s, long an, double bal) {
    fullname = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullname << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullname << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balacnce: $" << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r)
    : Brass(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt <= bal) {  //正常取款,取款额<=存款额
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {  //贷款, 取款额<=存款额+最大贷款限度-现欠款
        double advacnce = amt - bal;               //贷款量
        owesBank += advacnce * (1.0 + rate);
        cout << "Bank adcvance: $" << advacnce << endl;
        cout << "Finance charge: $" << advacnce * rate << endl;
        Deposit(advacnce);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceed. Transaction cancelled.\n";
    }
}

format setFormat() {
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}