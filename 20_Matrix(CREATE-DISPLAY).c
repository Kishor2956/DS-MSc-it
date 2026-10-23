
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int col;
    int data;
    struct node *right;
    struct node *down;
};

struct node *head = NULL;
int rows, cols;

/* Create matrix */
void create()
{
    struct node *newnode, *temp;
    int i, j, value;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0)
    {
        printf("Invalid matrix size.\n");
        head = NULL;
        return;
    }

    head = NULL;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &value);

            newnode = (struct node *)malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("Memory allocation failed.\n");
                return;
            }

            newnode->row = i;
            newnode->col = j;
            newnode->data = value;
            newnode->right = NULL;
            newnode->down = NULL;

            if (head == NULL)
                head = newnode;
            else
            {
                temp = head;

                while (temp->right != NULL)
                    temp = temp->right;

                temp->right = newnode;
            }
        }
    }

    printf("Matrix created successfully.\n");
}

/* Display matrix */
void display()
{
    struct node *temp;
    int i, j;

    if (head == NULL)
    {
        printf("Matrix not created.\n");
        return;
    }

    temp = head;

    printf("Matrix:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (temp != NULL)
            {
                printf("%d\t", temp->data);
                temp = temp->right;
            }
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- MATRIX MENU ---\n");
        printf("1. Create Matrix\n");
        printf("2. Display Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
