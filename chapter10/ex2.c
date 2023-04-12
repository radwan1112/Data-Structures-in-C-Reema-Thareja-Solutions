#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    bool rigth_thread;
};

struct node *insert_node(struct node *root, struct node *new_node, struct node *rt)
{
    if(root == NULL)
    {
        root = new_node;
        if(rt != NULL)
        {
            root->right = rt;
            root->rigth_thread = true;
        }
    }
    else if(new_node->data < root->data)
    {
        root->left = insert_node(root->left, new_node, root);
    }
    else
    {
        if(root->rigth_thread == true)
        {
            root->right = insert_node(NULL, new_node, rt);
            root->rigth_thread = false;
        }
        else
        {
            root->right = insert_node(root->right, new_node, rt);
        }
    }
    return root;
};

struct node *create_node(struct node *root, int val)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    new_node->rigth_thread = false;
    root = insert_node(root, new_node, NULL);
    return root;
};

void inorder_traversal(struct node *root)
{
    struct node *ptr, *prev;
    ptr = root;
    do
    {
        while(ptr != NULL)
        {
            prev = ptr;
            ptr = ptr->left;
        }
        if(prev != NULL)
        {
            printf(" %d", prev->data);
            ptr = prev->right;
            while(prev != NULL && prev->rigth_thread)
            {
                printf(" %d", ptr->data);
                prev = ptr;
                ptr = ptr->right;
            }
        }
    }
    while(ptr != NULL);
};

int main()
{
    int option, val;
    struct node *root = NULL;

    do
    {
        printf("\n ------MENU------");
        printf("\n 1. Insert element");
        printf("\n 2. Inorder traversal");
        printf("\n 3. EXIT");
        printf("\n\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter value to insert: ");
            scanf(" %d", &val);
            root = create_node(root, val);
            break;
        case 2:
            inorder_traversal(root);
            break;
        default:
            option = 3;
            break;
        }
    }
    while(option != 3);

    return 0;
}
