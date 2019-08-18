#include "dcl.h"

#define check(e) \
    if (e != 0)  \
    return -1

int parse_expr(char *in, int ptr);
int parse_star(char *in, int ptr);
int parse_non_star(char *in, int ptr);
int parse_rhs(char *in, int ptr);

int parse(char *in, int ptr)
{
    char out[100];
    tok t;
    ptr = get_tok(out, &t, in, ptr);

    if (t != Var)
    {
        printf("Missing base type");
        return -1;
    }

    check(parse_expr(in, ptr));
    printf(" %s\n", out);
    return 0;
}

int parse_expr(char *in, int ptr)
{
    // printf("\nparse_expr: %s\n", in + ptr);
    int ptr_orig = ptr;
    int ptr_prv = ptr;

    char out[100];
    tok t;
    ptr = get_tok(out, &t, in, ptr);

    if (t == Chr && out[0] == '*')
    {
        while (t == Chr && out[0] == '*')
        {
            ptr_prv = ptr;
            ptr = get_tok(out, &t, in, ptr);
        }
    }

    check(parse_non_star(in, ptr_prv));
    check(parse_star(in, ptr_orig));

    return 0;
}

int parse_star(char *in, int ptr)
{
    // printf("\nparse_star: %s\n", in + ptr);
    char out[100];
    tok t;
    ptr = get_tok(out, &t, in, ptr);
    while (t == Chr && out[0] == '*')
    {
        printf(" pointer to");
        ptr = get_tok(out, &t, in, ptr);
    }
    return 0;
}

int parse_non_star(char *in, int ptr)
{
    // printf("\nparse_non_star: %s\n", in + ptr);
    int ptr_expr = ptr;

    char out[100];
    tok t;

    ptr = get_tok(out, &t, in, ptr);

    if (t == Var)
    {
        printf("%s is", out);
        check(parse_rhs(in, ptr));
        return 0;
    }

    if (t == Chr && out[0] == '(')
    {
        ptr_expr = ptr;
        int p_count;
        for (p_count = 1; p_count > 0;)
        {
            ptr = get_tok(out, &t, in, ptr);
            if (t == Chr && out[0] == '(')
                p_count++;
            if (t == Chr && out[0] == ')')
                p_count--;
            if (t == Eof)
            {
                printf("Unbalanced parens\n");
                return -1;
            }
        }

        check(parse_expr(in, ptr_expr));
        check(parse_rhs(in, ptr));
        return 0;
    }

    printf("Malformed expr\n");
    return -1;
}

int parse_rhs(char *in, int ptr)
{
    // printf("\nparse_rhs: %s\n", in + ptr);
    tok t;
    char out[100];
    ptr = get_tok(out, &t, in, ptr);
    int parens = 0;
    int brackets = 0;
    while (t != Eof && parens >= 0)
    {
        if (t == Chr && out[0] == '(')
            parens++;
        if (t == Chr && out[0] == ')')
        {
            if (--parens >= 0)
                printf(" function returning");
        }
        if (t == Chr && out[0] == '[')
            brackets++;
        if (t == Chr && out[0] == ']')
        {
            brackets--;
            printf(" array of");
        }
        ptr = get_tok(out, &t, in, ptr);
    }
    if (parens < -1 || parens > 0 || brackets != 0)
    {
        printf("\nUnbalanced parens\n");
        return -1;
    }
    return 0;
}
