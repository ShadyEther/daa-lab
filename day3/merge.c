// merge sort
#include <stdio.h>
#include <stdlib.h>
int steps=0;
void merge(int *arr, int low, int mid, int high)
{
    int left[mid - low], right[high - mid];
    int k = low;
    for (int i = 0; i < mid - low+1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < high - mid; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i,j;
    for ( i = 0, j = 0; i < mid - low+1 && j < high - mid;)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<mid-low+1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<high-mid)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergeSort(int* arr , int low, int high)
{
    if(low<high)
    {
        steps++;
        int mid=low + (high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergeSort(arr,0,size-1);
    printf("\nSorted array---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nsteps: %d\n",steps);
}