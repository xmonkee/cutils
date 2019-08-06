#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void reverse(char *s, int n) {
    char temp;
    int i = 0;
    int j = n - 1;
    for(;i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}


bool strcmp1(char *s1, char *s2) {
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') i++;
    return (bool) (s1[i] == '\0' && s2[i] == '\0');
}


size_t getline1(char *line, size_t maxlen) {
    char c;
    size_t i = 0;
    while(i < maxlen && (c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        i++;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
