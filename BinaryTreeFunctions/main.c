//
//  main.c
//  BinaryTreeFunctions
//
//  Created by Arun Sudhindra on 5/18/13.
//  Copyright (c) 2013 Arun Sudhindra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

/*
 * Insert a node in a Binary Search Tree.
 */
void insertNode(Node *root, int value)
{
    if(root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    
    else if(value > root->data)
    {
        if(root->right == NULL)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = value;
            root->right = temp;
        }
        else
        {
            insertNode(root->right, value);
        }
    }
    else if(value <= root->data)
    {
        if(root->left == NULL)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = value;
            root->left = temp;
        }
        else
        {
            insertNode(root->left, value);
        }
    }
}

/*
 * Computes the maximum depth of a Binary Tree.
 */
int maxDepth(Node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        
        if(lDepth > rDepth)
            return lDepth+1;
        else
            return rDepth+1;
    }
}

/*
 * Prints the nodes of a Binary Search Tree at a given level.
 */
void printLevel(Node *root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else
    {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

/*
 * Prints the nodes of the Binary Search Tree in level order.
 * You also need helper functions to do the following:
 * (i)  Print the nodes at a given level: printLevel(Node *n)
 * (ii) Find the maximum depth of a Binary Search Tree: maxDepth(Node *n)
 * NOTE: This approach can take O(N^2) time. For a linear time approach, use a queue
 * http://www.geeksforgeeks.org/level-order-tree-traversal/
 */
void printLevelOrder(Node *root)
{
    if(root == NULL)
        return;
    int height = maxDepth(root);
    int i;
    for(i = 1; i <= height; i++)
    {
        printLevel(root, i);
        printf("\n");
    }
}

int main(int argc, const char * argv[])
{
    // insert code here...
    printf("Hello, World!\n");
    //return 0;
    
    Node *rootNode = (Node *)malloc(sizeof(Node));
    rootNode->data = 6;
    
    insertNode(rootNode, 4);
    insertNode(rootNode, 3);
    insertNode(rootNode, 5);
    insertNode(rootNode, 7);
    insertNode(rootNode, 9);
    
    printLevelOrder(rootNode);
}

