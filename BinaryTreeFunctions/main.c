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


/*
 * Perform an iterative Preorder traversal of a Binary Search Tree.
 * http://www.geeksforgeeks.org/iterative-preorder-traversal/
 */
void iterativePreorderTraversal(Node * head)
{
    if(head == NULL)
        return;
    Stack *s1 = createStack(MAX_SIZE);
    
    //Push the root Node on to the stack.
    push(s1, head);
    /* Pop all items one by one. Do following for every popped item
     a) print it
     b) push its right child
     c) push its left child
     Note that right child is pushed first so that left is processed first
     */
    while(!isEmpty(s1))
    {
        struct Node * node = pop(s1);
        //Print the value of the node (Preorder)
        printf("%d ", node->data);
        
        //Push right and left children of the popped node to stack
        if(node->right != NULL)
            push(s1, node->right);
        if(node->left != NULL)
            push(s1, node->left);
    }
    
}

/*
 * Perform an iterative Postorder traversal of a Binary Search Tree.
 * Explanation: http://www.geeksforgeeks.org/iterative-postorder-traversal/
 * Summary: Similar to Preorder traversal, except:
 * (a) Instead of prinitng the value of the node, push the node to the second stack.
 * (b) Push the left subtree instead of the right subtree.
 */
void iterativePostorderTraversal(Node * head)
{
    if(head == NULL)
        return;
    Stack *s1 = createStack(MAX_SIZE);
    Stack *s2 = createStack(MAX_SIZE);
    
    //Push the root node on to the stack.
    push(s1, head);
    while(!isEmpty(s1))
    {
        Node *node = pop(s1);
        //Push the node on to the second stack instead of printing its value
        //like we do for preorder traversal.
        push(s2, node);
        
        //Instead of pushing the right child and then the left child, push the
        //left child and then right child
        if(node->left != NULL)
            push(s1, node->left);
        if(node->right != NULL)
            push(s1, node->right);
    }
    
    //We now have the reversed form of a postorder traversal on stack s2. Pop elements off s2 and print values
    while(!isEmpty(s2))
    {
        Node *temp = pop(s2);
        printf("%d ", temp->data);
    }
}

/*
 * Prints the Inorder traversal of a Binary Search Tree.
 * Explanation: http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
 * Summary: Use a stack and a current pointer.
 * (a) Initialize the current node as root.
 * (b) Push the current node on to the stack.
 * (c) Set current = current->left until current is NULL.
 * (d) If current is NULL and the stack is not empty then:
 *          Pop the stack and print the value of the node of the popped element.
 *          Set current = current->right.
 *          Go to step (b).
 * (e) If current is NULL and the stack is empty, we are done with printing all the nodes, so exit.
 */
void iterativeInorderTraversal(Node *node)
{
    if(node == NULL)
        return;
    
    Stack *s = createStack(MAX_SIZE);
    Node *current = node;
    int done = 0;
    
    while (!done)
    {
        if(current != NULL)
        {
            push(s, current);
            current = current->left;
        }
        else
        {
            if(!isEmpty(s))
            {
                current = pop(s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
            {
                done = 1;
            }
        }
    }
}

int lowestCommonAncestorBST(Node *head, int data1, int data2)
{
    if(head == NULL)
        return -1;
    if(data1 < head->data && data2 < head->data)
        return lowestCommonAncestorBST(head->left, data1, data2);
    else if(data1 > head->data && data2 > head->data)
        return lowestCommonAncestorBST(head->right, data1, data2);
    else
        return head->data;
}


int main(int argc, const char * argv[])
{
    Node *rootNode = (Node *)malloc(sizeof(Node));
    rootNode->data = 6;
    
    insertNode(rootNode, 4);
    insertNode(rootNode, 3);
    insertNode(rootNode, 5);
    insertNode(rootNode, 7);
    insertNode(rootNode, 9);
    
    printLevelOrder(rootNode);
    printf("\n");
    
    printf("****POSTORDER TRAVERSAL****\n");
    iterativePostorderTraversal(rootNode);
    printf("\n");
    
    printf("****PREORDER TRAVERSAL****\n");
    iterativePreorderTraversal(rootNode);
    printf("\n");
    
    printf("****INORDER TRAVERSAL****\n");
    iterativeInorderTraversal(rootNode);
    printf("\n");
    
    printf("****LOWEST COMMON ANCESTOR OF BST****\n");
    int result = lowestCommonAncestorBST(rootNode, 3, 5);
    printf("%d", result);
    printf("\n");
}

