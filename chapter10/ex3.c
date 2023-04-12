#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int balance;
};

struct node *insert_node(struct node *tree, int val)
{
    if(tree == NULL)
    {
        tree = (struct node *)malloc(sizeof(struct node));
        tree->data = val;
        tree->left = tree->right = NULL;
    }
    else
    {
        if(val < tree->data)
        {
            tree->left = insert_node(tree->left, val);
        }
        else
        {
            tree->right = insert_node(tree->right, val);
        }
    }

    //Balance factor check
    tree->balance


    return tree;
};


int main()
{
    int option, val;
    struct node *tree = NULL;

    do
    {
        printf("\n ------MENU------");
        printf("\n 1. Insert node");
        printf("\n 2. Delete node");
        printf("\n 3. Inorder traverse");
        printf("\n 4. EXIT");
        printf("\n\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the data of the node: ");
            scanf(" %d", &val);
            tree = insert_node(tree, val);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            option = 4;
            break;
        }
    }
    while(option != 4);

    return 0;
}
