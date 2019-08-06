/* Reverse the input line by line */
#include <stdio.h>
#include <stdbool.h>
#include "util.h"

#define MAXLEN 100

int main(void) {
    // test_reverse();
    size_t n;
    char line[MAXLEN+1];
    while((n = getline1(line, MAXLEN)) > 0) {
        // n-1 to preserve the newline
        reverse(line, n-1);
        printf("%s", line);
    }
}
