#include <stdio.h>
int main(void) {
    printf("%20s %lu\n", "short", 8 * sizeof(short));
    printf("%20s %lu\n", "int", 8 * sizeof(int));
    printf("%20s %lu\n", "long", 8 * sizeof(long));
    printf("\n");
    printf("%20s %lu\n", "unsigned int", 8 * sizeof(unsigned int));
    printf("%20s %lu\n", "unsigned short int", 8 * sizeof(unsigned short int));
    printf("%20s %lu\n", "unsigned long int", 8 * sizeof(unsigned long int));
    printf("\n");
    printf("%20s %lu\n", "char", 8 * sizeof(char));
    printf("%20s %lu\n", "unsigned char", 8 * sizeof(unsigned char));
    printf("\n");
    printf("%20s %lu\n", "float", 8 * sizeof(float));
    printf("%20s %lu\n", "double", 8 * sizeof(double));
    printf("%20s %lu\n", "long double", 8 * sizeof(long double));
}
