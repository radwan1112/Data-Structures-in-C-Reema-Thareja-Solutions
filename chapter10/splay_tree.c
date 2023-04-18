#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *new_node(int val)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if(!new_node)
    {
        printf("\n Out of memory bound!");
        return NULL;
    }
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
};

struct node *rr_rotate(struct node *k2)
{
    struct node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
};

struct node *ll_rotate(struct node *k2)
{
    struct node *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    return k1;
};

struct node *splay(struct node *tree, int val)
{
    if(!tree)
    {
        return NULL;
    }
    struct node *header;
    header = (struct node *)malloc(sizeof(struct node));
    header->left = header->right = NULL;

    struct node *leftTreeMax = header;
    struct node *rightTreeMin = header;

    while(1)
    {
        if(val < tree->data)
        {
            if(!tree->left)
            {
                break;
            }
            if(val < tree->left->data)
            {
                tree = rr_rotate(tree);
                if(!tree->left)
                {
                    break;
                }
            }
            rightTreeMin->left = tree;
            rightTreeMin = rightTreeMin->left;
            tree = tree->left;
            rightTreeMin->left = NULL;
        }
        else if(val > tree->data)
        {
            if(!tree->right)
            {
                break;
            }
            if(val > tree->right->data)
            {
                tree = ll_rotate(tree);
                if(!tree->right)
                {
                    break;
                }
            }
            leftTreeMax->right = tree;
            leftTreeMax = leftTreeMax->right;
            tree = tree->right;
            leftTreeMax->right = NULL;
        }
        else
        {
            break;
        }
    }

    leftTreeMax->right = tree->left;
    rightTreeMin->left = tree->right;
    tree->left = header->right;
    tree->right = header->left;
    return tree;

};

struct node *insert(struct node *tree, int val)
{
    struct node *ptr = NULL;

    if(!ptr)
    {
        ptr = new_node(val);
    }
    else
    {
        ptr->data = val;
    }

    if(!tree)
    {
        tree = ptr;
        ptr = NULL;
        return tree;
    }
    tree = splay(tree, val);

    if(val < tree->data)
    {
        ptr->left = tree->left;
        ptr->right = tree;
        tree->left = NULL;
        tree = ptr;
    }
    else if(val > tree->data)
    {
        ptr->right = tree->right;
        ptr->left = tree;
        tree->right = NULL;
        tree = ptr;
    }
    else
    {
        return tree;
    }

    ptr = NULL;
    return tree;
};

struct node *delete(struct node *tree, int val)
{
    struct node *temp;
    if(!tree)
    {
        return NULL;
    }
    tree = splay(tree, val);
    if(val != tree->data)
    {
        return tree;
    }
    else
    {
        if(!tree->left)
        {
            temp = tree;
            tree = tree->right;
        }
        else
        {
            temp = tree;
            tree = splay(tree->left, val);
            tree->right = temp->right;
        }
        free(temp);
        return tree;
    }
};

struct node *search(struct node *tree, int val)
{
    return splay(tree, val);
};

void preorder_travesal(struct node *tree)
{
    if(tree != NULL)
    {
        printf(" %d", tree->data);
        preorder_travesal(tree->left);
        preorder_travesal(tree->right);
    }
}

void inorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        inorder_traversal(tree->left);
        printf(" %d", tree->data);
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf(" %d", tree->data);
    }
}

void print_tree(struct node *tree, int space)
{
    int i;
    if(tree != NULL)
    {
        space = space + 10;
        print_tree(tree->right, space);
        printf("\n");
        for(i = 10; i < space; i++)
        {
            printf(" ");
        }
        printf("%d", tree->data);
        printf("\n");
        print_tree(tree->left, space);
    }
}

int main()
{
    int option, val;
    struct node *tree = NULL;
    do
    {
        printf("\n ------MENU------");
        printf("\n 1. Insert node");
        printf("\n 2. Search node");
        printf("\n 3. Delete node");
        printf("\n 4. Preorder traversal");
        printf("\n 5. Inorder traversal");
        printf("\n 6. Postorder traversal");
        printf("\n 7. EXIT");
        printf("\n\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the data of the node: ");
            scanf(" %d", &val);
            tree = insert(tree, val);
            break;
        case 2:
            printf("\n Enter the value to search for: ");
            scanf(" %d", &val);
            tree = search(tree, val);
            if(tree->data == val)
            {
                printf("\n value is found");
            }
            else
            {
                printf("\n value not found");
            }
            break;
        case 3:
            printf("\n Enter the node value to delete: ");
            scanf(" %d", &val);
            tree = delete(tree, val);
            break;
        case 4:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in preorder traversal: ");
                preorder_travesal(tree);
                printf("\n");
                print_tree(tree, 0);
            }
            break;
        case 5:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in inorder traversal: ");
                inorder_traversal(tree);
                printf("\n");
                print_tree(tree, 0);
            }
            break;
        case 6:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in postorder traversal: ");
                postorder_traversal(tree);
                printf("\n");
                print_tree(tree, 0);
            }
            break;
        default:
            option = 7;
            break;
        }
    }
    while(option != 7);

    return 0;
}
