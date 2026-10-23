
#include <stdio.h>

int getMax(int arr[], int n)
{
    int i, max;

    max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10];
    int i, index;

    for (i = 0; i < 10; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
    {
        index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max, exp;

    max = getMax(arr, n);

    for (exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
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

    radixSort(arr, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
