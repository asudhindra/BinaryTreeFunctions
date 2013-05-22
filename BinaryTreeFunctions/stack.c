//
//  stack.c
//  BinaryTreeFunctions
//
//  Created by Arun Sudhindra on 5/19/13.
//  Copyright (c) 2013 Arun Sudhindra. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array =
    (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}

int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }

int isEmpty(struct Stack* stack)
{  return stack->top == -1;  }

void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
