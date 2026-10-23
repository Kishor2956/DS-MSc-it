
#include <stdio.h>

int blockSize[20], allocated[20];
int n;

/* Best-Fit Allocation */
void allocation()
{
    int processSize, i, best, remaining;

    printf("Enter process size: ");
    scanf("%d", &processSize);

    best = -1;

    for (i = 0; i < n; i++)
    {
        if (allocated[i] == 0 && blockSize[i] >= processSize)
        {
            if (best == -1 || blockSize[i] < blockSize[best])
                best = i;
        }
    }

    if (best == -1)
    {
        printf("Memory allocation failed!\n");
    }
    else
    {
        remaining = blockSize[best] - processSize;
        blockSize[best] = remaining;
        allocated[best] = 0;

        printf("Memory allocated using Best-Fit.\n");
        printf("Block number: %d\n", best + 1);
        printf("Remaining memory in block: %d\n", remaining);
    }
}

/* Deallocation */
void deallocation()
{
    int size, i;

    printf("Enter memory size to deallocate: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size.\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (allocated[i] == 0)
        {
            blockSize[i] = blockSize[i] + size;
            printf("Memory deallocated successfully.\n");
            printf("Block number: %d\n", i + 1);
            return;
        }
    }

    printf("No suitable block found.\n");
}

/* Display Memory Blocks */
void display()
{
    int i;

    printf("\nMemory Blocks:\n");
    printf("Block No.\tAvailable Size\n");

    for (i = 0; i < n; i++)
        printf("%d\t\t%d\n", i + 1, blockSize[i]);
}

int main()
{
    int i, choice;

    printf("Enter number of memory blocks (max 20): ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid number of blocks.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        allocated[i] = 0;
    }

    do
    {
        printf("\n--- BEST-FIT STORAGE ALLOCATION ---\n");
        printf("1. Allocation\n");
        printf("2. Deallocation\n");
        printf("3. Display Memory Blocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                allocation();
                break;

            case 2:
                deallocation();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
