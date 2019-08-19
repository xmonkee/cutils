#include "hash-table.h"
#include <string.h>
#include <stdlib.h>

#define NULLCHECK(e) \
    if ((e) == NULL) \
        return NULL;

void free_node(node *n);
int hash(char *s);
node *create_node(char *key, char *val);

table init_table(void)
{
    table t = malloc(sizeof(node *) * HASHSIZE);
    for (int i = 0; i < HASHSIZE; i++)
        t[i] = NULL;
    return t;
}

void free_table(table t)
{
    node *n, *m;
    for (int i = 0; i < HASHSIZE; i++)
    {
        for (n = t[i]; n != NULL;)
        {
            m = n->next;
            free_node(n);
            n = m;
        }
    }
    free(t);
}

void free_node(node *n)
{
    free(n->key);
    free(n->val);
    free(n);
}

node *lookup(table t, char *key)
{
    node *n;
    for (n = t[hash(key)]; n != NULL; n = n->next)
        if (strcmp(key, n->key) == 0)
            return n;
    return NULL;
}

node *insert(table t, char *key, char *val)
{
    node *n;
    if ((n = lookup(t, key)) == NULL)
    {
        NULLCHECK(n = create_node(key, val));
        int h = hash(key);
        n->next = t[h];
        t[h] = n;
    }
    else
    {
        free(n->val);
        NULLCHECK(n->val = strdup(val));
    }
    return n;
}

int hash(char *key)
{
    int sum = 0;
    for (; *key != '\0'; key++)
        sum = sum * 31 + *key;
    return sum % HASHSIZE;
}

node *create_node(char *key, char *val)
{
    node *n;
    NULLCHECK(n = malloc(sizeof(node)));
    NULLCHECK(n->key = strdup(key));
    NULLCHECK(n->val = strdup(val));
    n->next = NULL;
    return n;
}
