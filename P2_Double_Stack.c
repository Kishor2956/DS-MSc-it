#include <stdio.h>
#define MAX 10

int stack[MAX];

int top1 = -1;
int top2 = MAX;


// Push in Stack 1
void push1()
{
    int value;

    if (top1 + 1 == top2)
    {
        printf("\n Stack Overflow!");
    }
    else
    {
        printf("\n Enter value : ");
        scanf("%d", &value);

        stack[++top1] = value;

        printf("\n Value Inserted in Stack 1.");
    }
}


// Push in Stack 2
void push2()
{
    int value;

    if (top1 + 1 == top2)
    {
        printf("\n Stack Overflow!");
    }
    else
    {
        printf("\n Enter Value : ");
        scanf("%d", &value);

        stack[--top2] = value;

        printf("Value Inserted in Stack 2.");
    }
}


// Pop from Stack 1
void pop1()
{
    if (top1 == -1)
    {
        printf("\n Stack 1 Underflow!");
    }
    else
    {
        printf("\n Deleted Element = %d", stack[top1]);
        top1--;
    }
}


// Pop from Stack 2
void pop2()
{
    if (top2 == MAX)
    {
        printf("\n Stack 2 Underflow!");
    }
    else
    {
        printf("\n Deleted Element = %d", stack[top2]);
        top2++;
    }
}


// Peep Stack 1
void peep1()
{
    if (top1 == -1)
    {
        printf("\n Stack 1 is Empty!");
    }
    else
    {
        printf("\n Top Element of Stack 1 = %d", stack[top1]);
    }
}


// Peep Stack 2
void peep2()
{
    if (top2 == MAX)
    {
        printf("\n Stack 2 is Empty!");
    }
    else
    {
        printf("\n Top Element of Stack 2 = %d", stack[top2]);
    }
}


// Modify Stack 1
void modify1()
{
    int position, value;

    if (top1 == -1)
    {
        printf("\n Stack 1 is Empty!");
    }
    else
    {
        printf("\n Enter Position From Top : ");
        scanf("%d", &position);

        if (position < 1 || position > top1 + 1)
        {
            printf("\n Invalid Position!");
        }
        else
        {
            printf("\n Enter New Value : ");
            scanf("%d", &value);

            stack[top1 - position + 1] = value;

            printf("\n Value Modified Successfully.");
        }
    }
}


// Modify Stack 2
void modify2()
{
    int position, value;

    if (top2 == MAX)
    {
        printf("\n Stack 2 is Empty!");
    }
    else
    {
        printf("\n Enter Position From Top : ");
        scanf("%d", &position);

        if (position < 1 || position > MAX - top2)
        {
            printf("\nInvalid Position!");
        }
        else
        {
            printf("Enter New Value : ");
            scanf("%d", &value);

            stack[top2 + position - 1] = value;

            printf("Value Modified Successfully.");
        }
    }
}


// Display Stack 1
void display1()
{
    int i;

    if (top1 == -1)
    {
        printf("\n Stack 1 is Empty!");
    }
    else
    {
        printf("\n Stack 1: ");

        for (i = top1; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}


// Display Stack 2
void display2()
{
    int i;

    if (top2 == MAX)
    {
        printf("\n Stack 2 is Empty!");
    }
    else
    {
        printf("\n Stack 2: ");

        for (i = top2; i < MAX; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}


// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== DOUBLE STACK MENU =====");

        printf("\n1. Push Stack 1");
        printf("\n2. Push Stack 2");

        printf("\n3. Pop Stack 1");
        printf("\n4. Pop Stack 2");

        printf("\n5. Peep Stack 1");
        printf("\n6. Peep Stack 2");

        printf("\n7. Modify Stack 1");
        printf("\n8. Modify Stack 2");

        printf("\n9. Display Stack 1");
        printf("\n10. Display Stack 2");

        printf("\n11. Exit");

        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push1();
                break;

            case 2:
                push2();
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                peep1();
                break;

            case 6:
                peep2();
                break;

            case 7:
                modify1();
                break;

            case 8:
                modify2();
                break;

            case 9:
                display1();
                break;

            case 10:
                display2();
                break;

            case 11:
                return 0;

            default:
                printf("\n Invalid Choice!");
        }
    }

    return 0;
}