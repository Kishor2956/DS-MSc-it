
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value not allowed.\n");

    return root;
}

/* Preorder: Root, Left, Right */
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Inorder: Left, Root, Right */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Postorder: Left, Right, Root */
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    do
    {
        printf("\n\n--- BINARY TREE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter integer value: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Insertion completed.\n");
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
