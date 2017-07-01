#include "test.h"

static int nums = 0;

void zassert(int condition, char* msg, int line, char* file) {
    if (!condition) {
        fail(msg, line, file);
    }
    nums++;
}

void fail(const char* msg, int line, char* file) {
    printf("\n");
    printf("Test Failure on %i in %s\n", line, file);
    printf("\t%s\n\n", msg);
    zfinish(1, file);
}

void zfinish(int e_code, char* file) {
    if (e_code != 0) {
        printf("%i tests passed in %s before exiting\n", nums, file);
    } else {
        printf("%i tests passed in %s\n", nums, file);
    }
    
    exit(e_code);
}