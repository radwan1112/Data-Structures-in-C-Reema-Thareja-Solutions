#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int balance;
};

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node *find_smallest_element(struct node *tree)
{
    if(tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return find_smallest_element(tree->left);
    }
};

struct node *find_largest_element(struct node *tree)
{
    if(tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        return find_largest_element(tree->right);
    }
};

int height(struct node *tree)
{
    int left_height, right_height;
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        left_height = height(tree->left);
        right_height = height(tree->right);
        if(left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

int balance_factor(struct node *tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL && tree->right == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL && tree->right != NULL)
    {
        return -(height(tree->right) + 1);
    }
    else if(tree->right == NULL && tree->left != NULL)
    {
        return height(tree->left) + 1;
    }
    else
    {
        return ((height(tree->left) + 1) - (height(tree->right) + 1));
    }
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->balance = balance_factor(y);
    x->balance = balance_factor(x);
    return x;
};

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->balance = balance_factor(x);
    y->balance = balance_factor(y);
    return y;
};

struct node *insert_node(struct node *tree, int val)
{
    if(tree == NULL)
    {
        tree = (struct node *)malloc(sizeof(struct node));
        tree->data = val;
        tree->balance = 0;
        tree->left = tree->right = NULL;
    }
    else
    {
        if(val < tree->data)
        {
            tree->left = insert_node(tree->left, val);
        }
        else if(val > tree->data)
        {
            tree->right = insert_node(tree->right, val);
        }
        else
        {
            return tree;
        }
    }

    //Balance factor check
    tree->balance = balance_factor(tree);

    if(tree->balance > 1 && balance_factor(tree->left) >= 0)
    {
        return rightRotate(tree);
    }
    if(tree->balance > 1 && balance_factor(tree->left) < 0)
    {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }
    if(tree->balance < -1 && balance_factor(tree->right) <= 0)
    {
        return leftRotate(tree);
    }
    if(tree->balance < -1 && balance_factor(tree->right) > 0)
    {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
};

struct node *delete_node(struct node *tree, int val)
{
    struct node *temp;
    if(tree == NULL)
    {
        printf("\n Element not found in the tree");
        return tree;
    }

    if(val < tree->data)
    {
        tree->left = delete_node(tree->left, val);
    }
    else if(val > tree->data)
    {
        tree->right = delete_node(tree->right, val);
    }
    else
    {
        if((tree->left == NULL) || (tree->right == NULL))
        {
            struct node *temp = tree->left ? tree->left : tree->right;
            if(temp == NULL)
            {
                temp = tree;
                tree = NULL;
            }
            else
            {
                *tree = *temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(tree->right);
            tree->data = temp->data;
            tree->right = delete_node(tree->right, temp->data);
        }
    }

    if(tree == NULL)
    {
        return tree;
    }
    //Balance factor check
    tree->balance = balance_factor(tree);
    // Left Left Case
    if (tree->balance > 1 && val < tree->left->data)
    {
        return rightRotate(tree);
    }
    // Right Right Case
    if (tree->balance < -1 && val > tree->right->data)
    {
        return leftRotate(tree);
    }
    // Left Right Case
    if (tree->balance > 1 && val > tree->left->data)
    {
        tree->left =  leftRotate(tree->left);
        return rightRotate(tree);
    }
    // Right Left Case
    if (tree->balance < -1 && val < tree->right->data)
    {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

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

int main()
{
    int option, val;
    struct node *tree = NULL;

    do
    {
        printf("\n ------MENU------");
        printf("\n 1. Insert node");
        printf("\n 2. Delete node");
        printf("\n 3. Preorder traversal");
        printf("\n 4. Inorder traversal");
        printf("\n 5. Postorder traversal");
        printf("\n 6. EXIT");
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
            printf("\n Enter the node value to delete: ");
            scanf(" %d", &val);
            tree = delete_node(tree, val);
            break;
        case 3:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in preorder traversal: ");
                preorder_travesal(tree);
            }
            break;
        case 4:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in inorder traversal: ");
                inorder_traversal(tree);
            }
            break;
        case 5:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in postorder traversal: ");
                postorder_traversal(tree);
            }
            break;
        default:
            option = 6;
            break;
        }
    }
    while(option != 6);

    return 0;
}
