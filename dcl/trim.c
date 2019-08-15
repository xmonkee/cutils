#include "dcl.h"

void trim(char *s, int *i, int *j){
    while(isspace(s[*i]))
        ++(*i);
    while(isspace(s[*j]))
        --(*j);
}

