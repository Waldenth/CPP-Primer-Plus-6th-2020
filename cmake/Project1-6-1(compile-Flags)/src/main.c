#include <stdlib.h>

#include "Graph.h"

int main(int argc, char *argv[]) {
    MatGraph G;
    InitGraph(&G);
    Prim(G, 0);
    system("PAUSE");
    return 0;
}