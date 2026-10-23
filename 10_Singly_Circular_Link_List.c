#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void insert(struct node **head, int value);
void deleteNode(struct node **head, int value);
void modify(struct node *head, int oldValue, int newValue);
void display(struct node *head);


// Insert
void insert(struct node **head, int value)
{
    struct node *newNode;
    struct node *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->info = value;

    // Empty list
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        temp = *head;

        while (temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head;
    }

    printf("\nValue inserted successfully.");
}


// Delete
void deleteNode(struct node **head, int value)
{
    struct node *temp;
    struct node *prev;

    if (*head == NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }

    // Delete first node
    if ((*head)->info == value)
    {
        temp = *head;

        // Only one node
        if (temp->next == *head)
        {
            *head = NULL;
        }
        else
        {
            prev = *head;

            while (prev->next != *head)
            {
                prev = prev->next;
            }

            *head = temp->next;
            prev->next = *head;
        }

        free(temp);

        printf("\nValue deleted successfully.");
        return;
    }

    // Search node
    prev = *head;
    temp = (*head)->next;

    while (temp != *head && temp->info != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == *head)
    {
        printf("\nValue Not Found!");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("\nValue deleted successfully.");
}


// Modify
void modify(struct node *head, int oldValue, int newValue)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }

    temp = head;

    do
    {
        if (temp->info == oldValue)
        {
            temp->info = newValue;

            printf("\nValue modified successfully.");
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("\nValue Not Found!");
}


// Display
void display(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }

    printf("\nCircular Linked List: ");

    temp = head;

    do
    {
        printf("%d ", temp->info);

        temp = temp->next;

    } while (temp != head);

    printf("\n");
}


// Main Function
int main()
{
    struct node *head = NULL;

    int choice;
    int value;
    int newValue;

    while (1)
    {
        printf("\n\n===== SINGLY CIRCULAR LINKED LIST =====");

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

                printf("\nEnter value: ");
                scanf("%d", &value);

                insert(&head, value);

                break;


            case 2:

                printf("\nEnter value to delete: ");
                scanf("%d", &value);

                deleteNode(&head, value);

                break;


            case 3:

                printf("\nEnter old value: ");
                scanf("%d", &value);

                printf("Enter new value: ");
                scanf("%d", &newValue);

                modify(head, value, newValue);

                break;


            case 4:

                display(head);

                break;


            case 5:

                return 0;


            default:

                printf("\nInvalid Choice!");
        }
    }

    return 0;
}