#include <iostream>
#define DWORD unsigned long
using namespace std;

bool fsm(string input, DWORD *output);

int main() {
    DWORD output[6];
    fsm("   2020   -   02 ----- 08 --- 14:   00 :  23   ", output);
    cout << "finished\n";
    for (int i = 0; i < 6;i++){
        cout << output[i] << endl;
    }
    return 0;
}

void test() {}

bool fsm(string input, DWORD *output) {
    enum states { 
         before,inside
    } state;
    state = before;
    int curIndex = 0;//for read input char
    int curOutputIndex = 0;//for write output data
    int curTmpIndex=0;//for tmpStr
    char tmpStr[]="xxxxx";
    char curGetChar;
    while(curIndex<input.length()){
        curGetChar = input.at(curIndex++);
        switch (state)
        {
            case before:
                switch (curGetChar)
                {
                    case ' ':
                    case '-':
                    case ':':
                        break;
                    default:
                        tmpStr[curTmpIndex++] = curGetChar;
                        state = inside;
                        break;
                }
                break;
            case inside:
                switch (curGetChar)
                {
                    case ' ':
                    case '-':
                    case ':':
                        tmpStr[curTmpIndex] = '\0';
                        output[curOutputIndex++] = atoi(tmpStr);
                        curTmpIndex = 0;
                        state = before;
                        break;
                    default:
                        tmpStr[curTmpIndex++] = curGetChar;
                        if(curIndex==input.length()){
                            tmpStr[curTmpIndex] = '\0';
                            output[curOutputIndex++] = atoi(tmpStr);
                            curTmpIndex = 0;
                            state = before;
                        }
                        break;
                }
                break;

            default:
                break;
        }
    }
    return true;
}
