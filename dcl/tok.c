#include "dcl.h"

int get_tok(char *out, tok *t, char *in, int ptr) {
    // Skip whitespace
    while(isspace(c = in[ptr]))
        ptr++;

    //EOF
    if(in[ptr] == '\0') {
        *t = Eof;
        return ptr;
    }

    // Var
    int i;
    for (i = 0; isalpha(in[ptr]); out[i++] = in[ptr++])
        ;
    if (i > 0) {
        out[i] = '\0';
        *t = Var;
        return ptr;
    }

    // Char
    out[0] = c;
    out[1] = '\0';
    *t = Chr;
    return ++ptr;
}
