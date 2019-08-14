#include <ctype.h>
#include <stdio.h>

void trim(char *s, int *i, int *j){
    while(isspace(s[*i]))
        ++(*i);
    while(isspace(s[*j]))
        --(*j);
}

int main(void) {
    int a=0, b=4;
    char s[] = " hel ";
    trim(s, &a, &b);
    printf("%d %d\n", a, b);
}
