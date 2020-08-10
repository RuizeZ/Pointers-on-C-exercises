/*
ruizeZ
8/10/2020
Write a function for the linked tree module that deletes a value from the tree. If the
value to be deleted is not found in the tree, the function may abort the program.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
void insert(int value);
void delete(int value);
typedef struct TREE_NODE
{
    int value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

static TreeNode *tree;

int main(void)
{
    int inputvalue;
    char option[1];
    while(1)
    {
        printf("What do you want to do? (I)nsert or (D)elete or (Q)uit \n");
        scanf("%s", option);
        if (!strcmp(option, "I"))
        {
            printf("Please inter the value you want to insert\n");
            scanf("%d", &inputvalue);
            insert(inputvalue);
        }
        else if (!strcmp(option, "D"))
        {
            printf("Please inter the value you want to delete\n");
            scanf("%d", &inputvalue);
            delete(inputvalue);
        }
        else if (!strcmp(option, "Q"))
        {
            break;
        }
    }
}

void insert(int value)
{
    TreeNode *current;
    TreeNode **link;

    link = &tree;

    while ((current = *link) != NULL)
    {
        if(value < current->value)
        {
            link = &current->left;
        }
        else
        {
            assert(value != current->value);
            link = &current->right;
        }
    }
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current -> value = value;
    current -> left = NULL;
    current -> right = NULL;
    *link = current;
}

void delete(int value)
{
    TreeNode *current;
    TreeNode **link;
    TreeNode *delete;
    int findvalue = 0;
    // TreeNode **previous;

    link = &tree;
    // previous = link;

    while ((current = *link) != NULL)
    {
        if(value < current->value)
        {
            // previous = link;
            link = &current->left;
        }
        else if(value > current->value)
        {
            // previous = link;
            link = &current->right;
        }
        else if(value == current->value)
        {
            findvalue = 1;
            break;
        }
    }
    if (!findvalue)
    {
        exit(0);
    }
    
    
    if ((current->left == NULL) && (current->right == NULL))
    {
        *link = NULL;
    }
    else if ((current->left != NULL) && (current->right != NULL))
    {
        delete = *link;
        link = &current->left;
        int maxvalue = (*link)->value;
        if ((*link)->right == NULL)
        {
            delete->value = maxvalue;
            delete->left = (*link)->left;
        }
        else
        {    while ((current = *link) != NULL)
            {
                if ((current->value > maxvalue))
                {
                    maxvalue = current->value;
                }
                if ((current->right == NULL))
                {
                    break;
                }
                
                link = &current->right;
            }
            *link = NULL;
            delete->value = maxvalue;
        }
    }
    else if ((current->left != NULL) || (current->right != NULL))
    {
        if (current->left != NULL)
        {
            *link = current->left;
        }
        else if(current->right != NULL)
        {
            *link = current->right;
        } 
    }
}