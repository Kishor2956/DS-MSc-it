#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void insert_sl(struct node **head, int val);
void delete_sl(struct node **head, int val);
void modify_sl(struct node **head, int val, int newVal);
void display_sl(struct node *head);


int main()
{
    struct node *head = NULL;

    int val, newVal, ch;

    while (1)
    {
        printf("\n\n===== SINGLY LINKED LIST =====");

        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter Value: ");
                scanf("%d", &val);

                insert_sl(&head, val);
                break;


            case 2:
                printf("\nEnter Value For Delete: ");
                scanf("%d", &val);

                delete_sl(&head, val);
                break;


            case 3:
                printf("\nEnter Value For Modify: ");
                scanf("%d", &val);

                printf("Enter New Value: ");
                scanf("%d", &newVal);

                modify_sl(&head, val, newVal);
                break;


            case 4:
                display_sl(head);
                break;


            case 5:
                return 0;


            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}


// Insert Operation
void insert_sl(struct node **head, int val)
{
    struct node *nd;
    struct node *t1;
    struct node *t2 = NULL;

    nd = (struct node *)malloc(sizeof(struct node));

    nd->info = val;
    nd->next = NULL;


    // Empty List
    if (*head == NULL)
    {
        *head = nd;
    }

    // Insert at Beginning
    else if ((*head)->info > val)
    {
        nd->next = *head;
        *head = nd;
    }

    // Insert at Proper Position
    else
    {
        t1 = *head;

        while (t1 != NULL && t1->info < val)
        {
            t2 = t1;
            t1 = t1->next;
        }

        t2->next = nd;
        nd->next = t1;
    }

    printf("\nValue inserted successfully.");
}


// Delete Operation
void delete_sl(struct node **head, int val)
{
    struct node *temp;
    struct node *t1;
    struct node *t2 = NULL;


    if (*head == NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }


    // Delete First Node
    if ((*head)->info == val)
    {
        temp = *head;

        *head = (*head)->next;

        free(temp);

        printf("\nValue deleted successfully.");

        return;
    }


    // Search Node
    t1 = *head;

    while (t1 != NULL && t1->info != val)
    {
        t2 = t1;
        t1 = t1->next;
    }


    // Value Not Found
    if (t1 == NULL)
    {
        printf("\nValue Not Found!");
        return;
    }


    // Delete Node
    t2->next = t1->next;

    free(t1);

    printf("\nValue deleted successfully.");
}


// Modify Operation
void modify_sl(struct node **head, int val, int newVal)
{
    struct node *ptr;

    ptr = *head;


    if (ptr == NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }


    // Search Value
    while (ptr != NULL && ptr->info != val)
    {
        ptr = ptr->next;
    }


    // Value Not Found
    if (ptr == NULL)
    {
        printf("\nValue Not Found!");
        return;
    }


    // Modify Value
    ptr->info = newVal;

    printf("\nValue modified successfully.");
}


// Display Operation
void display_sl(struct node *head)
{
    struct node *ptr;

    ptr = head;


    if (ptr == NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }


    printf("\nLinked List: ");

    while (ptr != NULL)
    {
        printf("%d ", ptr->info);

        ptr = ptr->next;
    }
}