/* int **(*m[])() -> (((((m) is array of) pointer to) function returning) pointer to pointer to int) */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char *s, int *i, int *j);

typedef enum {
    Var,
    Chr,
    Eof,
} tok;

int get_tok(char *out, tok *t, char *in, int ptr);

//parse(base_type expr) -> parse_expr(expr) + base_type
//parse_expr(**inner[]) -> parse_non_star(inner[]) + parse_star(**)
//parse_non_ptr(var[]) -> var + parse_rhs([])
//parse_non_ptr((expr)[]) -> parse_expr(expr) + parse_rhs([])
//parse_rhs([]) -> []

int parse(char *in, int ptr);
