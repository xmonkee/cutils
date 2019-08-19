/* 
COMPILE WITH -lreadline
you'll also need to install libreadline-dev
*/

#include "hash-table.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int _main(table t)
{

    char *line, *instr, *key, *val;
    node *n;
    while ((line = readline("> ")) != NULL)
    {
        instr = strtok(line, " ");
        if (instr == NULL)
            return 0;
        if (strcmp(instr, "i") == 0)
        {
            key = strtok(NULL, " ");
            val = strtok(NULL, " ");
            if (key == NULL || val == NULL)
                return 1;
            if (insert(t, key, val) == NULL)
                return -1;
        }
        else if (strcmp(instr, "l") == 0)
        {
            if ((key = strtok(NULL, " ")) == NULL)
                return 1;
            if ((n = lookup(t, key)) == NULL)
            {
                printf("Not found \n");
            }
            else
            {
                printf("%s\n", n->val);
            }
        }
        else
        {
            return 1;
        }
        free(line);
    }
    return 0;
}

int main(void)
{
    int m;
    table t = init_table();
    while ((m = _main(t)) == 1)
    {
        printf("Usage error\n"
               "Each line should be either \n"
               "\t'i <key> <val>' for insert or \n"
               "\t'l <key>' for lookup\n");
    }

    if (m == -1)
    {
        printf("Memory error\n");
    }
    free_table(t);
    return m;
}