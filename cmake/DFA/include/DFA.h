#ifndef _DFA_H_
#define _DFA_H_
#include <string>
enum State { START = 1, STATE2, STATE3, STATE4, ACCEPT, ERROR };

class DFA {
   private:
    char input[1000];

   public:
    void readFile(const char* path);
    bool parser();
};

#endif