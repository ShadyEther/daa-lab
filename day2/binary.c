// binary search
#include <stdio.h>
#include <stdlib.h>
int steps = 0;
void inSort(int *arr, int size)
{ // insertion sort
    int key;
    for (int i = 1; i < size; i++) // iterate through every position...n times
    {
        key = arr[i]; // put ith element in key
        int j = i - 1;
        for (; j >= 0 && arr[j] > key; j--) // shift larger elements  one step to right until a element smaller than key is found
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key; // replace the element immediately right of the smaller elemnt with the key value
    }
}
int binarySearch(int *arr, int low, int high, int key)
{
    steps++;
    if (high >= low)//as long as high is greater than equal to low
    {
        int mid = low + (high - low) / 2;//mid
        if (arr[mid] == key)//check mid if found..return
            return mid;
        else if (arr[mid] < key)//if mid smaller..then check right half
            binarySearch(arr, mid + 1, high, key);
        else if (arr[mid] > key)//if mid greater then check left half
            binarySearch(arr, low, mid - 1, key);
        
    }
    else
        return -1;
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
    inSort(arr, size);

    printf("\nSorted array---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    int binarysearch = binarySearch(arr, 0, size - 1, key);
    if (binarysearch == -1)
        printf("Element not found\n");
    else
        printf("Element found at position arr[%d]\n", binarysearch);

    printf("Steps: %d", steps);
}