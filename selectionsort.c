#include<stdio.h>
#include<windows.h>
void arry_display();
void selection_sort();
void main()
{    
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
     int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter the element of the array %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("The Unsorted Array: ");
    arry_display(arr,size);
    LARGE_INTEGER frequency;  // ticks per second
    LARGE_INTEGER start, end; // tick counts
    double elapsedTime;
    // Get frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Record start time
    QueryPerformanceCounter(&start);
    selection_sort(arr,size);
    printf("\nThe Sorted Array: ");
    arry_display(arr,size);
    
    QueryPerformanceCounter(&end);

    // Calculate elapsed time in seconds
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // Convert to microseconds
    double microseconds = elapsedTime * 1e6;

    printf("Selection Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);
}

void arry_display(int arr[],int size)
{
    for ( int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void selection_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
       int min_index=i;
        for(int j=i+1; j<size;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}