#include "string-builder.h"
#include <stdio.h>

StringBuilder * new_sb(void) {
    StringBuilder *sb = malloc(sizeof(StringBuilder));
    sb->bufsize = 10;
    sb->s = malloc(sizeof(char) * sb->bufsize);
    sb->len = 0;
    return sb;
}

void free_sb(StringBuilder *sb) {
    free(sb->s);
    free(sb);
}

int get_len(const StringBuilder *sb) {
    return sb->len;
}

int get_str(const StringBuilder *sb, char *s) {
    int i;
    for(i = 0; i < sb->len; i++) {
        s[i] = sb->s[i];
    }
    s[i] = '\0';
    return sb->len;
}

void grow(StringBuilder *sb) {
    sb->s = realloc(sb->s, sb->bufsize * 2);
    if(sb->s == NULL) {
        perror("realloc");
        exit(1);
    }
    sb->bufsize *= 2;
}

void add_chr(StringBuilder *sb, char c) {
    if ((size_t)sb->len == sb->bufsize) {
       grow(sb);
    }
    sb->s[sb->len] = c;
    sb->len++;
}

void add_str(StringBuilder *sb, const char *s, int len) {
    while ((size_t)(sb->len + len) > sb->bufsize) {
       grow(sb);
    }
    int i = 0;
    while(s[i] != '\0'){
        sb->s[sb->len++] = s[i++];
    }
    sb->s[sb->len] = '\0';
}
