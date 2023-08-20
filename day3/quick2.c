#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int size, key;
    printf("Enter the number of elements in array: ");
    scanf("%d", &size);
    // creating an array with random numbers between 1 to n
    int *arr = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 0;
    }
    printf("\nGenerated Unsorted array---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorted array---\n");
    quickSort(arr, 0, size - 1);
    printf("\nSorted array---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr); // Don't forget to free the allocated memory.

    return 0;
}
