#include <iostream>
#include "DFA.h"
int main() {
    DFA dfa = DFA();
    dfa.readFile("../test.txt");
    std::cout << dfa.parser() << std::endl;
    return 0;
}