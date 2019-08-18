#include "six-letters.h"

static char charbuf[100];
static int charptr;

char getch()
{
    if (charptr)
    {
        return charbuf[--charptr];
    }
    return getchar();
}

void ungetch(char c)
{
    charbuf[charptr++] = c;
}

char peekch()
{
    char c = getch();
    ungetch(c);
    return c;
}
