#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_tree(struct node *tree)
{
    tree = NULL;
    return tree;
};

struct node *search_element(struct node *tree, int val)
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
            return search_element(tree->left, val);
        }
        else
        {
            return search_element(tree->right, val);
        }
    }
}

struct node *insert_element(struct node *tree, int val)
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
            tree->left = insert_element(tree->left, val);
        }
        else if(val > tree->data)
        {
            tree->right = insert_element(tree->right, val);
        }
        else
        {
            tree->data = val;
        }
    }
    return tree;
};

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

struct node *delete_element(struct node *tree, int val)
{
    struct node *temp;

    if(tree == NULL)
    {
        printf("\n Element not found in the tree");
    }
    else if(val < tree->data)
    {
        tree->left = delete_element(tree->left, val);
    }
    else if(val > tree->data)
    {
        tree->right = delete_element(tree->right, val);
    }
    else if(tree->left && tree->right)
    {
        temp = find_largest_element(tree->left);
        tree->data = temp->data;
        tree->left = delete_element(tree->left, temp->data);
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

void preorder_travesal(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d ", tree->data);
        preorder_travesal(tree->left);
        preorder_travesal(tree->right);
    }
};

void inorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d ", tree->data);
        inorder_traversal(tree->right);
    }
}

void postorder_travesal(struct node *tree)
{
    if(tree != NULL)
    {
        postorder_travesal(tree->left);
        postorder_travesal(tree->right);
        printf("%d ", tree->data);
    }
}

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

int main()
{
    int option, val;
    struct node *tree, *ptr;
    tree = create_tree(tree);
    do
    {
        printf("\n ******MAIN MENU*******");
        printf("\n\n --Modify--");
        printf("\n 1. Insert Element");
        printf("\n 2. Delete an element");
        printf("\n\n --Traverse, Search, and Count--");
        printf("\n 3. Search for an element");
        printf("\n 4. Preorder Traversal");
        printf("\n 5. Inorder Traversal");
        printf("\n 6. Postorder Traversal");
        printf("\n 7. Find the smallest element");
        printf("\n 8. Find the largest element");
        printf("\n 9. Count the total number of nodes");
        printf("\n 10. Count the total number of external nodes");
        printf("\n 11. Count the total number of internal nodes");
        printf("\n 12. Determine the height of the tree");
        printf("\n\n --Mirror Tree--");
        printf("\n 13. Find the mirror image of the tree");
        printf("\n\n --Delete--");
        printf("\n 14. Delete the BST");
        printf("\n 15. EXIT\n");
        printf("\n Enter your option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the value of the new node: ");
            scanf(" %d", &val);
            tree = insert_element(tree, val);
            break;
        case 2:
            printf("\n Enter the element to delete: ");
            scanf(" %d", &val);
            tree = delete_element(tree, val);
            printf("\n %d has been deleted", val);
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 3:
            printf("\n Enter the value to search for: ");
            scanf(" %d", &val);
            ptr = search_element(tree, val);
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
        case 4:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in preorder traversal: ");
                preorder_travesal(tree);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
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
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 6:
            if(tree == NULL)
            {
                printf("\n The tree is empty");
            }
            else
            {
                printf("\n Elements in postorder traversal: ");
                postorder_travesal(tree);
            }
            printf("\n\n Press enter to continue...");
            getchar();
            while (getchar() != '\n');
            break;
        case 7:
            ptr = find_smallest_element(tree);
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
        case 8:
            ptr = find_largest_element(tree);
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
        case 9:
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
        case 10:
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
        case 11:
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
        case 12:
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
        case 13:
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
        case 14:
            tree = delete_tree(tree);
            tree = NULL;
            if(tree == NULL)
            {
                printf("\n Tree has been deleted succesfully");
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
            option = 15;
            break;
        }
    }
    while(option != 15);
}
