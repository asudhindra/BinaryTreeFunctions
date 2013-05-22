//
//  stack.h
//  BinaryTreeFunctions
//
//  Created by Arun Sudhindra on 5/19/13.
//  Copyright (c) 2013 Arun Sudhindra. All rights reserved.
//

#include "main.h"
// Maximum stack size
#define MAX_SIZE 100

#ifndef BinaryTreeFunctions_stack_h
#define BinaryTreeFunctions_stack_h

typedef struct Stack
{
    struct Node* *array;
    int top;
    int size;
} Stack;

struct Stack* createStack(int size);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, struct Node* node);
struct Node* pop(struct Stack* stack);

#endif
