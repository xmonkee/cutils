#include "dcl.h"

int main(void) {
    char s[] = "int a";
    return parse(s, 0);
    /*strcpy(s, "int **(mvar)[]()");*/
    /*return parse(s, 0);*/
}
