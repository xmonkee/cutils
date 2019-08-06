#include "util.h"
#include <stdio.h>


void test_reverse(void) {
    char s[] = "hello";
    reverse(s, 5);
    if (!strcmp1(s, "olleh")) {
        printf("failed: %s != %s\n", s, "olleh");
        exit(1);
    }
}

int main(void) {
    test_reverse();
    printf("Success\n");
}
