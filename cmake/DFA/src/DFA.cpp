#include "DFA.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <iterator>

void DFA::readFile(const char* path) {
    std::ifstream in(path, std::ios::in);
    std::istreambuf_iterator<char> beg(in), end;
    std::string strdata(beg, end);
    // DFA::buffer = new std::string(beg, end);
    in.close();
    std::cout << strdata << std::endl;
    strcpy(input, strdata.c_str());
    std::cout << "read file completed" << std::endl;
}

bool DFA::parser() {
    // char input[] = "/**Hello World !** /";
    std::cout << "start parser" << std::endl;
    int curPointer = 0;
    State state = START;
    while (state == START || state == STATE2 || state == STATE3 || state == STATE4) {
        switch (state) {
            case START:
                switch (input[curPointer]) {
                    case '/':
                        state = STATE2;
                        curPointer++;
                        break;
                    default:
                        state == ERROR;
                }
                break;
            case STATE2:
                switch (input[curPointer]) {
                    case '*':
                        state = STATE3;
                        curPointer++;
                        break;
                    default:
                        state = ERROR;
                        break;
                }
                break;
            case STATE3:
                switch (input[curPointer]) {
                    case '*':
                        state = STATE4;
                        curPointer++;
                        break;
                    default:
                        curPointer++;
                        break;
                }
                break;
            case STATE4:
                switch (input[curPointer]) {
                    case '/':
                        state = ACCEPT;
                        curPointer++;
                        break;
                    case '*':
                        curPointer++;
                        break;
                    default:
                        state = STATE3;
                        curPointer++;
                        break;
                }
                break;
        }
    }
    std::cout << "END" << std::endl;
    if (state == ACCEPT) {
        return true;
    }
    return false;
}