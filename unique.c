#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include <string.h>

void print_usage(void) {
    printf("Usage:  unique NUM NUM NUM ...       (normal output)\n");
    printf("        unique -d NUM NUM NUM ...    (debugging output)\n");
    exit(0);
}

/*
* Purpose:      check that each character in the input string is a digit
*               (so that the digits can be stored in the tree).
*               if a ch is not a digit, or the string is empty, call print_usage.*               
*
* Parameters:   const char *s: a pointer to the string
*
* Returns:      nothing
*/
void check_number(const char *s) {
    // check is the string is NULL, and report it
    if (s == NULL){
        print_usage(); 
    }

    // for each ch in string, check that each ch is a digit
    // if not, report it
    for (unsigned int ch = 0; ch < strlen(s); ch++){
        if (!isdigit((unsigned char)s[ch])){
            print_usage();
        }
    }
}

/*
* Purpose:      create a new tree from the input numbers provided.
*               - note if "-d" was provided on the command line
*               - check that each input is a valid with check_number() (excpet "-d")
*               - add each valid input number to the tree with tree_add()
*               - call tree_dump() if "-d" was provided
*               - otherwise call tree_print() 
*               - free the tree with tree_free()           
*
* Parameters:   int argc: the number of arguments provided on the command line
*               char **argv: the value of each argument provided
*
* Returns:      nothing
*/
int main(int argc, char **argv) {

    Tree *tree = tree_alloc(); // allocate a tree
    int seen = 0; // initialize a variable "seen" to be used later

    // loop through the arguements provided on the command line
    // ignoring the first one (just a call to the program)
    for (int i = 1; i < argc; i++){

        // check if "-d" was provided
        if (strcmp(argv[i], "-d") == 0){
            seen = 1; // note that "-d" was provided
        }

        // for everything except "-d":
        else {
            check_number(argv[i]); // call check_number on each input provided
            tree_add(tree, atoi(argv[i])); // add the valid input number to the tree
        }
    }

    // if "-d" was provided
    if (seen == 1){
        tree_dump(tree); // call tree_dump
    }

    else {
        tree_print(tree); // otherwise, call tree_print
    }

    tree_free(&tree); // free the tree

    return 0;
}
