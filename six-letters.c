/*
 * Exercise 6-2. Write a program that reads a C program and prints in
 * alphabetical order each group of variable names that are identical in the
 * first 6 characters, but different somewhere thereafter. Don't count words
 * within strings and comments. Make 6 a parameter that can be set from the
 * command line.
 */

/*
 * tree {
 *  int count;
 *  char *word;
 *  tree subtree;
 *  tree left;
 *  tree right;
 * }
 *
 * For each word in file:
 *  if word len >= 6
 *      add_word(tree, word)
 * print_all(tree)
 *
 * add_word(tree, word)
 *    root = word[0:6]
 *    find root in tree
 *    if not found: create root
 *    increment root count by 1
 *    add word to root
 *
 * print_all(tree):
 *   print_all(tree->left)
 *   if tree->count > 1:
 *     print_subree(tree->subtree)
 *   print_all(tree_right)
 */

struct tree {
    int count;
    char *word;
    struct tree *sub;
    struct tree *left;

int get_word(char *word) {
    char c;
    while(c = getchar()) 
}
