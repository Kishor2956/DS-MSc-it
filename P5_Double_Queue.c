#include <stdio.h>
#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;


// Insert from Front
void insertFront()
{
    int value;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("\n Queue Overflow!");
        return;
    }

    printf("\n Enter Value : ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    queue[front] = value;

    printf("\n Value Inserted From Front.");
}

// Insert from Rear
void insertRear()
{
    int value;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("\n Queue Overflow!");
        return;
    }

    printf("\n Enter Value : ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = value;

    printf("\n Value Inserted From Rear.");
}

// Delete from Front
void deleteFront()
{
    if (front == -1)
    {
        printf("\n Queue Underflow!");
        return;
    }

    printf("\n Deleted Element = %d", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Delete from Rear
void deleteRear()
{
    if (front == -1)
    {
        printf("\n Queue Underflow!");
        return;
    }

    printf("\n Deleted Element = %d", queue[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
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
        printf("\n Invalid Position!");
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

        if (index == MAX - 1)
            index = 0;
        else
            index++;
    }

    printf("Enter New Value: ");
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
        printf("\n Queue is Empty!");
        return;
    }

    printf("\n Queue Elements : ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        if (i == MAX - 1)
            i = 0;
        else
            i++;
    }

    printf("\n");
}


// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== DOUBLE QUEUE MENU =====");

        printf("\n1. Insert from Front");
        printf("\n2. Insert from Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Modify");
        printf("\n6. Display");
        printf("\n7. Exit");

        printf("\n\n Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                modify();
                break;

            case 6:
                display();
                break;

            case 7:
                return 0;

            default:
                printf("\n Invalid Choice!");
        }
    }

    return 0;
}