
#include <stdio.h>

int main()
{
    int arr[100], n, i, choice, key;
    int low, high, mid, found, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n--- SEARCH MENU ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (arr[i] == key)
                    {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Element not found.\n");

                break;

            case 2:
                /* Sort array for binary search */
                for (i = 0; i < n - 1; i++)
                {
                    for (low = 0; low < n - i - 1; low++)
                    {
                        if (arr[low] > arr[low + 1])
                        {
                            temp = arr[low];
                            arr[low] = arr[low + 1];
                            arr[low + 1] = temp;
                        }
                    }
                }

                printf("Sorted array: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);

                printf("\nEnter element to search: ");
                scanf("%d", &key);

                low = 0;
                high = n - 1;
                found = 0;

                while (low <= high)
                {
                    mid = low + (high - low) / 2;

                    if (arr[mid] == key)
                    {
                        printf("Element found at position %d in sorted array\n",
                               mid + 1);
                        found = 1;
                        break;
                    }
                    else if (arr[mid] < key)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }

                if (found == 0)
                    printf("Element not found.\n");

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
