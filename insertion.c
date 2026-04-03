#include<stdio.h>
#include<windows.h>
void printArray();
void insertion_sort();
void main()
{
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);

    int arr[size];
    for ( int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array: ");
    printArray(arr,size); 
    LARGE_INTEGER frequency;  // ticks per second
    LARGE_INTEGER start, end; // tick counts
    double elapsedTime;

    // Get frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Record start time
    QueryPerformanceCounter(&start);

    insertion_sort(arr,size);

    printf("\nThe sorted array: ");
    printArray(arr,size); 
     // Record end time
    QueryPerformanceCounter(&end);

    // Calculate elapsed time in seconds
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // Convert to microseconds
    double microseconds = elapsedTime * 1e6;

    printf("Insertion Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);
        
}

void printArray(int arr[],int size)
{ 
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
}

void insertion_sort(int arr[],int size)
{
    int key;
    int j;
    for(int i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;
        while (key<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}