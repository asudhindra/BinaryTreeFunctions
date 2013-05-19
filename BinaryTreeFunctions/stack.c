//
//  stack.c
//  BinaryTreeFunctions
//
//  Created by Arun Sudhindra on 5/19/13.
//  Copyright (c) 2013 Arun Sudhindra. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

#define MAXSTACK 100
#define EMPTYSTACK -1
int top = EMPTYSTACK;
char items[MAXSTACK];




void push(char c) {
    items[++top] = c;
}

char pop() {
    return items[top--];
}

int full()  {
    return top+1 == MAXSTACK;
}

int empty()  {
    return top == EMPTYSTACK;
}
