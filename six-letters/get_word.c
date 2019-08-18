#include "six-letters.h"

int get_word(char *word)
{
    char c;
    int i = 0;

    while (!isalpha(c = getch()) && c != EOF)
        ;
    if (c == EOF)
    {
        word[i] = '\0';
        return EOF;
    }

    word[i++] = c;
    while (isalnum(c = getch()) && i < MAXLEN)
        word[i++] = c;
    word[i] = '\0';
    ungetch(c);
    return i;
}