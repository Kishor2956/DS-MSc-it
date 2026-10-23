
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *down;
};

struct node *createMatrix(int r, int c)
{
    struct node *head, *rowHead, *newnode;
    struct node *prevRow[50];
    struct node *prev;

    int i, j, value;

    head = NULL;

    for (i = 0; i < r; i++)
    {
        rowHead = NULL;
        prev = NULL;

        for (j = 0; j < c; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &value);

            newnode = (struct node *)malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("Memory allocation failed.\n");
                return head;
            }

            newnode->data = value;
            newnode->right = NULL;
            newnode->down = NULL;

            if (rowHead == NULL)
                rowHead = newnode;
            else
                prev->right = newnode;

            if (i > 0)
                prevRow[j]->down = newnode;

            prevRow[j] = newnode;
            prev = newnode;
        }

        if (head == NULL)
            head = rowHead;
    }

    return head;
}

void displayMatrix(struct node *head, int r, int c)
{
    struct node *row, *temp;
    int i, j;

    row = head;

    for (i = 0; i < r; i++)
    {
        temp = row;

        for (j = 0; j < c; j++)
        {
            printf("%d\t", temp->data);
            temp = temp->right;
        }

        printf("\n");

        if (row != NULL)
            row = row->down;
    }
}

void addMatrix()
{
    struct node *A, *B, *C;
    struct node *rowA, *rowB, *rowC;
    struct node *tempA, *tempB, *tempC;
    int r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    if (r <= 0 || c <= 0 || r > 50 || c > 50)
    {
        printf("Invalid matrix size.\n");
        return;
    }

    printf("Enter Matrix A:\n");
    A = createMatrix(r, c);

    printf("Enter Matrix B:\n");
    B = createMatrix(r, c);

    C = NULL;
    rowA = A;
    rowB = B;
    rowC = NULL;

    for (i = 0; i < r; i++)
    {
        tempA = rowA;
        tempB = rowB;
        tempC = NULL;

        for (j = 0; j < c; j++)
        {
            struct node *newnode;

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = tempA->data + tempB->data;
            newnode->right = NULL;
            newnode->down = NULL;

            if (tempC == NULL)
            {
                if (C == NULL)
                    C = newnode;
                rowC = newnode;
            }
            else
                tempC->right = newnode;

            tempC = newnode;
            tempA = tempA->right;
            tempB = tempB->right;
        }

        if (i < r - 1)
        {
            struct node *pA, *pB, *pC;

            pA = rowA;
            pB = rowB;
            pC = rowC;

            while (pA != NULL && pB != NULL && pC != NULL)
            {
                pA->down = pA->down;
                pB->down = pB->down;
                pC = pC->right;
                pA = pA->right;
                pB = pB->right;
            }
        }

        if (i == 0)
            C = rowC;

        rowA = rowA->down;
        rowB = rowB->down;
    }

    /* Display sum using a simple array-based calculation */
    printf("Matrix Addition Result:\n");

    {
        int a[50][50], b[50][50];

        rowA = A;
        rowB = B;

        for (i = 0; i < r; i++)
        {
            tempA = rowA;
            tempB = rowB;

            for (j = 0; j < c; j++)
            {
                a[i][j] = tempA->data;
                b[i][j] = tempB->data;
                tempA = tempA->right;
                tempB = tempB->right;
            }

            rowA = rowA->down;
            rowB = rowB->down;
        }

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
                printf("%d\t", a[i][j] + b[i][j]);

            printf("\n");
        }
    }
}

void multiplyMatrix()
{
    int A[50][50], B[50][50], C[50][50];
    int r1, c1, r2, c2, i, j, k;
    struct node *headA, *headB, *row, *temp;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
        r1 > 50 || c1 > 50 || r2 > 50 || c2 > 50)
    {
        printf("Invalid matrix size.\n");
        return;
    }

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return;
    }

    printf("Enter Matrix A:\n");
    headA = createMatrix(r1, c1);

    printf("Enter Matrix B:\n");
    headB = createMatrix(r2, c2);

    row = headA;

    for (i = 0; i < r1; i++)
    {
        temp = row;

        for (j = 0; j < c1; j++)
        {
            A[i][j] = temp->data;
            temp = temp->right;
        }

        row = row->down;
    }

    row = headB;

    for (i = 0; i < r2; i++)
    {
        temp = row;

        for (j = 0; j < c2; j++)
        {
            B[i][j] = temp->data;
            temp = temp->right;
        }

        row = row->down;
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("Matrix Multiplication Result:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d\t", C[i][j]);

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- MATRIX MENU ---\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addMatrix();
                break;

            case 2:
                multiplyMatrix();
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
