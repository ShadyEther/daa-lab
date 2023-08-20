//insertion sort
#include<stdio.h>
#include<stdlib.h>//for calloc and rand() function

int main()
{
    int size,key,steps=0;//key for key element..steps for no of steps
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int *arr=calloc(size,sizeof(int));
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%100 + 0;// number generated from 0 to 100
    }
    printf("\nUnSorted array---\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    for(int i=1;i<size;i++)//iterate through every position...n times
    {
        key=arr[i];//put ith element in key
        int j=i-1;
        for(;j>=0&&arr[j]>key;j--)//shift larger elements  one step to right until a element smaller than key is found
        {
            arr[j+1]=arr[j];
            steps++;
        }
        arr[j+1]=key;//replace the element immediately right of the smaller elemnt with the key value
    }
    printf("\nSorted array---\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nSteps: %d",steps);

}