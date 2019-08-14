/*
char (*(*x())[])()

x: function returning pointer to array of pointer to function returning char

char (*(*x[3])())[5]

x: array(3) of pointer to function returning pointer to array(5) of char

char (*(*x[][3]())())[5]

base_type expr
char expr
char expr[5]
char (expr)[5]
char (*expr())[5]
char (*(expr)())[5]
char (*(*x[][3]())())[5]

declare x as array of array 3 of function returning pointer to function returning pointer to array 5 of char
*/

#include "links.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *dcl_expr(char *dcl, int i);
char *space = " ";


int dcl(char dcl[], chain *c) {
    // decl :: base_type expr
    int i = 0;
    char *base_type = malloc(20);


    // split base_type and expr

    // Get rid of space
    while (isspace(dcl[i]))
        i++;

    // Copy base type to base_type
    int j = 0;
    while (isalpha(dcl[i]))
        base_type[j++] = dcl[i++];

    base_type[j] = '\0';
    link_s_after(c, base_type);

    // get rid of space

    char *expr_result = dcl_expr(dcl, i);
    link_s_before(c, expr_result);

    /*result = strcat(result, " ");*/
    return i;
}


char *dcl_expr(char dcl[], int i) {
    /*printf("called %s\n", dcl);*/
    char *result = malloc(1000);
    char *left_result = malloc(1000);
    char *temp_result;
    result[0] = '\0';
    left_result[0] = '\0';


    while(isspace(dcl[i]))
        i++;

    // Check left modifiers (*)
    while(dcl[i] == '*') {
        strcat(result, " pointer to");
        i++;
    }

    // Insert expr
    i = dcl_expr(c, dcl, i);

    // Insert right mods
    while(isspace(dcl[i]))
        i++;

    // Insert Left Mods
    link_s_after(c, result);
    return i;

    // check if var
    int j = 0;
    while(isalpha(dcl[i])) {
        // copy variable name
        result[j++] = dcl[i++];
    }
    if(j > 0) {
        result[j] = '\0';
        strcat(result, " is");
        /*printf("returning %s\n", result);*/
        return result;
    }

    // Check left modifiers (*)
    while(dcl[i] == '*') {
        strcat(left_result, " pointer to");
        i++;
    }

    // Check expr
    temp_result = dcl_expr(dcl, i);
    result = strcat(result, temp_result);
    free(temp_result);

    // Right modifiers

    // Order is Right modifier, Expr, Left Modifiers
    result = strcat(result, left_result);
    free(left_result);
    /*printf("returning %s\n", result);*/
    return result;

}

int main(void) {
    char *_inputs[] = {
        "char x",
        "char *x",
        "char **x",
        NULL,
    };
    char **inputs = _inputs;
    for (; *inputs != NULL; inputs++){
        chain *c = malloc(sizeof(c));
        chain_init(c);
        dcl(*inputs, c);
        printf("%-15s: ", *inputs);
        chain_print_all(c);
        chain_free_all(c);
    }
}
