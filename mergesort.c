#include<stdio.h>
#include<windows.h>
void print_array();
void merge_sort();
void merge();

void main()
{
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);

    int arr[size];
    for(int i=0; i<size; i++)
    {
        printf("Enter the element %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("The unsorted Array is: ");
    print_array(arr,size);
    LARGE_INTEGER frequency;  // ticks per second
    LARGE_INTEGER start, end; // tick counts
    double elapsedTime;

    // Get frequency of the performance counter
    QueryPerformanceFrequency(&frequency);

    // Record start time
    QueryPerformanceCounter(&start);
    merge_sort(arr,0, size-1);
    printf("\nThe sorted Array is: ");
    print_array(arr,size);
     // Record end time
    QueryPerformanceCounter(&end);

    // Calculate elapsed time in seconds
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // Convert to microseconds
    double microseconds = elapsedTime * 1e6;

    printf("Insertion Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);
        
}//end of main

void print_array(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

void merge_sort(int arr[],int l, int r)
{
    int size=(r-l)+1;
    int mid =size/2;
    int j=0;
    int left_array[mid];
    int right_array[size-mid];
    if(size<=1)
        return; // stopping condition to stop forever loop 
    for(int i=0;i<size;i++)
    {
        if(i<mid)
            left_array[i]=arr[i];   
        else
        {
            right_array[j]=arr[i];
            j++;   
        }
    }
    printf("\nElement in left array : ");
    print_array(left_array,mid);
    printf("\nElement in right array : ");
    print_array(right_array,size-mid);

    merge_sort(left_array,l,(mid-1)+l);
    merge_sort(right_array,mid+l,r); 
    int l_arrSize=sizeof(left_array)/sizeof(left_array[0]);
    int R_arrSize=sizeof(right_array)/sizeof(right_array[0]);
    merge(left_array,l_arrSize,right_array,R_arrSize,arr);
    
}

void merge(int left_array[],int l_arrSize,int right_array[],int R_arrSize,int sorted_array[])
{
    
    // int l_arrSize=sizeof(left_array)/sizeof(left_array[0]);
    printf("\nsize of the Left array %d",l_arrSize);
    // int R_arrSize=sizeof(right_array)/sizeof(right_array[0]);
    printf("\nsize of the Right array %d",R_arrSize);

    int l,r,i;
    l=r=i=0;

    while(l<l_arrSize && r<R_arrSize)
        if(left_array[l]<right_array[r])
        {
            sorted_array[i]=left_array[l];
            i++;
            l++;
        }
        else
        {
            sorted_array[i]=right_array[r];
            i++;
            r++;
        }

    while(l<l_arrSize)
    {
        sorted_array[i]=left_array[l];
        i++;
        l++;
    }

    while(r<R_arrSize)
    {
        sorted_array[i]=right_array[r];
        i++;
        r++;
    }
}