#define _GNU_SOURCE
#include "string-builder.h"
#include "assert.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int errors = 0;

void test_new_free(void) {
    StringBuilder * sb = new_sb();
    free_sb(sb);
}

void test_get_len_zero(void) {
    StringBuilder *sb = new_sb();
    assert(get_len(sb) == 0, "get_len");
    free_sb(sb);
}

void test_get_str_zero(void) {
    StringBuilder *sb = new_sb();
    char s[1];
    get_str(sb, s);
    assert(strcmp(s, "") == 0, "get_str");
    free_sb(sb);
}

void test_add_chr(void) {
    StringBuilder *sb = new_sb();

    add_chr(sb, 'c');
    char s[200]; get_str(sb, s);
    assert(strcmp(s, "c") == 0, "add_chr");

    add_chr(sb, 'd');
    get_str(sb, s);
    assert(strcmp(s, "cd") == 0, "add_chr");

    free_sb(sb);
}

void test_add_str(void) {
    StringBuilder *sb = new_sb();
    add_chr(sb, 'h');
    add_str(sb, "ello", 5);

    char s[200]; get_str(sb, s);
    assert(strcmp(s, "hello") == 0, "add_str");

    add_str(sb, "1234567890", 10);
    get_str(sb, s);
    assert(strcmp(s, "hello1234567890") == 0, "add_str");
}

int main(void) {
    test_new_free();
    test_get_len_zero();
    test_get_str_zero();
    test_add_chr();
    test_add_str();
    if(errors) {
        printf("Failures: %d\n", errors);
        return 1;
    }
    return 0;
}
