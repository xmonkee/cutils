#include <stdio.h>
#include "util.h"
#define MAXLEN 20000

int main(void) {
    char line[MAXLEN];
    int n;
    while((n = getline1(line, MAXLEN)) > 0) {
        if (n > 80) {
            printf("%s", line);
        }
    }
}
