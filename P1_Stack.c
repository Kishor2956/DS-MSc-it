#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push Operation
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("\n Stack Overflow!");
    }
    else
    {
        printf("\n Enter Value : ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d Inserted Successfully.", value);
    }
}

// Pop Operation
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\n Deleted Element = %d", stack[top]);
        top--;
    }
}

// Peep Operation
void peep()
{
    if (top == -1)
    {
        printf("\n Stack is Empty!");
    }
    else
    {
        printf("\n Top Element = %d", stack[top]);
    }
}

// Modify Operation
void modify()
{
    int position, value;

    if (top == -1)
    {
        printf("\n Stack is Empty!");
    }
    else
    {
        printf("\n Enter Position From Top : ");
        scanf("%d", &position);

        if (position < 1 || position > top + 1)
        {
            printf("\n Invalid Position!");
        }
        else
        {
            printf("Enter New Value : ");
            scanf("%d", &value);

            stack[top - position + 1] = value;

            printf("\n Value Modified Successfully.");
        }
    }
}

// Display Operation
void display()
{
    int i;

    if (top == -1)
    {
        printf("\n Stack is Empty!");
    }
    else
    {
        printf("\n Stack Elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== STACK MENU =====");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peep");
        printf("\n4. Modify");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\n Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                modify();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("\n Invalid Choice!");
        }
    }

    return 0;
} 
