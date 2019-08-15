#include "dcl.h"

#define check(e) if(e != 0) return -1

int parse_expr(char *in, int ptr);
int parse_star(char *in, int ptr);
int parse_non_star(char *in, int ptr);
int parse_rhs(char *in, int ptr);

int parse(char *in, int ptr) {
    char out[100];
    tok t;
    ptr = get_tok(out, &t, in, ptr);

    if (t != Var) {
        printf("Missing base type");
        return -1;
    }

    check(parse_expr(in, ptr));
    return 0;
}

int parse_expr(char *in, int ptr) {
    int ptr_orig = ptr;
    char out[100];
    tok t;
    ptr = get_tok(out, &t, in, ptr);

    if (t == Chr && out[0] == '*') {
        while (t == Chr && out[0] == '*') {
            ptr = get_tok(out, &t, in, ptr);
        }

    }

    check(parse_non_star(in, ptr));
    check(parse_star(in, ptr == ptr_orig ? ));

    return 0;
}

int parse_star(char *in, int ptr) {
    char out[100];
    tok t;
    ptr = get_tok(out, &t, in, ptr);
    while (t == Chr && out[0] == '*') {
        printf(" pointer to");
        ptr = get_tok(out, &t, in, ptr);
    }
    return 0;
}

int parse_non_star(char *in, int ptr) {
    int ptr_orig = ptr;

    char out[100];
    tok t;
    ptr=get_tok(out, &t, in, ptr);

    if (t == Var) {
        printf("%s is", out);
        check(parse_rhs(in, ptr));
        return 0;
    }


    if (t == Chr && out[0] == '(') {
        int p_count;
        for(p_count = 1; p_count > 0;) {
            if (t == Chr && out[0] == '(')
                p_count++;
            if (t == Chr && out[0] == ')')
                p_count--;
            if (t == Eof) {
                printf("Unbalanced parens\n");
                return -1;
            }
            ptr = get_tok(out, &t, in, ptr);
        }

        check(parse_expr(in, ptr_orig));
        check(parse_rhs(in, ptr));
        return 0;
    }

    printf("Malformed expr\n");
    return -1;
}

int parse_rhs(char *in, int ptr) {
    return 0;
}
