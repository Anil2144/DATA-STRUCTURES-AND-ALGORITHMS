/*Implementation of heap using array*/
/*
2 heaps: 1. Max heap: parent > children
         2. Min heap: parent < children
*/
/*
    2i and 2i+1 are the children
    just divide by 2 so as to find the parent
    we use array indexing from 1 for our convinence
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void heapify(int arr[], int N, int  i)
{
    // from random binaey tree to heap
    // try to find the bigger value among 2i and 2i+1 and swap with i
    // repeat this process until all the array is set
    int largest = i,temp;
    int left = 2*i;
    int right = 2*i+1;
    if(left <= N && arr[left] > arr[largest])
        largest = left;
    if(right<= N && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        printf(",,,,,,,,,,,,");
       // arr[i] = arr[i]+arr[largest]-(arr[largest]=arr[i]);
       // swap(arr[i],arr[largest]);
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        printf(",,,,,,,,,,,,..............");
        heapify(arr,N,largest);
    }
}
bool isHeap(int arr[], int N)
{
     // so as to check array is max heap or not
     // Takes input of the complete binary tree
    for(int i = 1; i <=N/2; i++)
    {
        if(arr[2*i]>arr[i])
            return false;
        if(arr[2*i+1] > arr[i] && (2*i+1)<=N)
            return false;
    }
    return true;
}
void heapsort(int arr[], int N)
{
    for(int i = 1; i <= N/2; i++)
    {
        heapify(arr,N,i);
    }
    for(int i = N; i>=1; i--)
    {
        arr[1] = arr[1]+arr[i]-(arr[i]=arr[1]);
        heapify(arr,i-1,1);
    }
}
int main(void)
{
    int N,a[100],ch;
    bool value;
    while (1)
    {
        printf("\n********What you wanna do?********\n\t");
        printf("0.Exit\n\t");
        printf("1.isHeap\n\t");
        printf("2.heapify\n\t");
        printf("3.Heap sort\n\t");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Enter the size of the array: ");
            scanf("%d",&N);
            printf("Enter the elements of the array: ");
            for(int i = 1; i <= N; i++)
                scanf("%d",&a[i]);
            value = isHeap(a,N);
            (value == true)?printf("Yes it is max heap")
                           : printf("No! It is not a max heap");
            break;
        case 2:
            printf("Enter the size of the array: ");
            scanf("%d",&N);
            printf("Enter the elements of the array: ");
            for(int i = 1; i <= N; i++)
                scanf("%d",&a[i]);
            for(int i = 1; i <= N/2; i++ )
            heapify(a,N,i);
            value = isHeap(a,N);
            (value == true)?printf("Yes it is max heap\n")
                           : printf("No! It is not a max heap\n");
            for(int i = 1; i <= N; i++)
            printf("%d,",a[i]);
            break;
        case 3:
            printf("Enter the size of the array: ");
            scanf("%d",&N);
            printf("Enter the elements of the array: ");
            for(int i = 1; i <= N; i++)
                scanf("%d",&a[i]);
            heapsort(a,N);
            for(int i = 1; i <= N; i++)
                printf("%d, ",a[i]);
            break;
        default:
            break;
        }
    }
    return 0;
}
void swap(int *a,int *b)
{
    int *c;
    *c=*a;
    *a=*b;
    *b=*c;
}
