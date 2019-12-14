//stack_arr.h
//Add documentation including Pre and Post conditions for functions

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack_arr.h"

FILE *fptr;
Stack312 s;
StackEntry character;
StackEntry compare;


void equationChecker(){
        makeStack(&s);
        bool error = false;
        char missing = ' ';
        character = fgetc(fptr);
        while ((character != '\n') && (character != -1)) {
            if ((character == '(') || (character == '[') || (character == '<')) {//If you see a opening, then push it
                if (isFull(s) == true) {
                    error = true;
                    printf("stack full");
                }
                push(character, &s);
            }

            if (character == ')') {//The following lines are error checking
                if (isEmpty(s) == true) {
                    error = true;
                    missing = '(';
                }
                compare = pop(&s);
                if (compare != '(') {
                    error = true;
                    missing = '(';
                }
            }

            if (character == ']') {
                if (isEmpty(s) == true) {
                    error = true;
                    missing = '[';
                }
                compare = pop(&s);
                if (compare != '[') {
                    error = true;
                    missing = '[';
                }
            }

            if (character == '>') {
                if (isEmpty(s) == true) {
                    error = true;
                    missing = '<';
                }
                compare = pop(&s);
                if (compare != '<') {
                    error = true;
                    missing = '<';
                }
            }

            printf("%c", character);
            character = fgetc(fptr);

        }
        if (isEmpty(s) == false) {
            error = true;
            compare = pop(&s);
            if (compare == '(') {
                missing = ')';
            }
            if (compare == '[') {
                missing = ']';
            }
            if (compare == '<') {
                missing = '>';
            }
        }
        if (error == true) {
            printf("%s" "%c", " === missing ", missing);
        } else {
            printf("%s", " === valid expression");
        }
        printf("\n");
    }

int main(int argc, char *argv[]) {

    char fname[BUFSIZ];
    strcpy(fname, argv[1]);
    fptr = fopen(fname, "r");
    if (fptr == NULL) {
        printf("error\n");
        exit(-1);
    }

    while(character != -1) {
        equationChecker();
    }
    return 0;
}
