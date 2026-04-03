#include<stdio.h>
#include<windows.h>
void bubblesort();
void display_array();
void main()
{
    int arrsize;
    printf("Enter the Array size: ");
    scanf("%d",&arrsize);
    int i;
    int arr[arrsize];
    for ( i = 0; i < arrsize; i++)
    {
        printf("Enter the  %d element: ",i);
        scanf("%d",&arr[i]);
    }
    printf("the unsorted array:");
    display_array(arr,arrsize);
    
    LARGE_INTEGER frequency;  // ticks per second
    LARGE_INTEGER start, end; // tick counts
    double elapsedTime;

    // Get frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Record start time
    QueryPerformanceCounter(&start);
    
    bubblesort(arr,arrsize);
    
    printf("\nThe sorted array:");
    display_array(arr,arrsize);
    // Record end time
    QueryPerformanceCounter(&end);

    // Calculate elapsed time in seconds
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // Convert to microseconds
    double microseconds = elapsedTime * 1e6;

    printf("Bubble Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);

    
} // end of main

void display_array(int arr[],int arrsize)
{
    for ( int i = 0; i < arrsize; i++)
    printf("%d ",arr[i]);
}

void bubblesort(int arr[],int arrsize)
{ int swap_count=0;
 for (int i=0;i<arrsize;i++)
 {
    for(int j=0;j<arrsize-i-1;j++)
    {
        if(!(arr[j]< arr[j+1]))
        {
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            swap_count++;
        }
    }
    printf("\n Pass %d: ",i);
    for ( int k = 0; k < arrsize; k++)
    printf("%d ",arr[k]);
    
 }
 printf("\nnumber of swap = %d",swap_count);
}