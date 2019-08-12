#include "links.h"
#include <stdio.h>
#include <stdlib.h>

void chain_init(chain *c) {
    c->head = c->tail = NULL;
}

void link_s_before(chain *c, char *s){
    link *l = malloc(sizeof(link));
    l->s = s;
    link_before(c, l);
}

void link_before(chain *c, link *n) {
    if(c->head == NULL) {
        c->head = c->tail = n;
        c->head->next = c->head->prev = NULL;
    } else {
        n->next = c->head;
        c->head->prev = n;
        n->prev = NULL;
        c->head = n;
    }
}

void link_s_after(chain *c, char *s){
    link *l = malloc(sizeof(link));
    l->s = s;
    link_after(c, l);
}

void link_after(chain *c, link *n) {
    if(c->tail == NULL) {
        /*printf("NULL called %s\n", n->s);*/
        c->head = c->tail = n;
        c->head->next = c->head->prev = NULL;
    } else {
        /*printf("TULL called %s\n", n->s);*/
        n->prev = c->tail;
        c->tail->next = n;
        n->next = NULL;
        c->tail = n;
    }
}

void chain_print_all(chain *c) {
    link *curr = c->head;
    while(curr->next != NULL) {
        printf("%s ", curr->s);
        curr = curr->next;
    }
    printf("%s\n", curr->s);
}

void chain_free_all(chain *c) {
    link *curr = c->head;
    while(curr != NULL) {
        link *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(c);
}

