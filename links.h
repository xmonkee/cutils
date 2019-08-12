typedef struct link {
    struct link *prev;
    struct link *next;
    char *s;
} link;

typedef struct chain {
    link *head;
    link *tail;
} chain;

void chain_init(chain *c);
void link_before(chain *c, link *n);
void link_after(chain *c, link *n);
void link_s_before(chain *c, char *s);
void link_s_after(chain *c, char *s);
void chain_print_all(chain *c);
void chain_free_all(chain *c);
