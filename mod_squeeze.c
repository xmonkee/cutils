#include <stdio.h>

void squeeze(char *s1, char *s2) {
    // squeeze(s1, s2) deletes all chars from s1 present in s2
    int i, j, k;
    char c, d;
    i = k = 0;

    while((c = s1[i++]) != '\0') {
        for(j=0; (d = s2[j]) != '\0' && d != c; j++);
        if(d != c) s1[k++] = c;
    }
    s1[k] = '\0';
}

void squeeze(char *s1, char *s2) {
    // squeeze(s1, s2) deletes all chars from s1 present in s2
    int i, j, k;
    char c, d;
    i = k = 0;

    while((c = s1[i++]) != '\0') {
        for(j=0; (d = s2[j]) != '\0' && d != c; j++);
        if(d != c) s1[k++] = c;
    }
    s1[k] = '\0';
}

int main(void) {
    char s1[] = "hello";
    char s2[] = "lohe";
    squeeze( s1, s2);
    printf("%s\n", s1);
}
