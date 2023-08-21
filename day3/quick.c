#include <stdio.h>
#include <stdlib.h>
int steps=0;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        
        do{
            i++;
        }
        while (arr[i] <= pivot);
        do
        {
            j--;
        }
        while (arr[j] > pivot);
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[low]);
    return j; // returns pivotal position
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        steps++;
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
    quickSort(arr, 0, size);
    printf("\nSorted array---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr); // Don't forget to free the allocated memory.
    printf("\nSteps: %d\n",steps);

    return 0;
}
