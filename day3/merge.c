// merge sort
#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int low, int mid, int high)
{
    int left[mid - low], right[high - mid];
    int k = low;
    for (int i = 0; i < mid - low; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < high - mid; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i,j;
    for ( i = 0, j = 0; i < mid - low && j < high - mid;)
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
    while(i<mid-low)
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
void mergeSort(int* arr , int n)
int main()
{
}