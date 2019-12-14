
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack_arr.h"

int i = 99;
void makeStack(Stack312 *s){
    s->top = s->elements[99] = 0;
    s->elements[0] = ' ';
}

bool isFull(Stack312 s){
 if(s.top == s.elements[0]){
     return true;
 } else{
     return false;
 }
}

bool isEmpty(Stack312 s){
 if(s.top == 0){
     return true;
 }else{
     return false;
 }
}

void push(StackEntry e,Stack312 *s){
    s->top = e;//make the top element of the stack the entry
    i--;
    s->elements[i] = s->top;//make the top of the stack the next location
    //printf("%d", i);
}

StackEntry pop(Stack312 *s){
    StackEntry temp = s->top;//temporary pointer to top
    i++;
    s->top = s->elements[i];// make the last location the top of the stack
    //printf("%d", i);
    return temp;
}
