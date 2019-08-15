#include "dcl.h"

int main(void) {
    char s[] = "**(mvar)[]()";
    char o[100] = "mayank";
    tok t;
    int ptr = 0;
    while(ptr = (get_tok(o, &t, s, ptr)), t != Eof){
        printf("%d %s\n", t, o);
    }
    printf("%d\n", t);
}
