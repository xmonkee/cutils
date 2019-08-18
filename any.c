//any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2

#include "assert.h"
#include <stdio.h>

int any(char *s1, char *s2) {
    int i, j;
    char c, d;
    for(i = 0; (c = s1[i]) != '\0'; i++) {
        for(j = 0; (d = s2[j]) != '\0' && d != c; j++);
        if (d == c) return i;
    }
    return -1;
}

int main(void) {
    assert(any("hello", "ola") == 2, "hello");
    assert(any("hello", "bruh") == 0, "bruh");
    assert(any("hello", "sick") == -1, "sick");
}
