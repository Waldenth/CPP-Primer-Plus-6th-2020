#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *pValue;
    while (argc > 1) {
        if (strcmp(argv[1], "-help") == 0) {
            printf("Usage: love [options]\n");
            printf("       -a value        specify value of a\n");
            printf("       -b value        specify value of b\n");
            printf("       -c value        specify value of c\n");
            break;
        } else if ((strcmp(argv[1], "-a") == 0) && argc > 2) {
            pValue = argv[2];
            printf("The value of a is %s\n", pValue);
            argv += 2;
            argc -= 2;
        } else if ((strcmp(argv[1], "-b") == 0) && argc > 2) {
            pValue = argv[2];
            printf("The value of b is %s\n", pValue);
            argv += 2;
            argc -= 2;
        } else if ((strcmp(argv[1], "-c") == 0) && argc > 2) {
            pValue = argv[2];
            printf("The value of c is %s\n", pValue);
            argv += 2;
            argc -= 2;
        } else {
            break;
        }
    }
    return 0;
}