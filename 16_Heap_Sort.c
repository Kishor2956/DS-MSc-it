
#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest, left, right, temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;

    /* Build max heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Extract elements from heap */
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[100], n, i;

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

    heapSort(arr, n);

    printf("Sorted array in ascending order:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
