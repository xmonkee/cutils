
#include "links.h"
#include <stdlib.h>

int main(void) {
    char *_inputs[] = {
        "hello",
        "my",
        "name is",
        NULL,
    };
    link *l;
    chain *c = malloc(sizeof(chain));
    chain_init(c);
    char **inputs = _inputs;
    for (; *inputs != NULL; inputs++){
        l = malloc(sizeof(link));
        l->s = *inputs;
        link_before(c, l);
        l = malloc(sizeof(link));
        l->s = *inputs;
        link_after(c, l);
    }
    chain_print_all(c);
    chain_free_all(c);
}
