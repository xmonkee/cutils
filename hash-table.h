#define HASHSIZE 1000

typedef struct node
{
    char *key;
    char *val;
    struct node *next;
} node;

typedef node **table;

table init_table(void);
void free_table(table t);
node *lookup(table t, char *key);
node *insert(table t, char *key, char *val);