#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100;

/* Read several lines from stdin and print the longest one */

size_t copy(char **dest, char *src, size_t dst_len, size_t src_len) {
    /* copy string *src into *dest. 
     * Resizes dest buffer to 2 * src_len if src_len > dst_len
     * Updates *dest to point to new location if resize is required
     * Returns new length of *dest buffer
     */
    if(src_len > dst_len) {
        // Double the size of the destination buffer if source is bigger
        dst_len = src_len * 2;
        *dest = realloc(*dest, dst_len);
    }
    memcpy(*dest, src, src_len);
    return dst_len;

}

int main(void) {
    char *line = NULL;
    size_t n = 0;
    size_t nread;

    size_t size_long_buf = MAXLEN;
    char *longest_line = calloc(sizeof(char), size_long_buf);
    size_t longest_len = 0;


    while((nread = getline(&line, &n, stdin)) != (size_t)-1) {
        if(nread > longest_len) {
            size_long_buf = copy(&longest_line, line, size_long_buf, nread);
            longest_len = nread;
        }
    }
    fwrite(longest_line, longest_len, 1, stdout);
    printf("length: %ld\n", longest_len);

    free(longest_line);
    free(line);
    return 0;
}


