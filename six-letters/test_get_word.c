#include "six-letters.h"

int main(void)
{
    char word[MAXLEN + 1];
    int i;
    while ((i = get_word(word)) != EOF)
    {
        printf("%s:%d\n", word, i);
    }
}