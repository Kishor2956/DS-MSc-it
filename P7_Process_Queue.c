#include <stdio.h>
#include <stdlib.h>

void process_insert(int [], int *, int *, int);
int process_delete(int [], int *, int *);

int main()
{
    int q[10], f = -1, r = -1;

    int process[5] = {5, 7, 4, 8, 3};

    int i = 0;
    int val = 0;
    int count = 5;

    // Insert all processes into queue
    for (i = 0; i < 5; i++)
    {
        process_insert(q, &f, &r, process[i]);
    }

    i = 0;

    // Execute processes
    while (count != 0)
    {
        val = process_delete(q, &f, &r);

        if (val != -1)
        {
            printf("\nProcess %d : ", i + 1);

            if (val > 2)
            {
                val = val - 2;

                printf("\n2 Unit Executed");
            }
            else
            {
                printf("\n%d Unit Executed", val);

                val = 0;
                count--;
            }

            // Insert process again if remaining
            if (val != 0)
            {
                process_insert(q, &f, &r, val);
            }
        }

        i++;

        if (i == 5)
        {
            i = 0;
        }
    }

    printf("\n\nAll Process Executed");

    return 0;
}


// Process Insert
void process_insert(int q[], int *f, int *r, int val)
{
    // Check Queue Full
    if (*r == *f - 1 || (*f == 0 && *r == 9))
    {
        printf("\nQueue is Full");
        return;
    }

    // Circular insertion
    if (*r == 9 && *f != 0)
    {
        *r = 0;
    }
    else
    {
        *r = *r + 1;
    }

    // First element
    if (*f == -1)
    {
        *f = 0;
    }

    q[*r] = val;
}


// Process Delete
int process_delete(int q[], int *f, int *r)
{
    int temp;

    // Check Queue Empty
    if (*f == -1)
    {
        printf("\nQueue Is Empty");
        return -1;
    }

    temp = q[*f];

    // Only one element
    if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }

    // Circular deletion
    else if (*f == 9)
    {
        *f = 0;
    }
    else
    {
        *f = *f + 1;
    }

    return temp;
}


// Process Display
void process_display(int q[], int *f, int *r)
{
    int i;

    i = *f;

    while (i != *r)
    {
        printf("\n%d", q[i]);

        if (i == 9)
        {
            i = 0;
        }
        else
        {
            i = i + 1;
        }
    }

    printf("\n%d", q[i]);
}