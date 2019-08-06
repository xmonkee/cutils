#include <stdio.h>
#include <stdbool.h>

/* Replace tabs with spaces */

#define TABSTOP 4

int main(void) {
    char c;
    int space_size = 0;
    while((c=getchar()) !=EOF) {
        if (c==' '){
            // Keep a count of congiguous spaces
            space_size += 1;
            // Put a tab for TABSTOP spaces collected
            if(space_size == TABSTOP) {
                putchar('\t');
                space_size = 0;
            }
        }
        else { // c is not a space
            // Put leftover spaces
            for(; space_size >= 0; space_size--) putchar(' ');
            putchar(c);
        }
    }
    // Any leftover spaces before EOF
    for(; space_size >= 0; space_size--) putchar(' ');
}
