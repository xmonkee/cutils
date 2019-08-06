#include <stdlib.h>

typedef struct StringBuilder {
    int len;
    char *s;
    size_t bufsize;
} StringBuilder;

StringBuilder * new_sb(void);
void add_str(StringBuilder *sb, const char *s, int len);
void add_chr(StringBuilder *sb, char c);
int get_len(const StringBuilder *sb);
int get_str(const StringBuilder *sb, char *s);
void free_sb(StringBuilder *sb);
