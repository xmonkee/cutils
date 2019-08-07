#include "assert.h"
#include <stdio.h>

int assert(bool cond, char * msg) {
    extern int errors;
    if(!cond) {
        printf("Failed: %s\n", msg);
        errors += 1;
        return 1;
    }
    return 0;
}

