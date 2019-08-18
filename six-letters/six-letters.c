#include "six-letters.h"

struct tree *add_word(struct tree *t, char *word, int len);
struct tree *add_sub(struct tree *s, char *word, int len);
struct tree *new_tree(void);
char *get_root(char *word);
void print_all(struct tree *t);
void print_sub(struct tree *t);

int main(void)
{
    struct tree *t = NULL;
    char word[MAXLEN];
    int len;
    while ((len = get_word(word)) != EOF)
    {
        // printf("word read: %s: %d\n", word, len);
        if (len >= 6)
            t = add_word(t, word, len);
        // printf("added %s\n", t->word);
    }
    print_all(t);
}

struct tree *add_word(struct tree *t, char *word, int len)
{
    printf("add root: %s\n", word);
    if (t == NULL)
    {
        printf("new root: %s\n", word);
        t = new_tree();
        t->word = get_root(word);
        t->count = 1;
        t->left = NULL;
        t->right = NULL;
        t->sub = NULL;

        t->sub = add_sub(t->sub, word, len);
        return t;
    }
    else
    {
        int comp;
        if ((comp = strncmp(word, t->word, 6)) < 0)
        {
            printf("add root left: %s->%s\n", t->word, word);
            t->left = add_word(t->left, word, len);
        }
        else if (comp > 0)
        {
            printf("add root right: %s->%s\n", t->word, word);
            t->right = add_word(t->right, word, len);
        }
        else
        {
            printf("found root: %s->%s\n", t->word, word);
            t->count++;
            t->sub = add_sub(t->sub, word, len);
        }

        return t;
    }
}

struct tree *add_sub(struct tree *s, char *word, int len)
{

    printf("add sub: %s\n", word);
    if (s == NULL)
    {
        printf("new sub: %s\n", word);
        s = new_tree();
        s->word = strdup(word);
        s->left = NULL;
        s->right = NULL;
        s->sub = NULL;
        return s;
    }
    else
    {
        int comp;
        if ((comp = strcmp(word, s->word)) < 0)
        {
            printf("add sub left: %s\n", word);
            s->left = add_sub(s->left, word, len);
        }
        else if (comp > 0)
        {
            printf("add sub right: %s\n", word);
            s->right = add_sub(s->right, word, len);
        }
        else
        {
            printf("found sub: %s\n", word);
            // Do nothing
        }
        return s;
    }
}

void print_all(struct tree *t)
{
    if (t == NULL)
        return;
    print_all(t->left);
    if (t->count > 1)
    {
        // printf("root %s\n", t->word);
        print_sub(t->sub);
    }
    print_all(t->right);
}

void print_sub(struct tree *t)
{

    if (t == NULL)
        return;
    print_sub(t->left);
    printf("%s\n", t->word);
    print_sub(t->right);
}

struct tree *new_tree(void)
{
    return malloc(sizeof(struct tree));
}

char *get_root(char *word)
{
    return strndup(word, 6);
}
