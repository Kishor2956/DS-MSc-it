#include <stdio.h>
#include <stdlib.h>

void priority_insert(int [], int *, int *, int);
int priority_delete(int [], int *, int *);
void priority_display(int [], int *, int *);


int main()
{
    int p1[10], p2[10], p3[10];

    int f1 = -1, r1 = -1;
    int f2 = -1, r2 = -1;
    int f3 = -1, r3 = -1;

    int ch, val, priority, deleteVal;

    do
    {
        printf("\n\n===== PRIORITY QUEUE =====");

        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:

                printf("\nEnter Value: ");
                scanf("%d", &val);

                printf("Enter Priority (1, 2, 3): ");
                scanf("%d", &priority);

                if(priority == 1)
                {
                    priority_insert(p1, &f1, &r1, val);
                }
                else if(priority == 2)
                {
                    priority_insert(p2, &f2, &r2, val);
                }
                else if(priority == 3)
                {
                    priority_insert(p3, &f3, &r3, val);
                }
                else
                {
                    printf("\nInvalid Priority!");
                }

                break;


            case 2:

                if(f1 != -1)
                {
                    deleteVal = priority_delete(p1, &f1, &r1);
                    printf("\nDeleted Value = %d", deleteVal);
                }
                else if(f2 != -1)
                {
                    deleteVal = priority_delete(p2, &f2, &r2);
                    printf("\nDeleted Value = %d", deleteVal);
                }
                else if(f3 != -1)
                {
                    deleteVal = priority_delete(p3, &f3, &r3);
                    printf("\nDeleted Value = %d", deleteVal);
                }
                else
                {
                    printf("\nQueue is Empty!");
                }

                break;


            case 3:

                printf("\n\nPriority 1 Queue:");
                priority_display(p1, &f1, &r1);

                printf("\n\nPriority 2 Queue:");
                priority_display(p2, &f2, &r2);

                printf("\n\nPriority 3 Queue:");
                priority_display(p3, &f3, &r3);

                break;


            case 4:
                exit(0);


            default:
                printf("\nInvalid Choice!");
        }

    } while(1);

    return 0;
}


// Insert into Priority Queue
void priority_insert(int p[], int *f, int *r, int val)
{
    if(*r == 9)
    {
        printf("\nQueue is Full!");
        return;
    }

    *r = *r + 1;

    if(*f == -1)
    {
        *f = 0;
    }

    p[*r] = val;

    printf("\nValue inserted successfully.");
}


// Delete from Priority Queue
int priority_delete(int p[], int *f, int *r)
{
    int temp;

    if(*f == -1)
    {
        printf("\nQueue is Empty!");
        return -1;
    }

    temp = p[*f];

    if(*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        *f = *f + 1;
    }

    return temp;
}


// Display Priority Queue
void priority_display(int p[], int *f, int *r)
{
    int i;

    if(*f == -1)
    {
        printf("\nQueue is Empty!");
        return;
    }

    i = *f;

    while(i <= *r)
    {
        printf("\n%d", p[i]);
        i++;
    }
}