#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;


// Insert Operation
void insert()
{
    int value;

    // Check Overflow
    if ((rear + 1) % MAX == front)
    {
        printf("\n Queue Overflow!");
        return;
    }

    printf("\n Enter Value : ");
    scanf("%d", &value);

    // First element
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d Inserted Successfully.", value);
}


// Delete Operation
void delete()
{
    if (front == -1)
    {
        printf("\n Queue Underflow!");
        return;
    }

    printf("\n Deleted Element = %d", queue[front]);

    // Only one element
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}


// Modify Operation
void modify()
{
    int position, value;
    int i, index;

    if (front == -1)
    {
        printf("\n Queue is Empty!");
        return;
    }

    printf("\n Enter Position from Front: ");
    scanf("%d", &position);

    if (position < 1 || position > MAX)
    {
        printf("\nInvalid Position!");
        return;
    }

    index = front;

    for (i = 1; i < position; i++)
    {
        if (index == rear)
        {
            printf("\n Invalid Position!");
            return;
        }

        index = (index + 1) % MAX;
    }

    printf("Enter New Value : ");
    scanf("%d", &value);

    queue[index] = value;

    printf("\n Value Modified Successfully.");
}

// Display Operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nCircular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}


// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== CIRCULAR QUEUE MENU =====");

        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}