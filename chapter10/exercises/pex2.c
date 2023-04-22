#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder_traversal(struct node *);
void inorder_traversal(struct node *);
void postorder_traversal(struct node *);
void print_tree(struct node *, int);
struct node *insert(struct node *, int);
struct node *search(struct node *, int);
struct node *findLargestNode(struct node *);
struct node *findSmallestNode(struct node *);
struct node *delete_node(struct node *, int);
void print_tree(struct node *, int);
void print_tree_value(struct node *, int, int);
int heigth(struct node *);
int total_external_nodes(struct node *);
int total_internal_nodes(struct node *);
int total_nodes(struct node *);
struct node *mirror_image(struct node *);
struct node *delete_tree(struct node *);

int main()
{
    int option, val;
    struct node *tree = NULL;
    struct node *ptr;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1.  Insert node");
        printf("\n 2.  Search node");
        printf("\n 3.  Delete node");
        printf("\n 4.  Find Height of the tree");
        printf("\n 5.  Find total number of nodes");
        printf("\n 6.  Find total number of external nodes");
        printf("\n 7.  Find total number of internal nodes");
        printf("\n 8.  Find the mirror image of the tree");
        printf("\n 9.  Find the smallest element");
        printf("\n 10. Find the largest element");
        printf("\n 11. Preorder traversal");
        printf("\n 12. inorder traversal");
        printf("\n 13. Postorder traversal");
        printf("\n 14. Delete tree");
        printf("\n 15. EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter element to insert: ");
            scanf( " %d", &val);
            tree = insert(tree, val);
            printf("\n ");
            print_tree_value(tree, val, 0);
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 2:
            printf("\n Enter the value to search for: ");
            scanf(" %d", &val);
            ptr = search(tree, val);
            if(ptr == NULL)
            {
                printf("\n Element doesn't exist in the BST");
            }
            else
            {
                printf("\n Element is found");
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n'); // wait for user to press enter
            break;
        case 3:
            printf("\n Enter element to delete: ");
            scanf(" %d", &val);
            tree = delete_node(tree, val);
            printf("\n ");
            if(tree == NULL)
            {
                printf("\n Tree is empty");
            }
            else
            {
                print_tree(tree, 0);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 4:
            val = heigth(tree);
            if(val)
            {
                printf("\n Tree height is: %d", val);
            }
            else
            {
                printf("\n Tree is empty hence its height is 0");
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 5:
            val = total_nodes(tree);
            if(val)
            {
                printf("\n Tree has total of %d nodes", val);
            }
            else
            {
                printf("\n Tree is empty hence has 0 nodes");
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 6:
            val = total_external_nodes(tree);
            if(val)
            {
                printf("\n Tree has total of %d external nodes", val);
            }
            else
            {
                printf("\n Tree is empty hence has 0 external nodes");
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 7:
            val = total_internal_nodes(tree);
            if(val)
            {
                printf("\n Tree has total of %d internal nodes", val);
            }
            else
            {
                printf("\n Tree is empty hence has 0 internal nodes");
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 8:
            tree = mirror_image(tree);
            if(tree != NULL)
            {
                printf("\n Tree has been mirrored");
            }
            else
            {
                printf("\n Tree is empty hence don't have a mirror image");

            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 9:
            ptr = findSmallestNode(tree);
            if(ptr == NULL)
            {
                printf("\n Tree is empty");
            }
            else
            {
                printf("\n Smallest element in BST is: %d", ptr->data);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 10:
            ptr = findLargestNode(tree);
            if(ptr == NULL)
            {
                printf("\n Tree is empty");
            }
            else
            {
                printf("\n Largest element in BST is: %d", ptr->data);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 11:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in preorder traversal: ");
                preorder_traversal(tree);
                printf("\n ");
                print_tree(tree, 0);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 12:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in inorder traversal: ");
                inorder_traversal(tree);
                printf("\n ");
                print_tree(tree, 0);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 13:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in postorder traversal: ");
                postorder_traversal(tree);
                printf("\n ");
                print_tree(tree, 0);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 14:
            tree = delete_tree(tree);
            tree = NULL;
            if(tree == NULL)
            {
                printf("\n Tree has been deleted successfully");
            }
            else
            {
                printf("\n Unable to delete tree for some reason");
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        default:
            printf("\n Ending program...");
            option = 15;
            break;
        }
    }
    while(option != 15);
    return 0;
}

struct node *delete_tree(struct node *tree)
{
    if(tree != NULL)
    {
        delete_tree(tree->left);
        delete_tree(tree->right);
        free(tree);
    }
    return tree;
};

int total_nodes(struct node *tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        return total_nodes(tree->left) + total_nodes(tree->right) + 1;
    }
};

int total_external_nodes(struct node *tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return total_external_nodes(tree->left) + total_external_nodes(tree->right);
    }
}

int total_internal_nodes(struct node *tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL && tree->right == NULL)
    {
        return 0;
    }
    else
    {
        return total_internal_nodes(tree->left) + total_internal_nodes(tree->right) + 1;
    }
}

int heigth(struct node *tree)
{
    int left_heigth, right_heigth;
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        left_heigth = heigth(tree->left);
        right_heigth = heigth(tree->right);
        if(left_heigth > right_heigth)
        {
            return left_heigth + 1;
        }
        else
        {
            return right_heigth + 1;
        }
    }
}

struct node *mirror_image(struct node *tree)
{
    struct node *temp;
    if(tree != NULL)
    {
        mirror_image(tree->left);
        mirror_image(tree->right);
        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    return tree;
};

struct node *findSmallestNode(struct node *tree)
{
    if(tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return findSmallestNode(tree->left);
    }
};

struct node *findLargestNode(struct node *tree)
{
    if(tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        return findLargestNode(tree->right);
    }
};

struct node *delete_node(struct node *tree, int val)
{
    struct node *temp;
    if(tree == NULL)
    {
        printf("\n There is no such value");
    }
    else if(val < tree->data)
    {
        tree->left = delete_node(tree->left, val);
    }
    else if(val > tree->data)
    {
        tree->right = delete_node(tree->right, val);
    }
    else if(tree->left && tree->right)
    {
        temp = findLargestNode(tree->left);
        tree->data = temp->data;
        tree->left = delete_node(tree->left, temp->data);
    }
    else
    {
        temp = tree;
        if(tree->left == NULL && tree->right == NULL)
        {
            tree = NULL;
        }
        else if(tree->left != NULL)
        {
            tree = tree->left;
        }
        else
        {
            tree = tree->right;
        }
        free(temp);
    }
    return tree;
};

struct node *search(struct node *tree, int val)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else if(tree->data == val)
    {
        return tree;
    }
    else
    {
        if(val < tree->data)
        {
            return search(tree->left, val);
        }
        else
        {
            return search(tree->right, val);
        }
    }
};

struct node *insert(struct node *tree, int val)
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
            tree->left = insert(tree->left, val);
        }
        else
        {
            tree->right = insert(tree->right, val);
        }
    }
    return tree;
};


void preorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        printf(" %d", tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
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

void print_tree_value(struct node *tree, int val, int space)
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
        if(tree->data == val)
        {
            printf("(%d)", tree->data);
        }
        else
        {
            printf("%d", tree->data);
        }
        printf("\n");
        print_tree(tree->left, space);
    }
}
