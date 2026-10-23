
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Iterative insertion */
struct node *insert(struct node *root, int value)
{
    struct node *newnode, *temp, *parent;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return root;
    }

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
        return newnode;

    temp = root;
    parent = NULL;

    while (temp != NULL)
    {
        parent = temp;

        if (value < temp->data)
            temp = temp->left;
        else if (value > temp->data)
            temp = temp->right;
        else
        {
            printf("Duplicate value not allowed.\n");
            free(newnode);
            return root;
        }
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

/* Iterative inorder display */
void display(struct node *root)
{
    struct node *stack[100];
    struct node *temp;
    int top;

    top = -1;
    temp = root;

    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Inorder Traversal: ");

    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            if (top == 99)
            {
                printf("\nStack limit reached.\n");
                return;
            }

            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];
        printf("%d ", temp->data);

        temp = temp->right;
    }

    printf("\n");
}

/* Delete node containing given value */
struct node *deleteNode(struct node *root, int value)
{
    struct node *temp, *parent, *child;
    struct node *successor, *successorParent;
    struct node *target;

    temp = root;
    parent = NULL;

    /* Search for the node */
    while (temp != NULL && temp->data != value)
    {
        parent = temp;

        if (value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp == NULL)
    {
        printf("Value not found.\n");
        return root;
    }

    target = temp;

    /* Case 1 and 2: zero or one child */
    if (target->left == NULL || target->right == NULL)
    {
        if (target->left != NULL)
            child = target->left;
        else
            child = target->right;

        if (parent == NULL)
            root = child;
        else if (parent->left == target)
            parent->left = child;
        else
            parent->right = child;

        free(target);
    }
    else
    {
        /* Case 3: two children */
        successorParent = target;
        successor = target->right;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        target->data = successor->data;

        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        free(successor);
    }

    printf("Node deleted successfully.\n");
    return root;
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    do
    {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Iterative Insert\n");
        printf("2. Iterative Display\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter integer value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                display(root);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
