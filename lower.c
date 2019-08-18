//Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.
#include <stdio.h>

void lower(char *s) {
    for(; s[0] != '\0'; s++) {
        s[0] = s[0] >= 'A' && s[0] <= 'Z' ? s[0] - 'A' + 'a' : s[0];
    }
}

int main(void) {
    char s[] = "HEllO";
    lower(s);
    printf("%s\n", s);
}
