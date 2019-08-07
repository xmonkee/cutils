// Convert hex to integer
// Can begin with 0x or 0X

#include <stdio.h>


int val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

int htoi(char *h) {
    int i, j, k;
    char c;

    for(i = j = 0; (c = h[j]) != '\0'; j++) {

        if (i == 0 && j == 1 && (c == 'x' || c == 'X'))
            // Takes care of 0X or 0x
            continue;

        if ((k = val(c)) == -1)
            // takes care of bad inputs
            return -1;

        i = i * 16 + k;
    }

    return i;

}

int main(void) {
   char *inputs[] = {
       "", "a", "1", "12", "1a", "0x", "0X", "0", "0x1a", "0xaa",
       "zz", "1000", "fff", "01"
   };
   for(int i = 0; i < 14; i++)
       printf("\"%s\": %d\n", inputs[i], htoi(inputs[i]));
}
