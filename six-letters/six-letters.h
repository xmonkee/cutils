#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 100

struct tree
{
    int count;
    char *word;
    struct tree *sub;
    struct tree *left;
    struct tree *right;
};

char getch(void);
char peekch(void);
void ungetch(char c);

int get_word(char *word);
