#include<stdio.h>
#include<windows.h>
// void print_array(int arr[],int size);
void swap(int *a,int *b);
int partition();
void print_array();
void Quick_sort();
void main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter the element %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array is: ");
    print_array(arr,size);
    //call quicksort
    LARGE_INTEGER frequency;  // ticks per second
    LARGE_INTEGER start, end; // tick counts
    double elapsedTime;

    // Get frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Record start time
    QueryPerformanceCounter(&start);

    Quick_sort(arr,0,size-1);
    printf("\n The sorted array (Quick Sort):");
    print_array(arr,size);
     // Record end time
    QueryPerformanceCounter(&end);

    // Calculate elapsed time in seconds
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // Convert to microseconds
    double microseconds = elapsedTime * 1e6;

    printf("Insertion Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);

}//end of main

void print_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d " ,arr[i]);
    }

}//end of print_array

void Quick_sort(int arr[],int L,int H)
{
    if(L<H)
    {
        int p = partition(arr,L,H);
        Quick_sort(arr,L,p-1);
        Quick_sort(arr,p+1,H);
    }
}



int partition(int arr[],int L,int H)
{
    int pivot=arr[H];
    int j=L-1;
    for(int i=L; i<H; i++)
    {
        if(arr[i]<=pivot)
        {
            j++;
            swap(&arr[i],&arr[j]);
        }
        
    }
    swap(&arr[j+1],&arr[H]);

    return j+1;

}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}