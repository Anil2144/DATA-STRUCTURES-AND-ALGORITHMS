#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void show(int heap[20],int n)
{
	int i;
	for(i=1;i<=n;i++)
	printf("%d\t",heap[i]);
	printf("\n");
}
void heapify(int heap[20],int n,int start)
{
	int f=0,i,t,j;
	for(i=start;i<=n/2 ;i++)
	{
		if(2*i+1<=n)
		{
			if(heap[i]<heap[2*i] || heap[i]<heap[2*i+1])
			{
				f=1;
				if(heap[2*i]>heap[2*i+1])
				swap(&heap[i],&heap[2*i]);
				else
				swap(&heap[i],&heap[2*i+1]);
			}
		}
		else
		{
			if(heap[i]<heap[2*i])
			{
				f=1;
				swap(&heap[i],&heap[2*i]);
			}	
		}
	}
	if(f==1)
	heapify(heap,n,1);
}	
void heapsort(int heap[20],int start,int last,int n)
{
	heapify(heap,last,start);
	if(last>1)
	{
		swap(&heap[start],&heap[last]);
		heapsort(heap,start,last-1,n);
	}
}
int delete(int heap[20],int n)
{
	if(n==0)
	printf("No Elements to delete\n");
	else
	{
		heapify(heap,n,1);
		swap(&heap[1],&heap[n]);
		printf("%d is deleted successfully\n",heap[n]);
		heapify(heap,n-1,1);
		return n-1;
	}
	return 0;
}	
void main()
{
	int heap[20],i,op,n;
	printf("Enter Size of array");
	scanf("%d",&n);
	printf("Enter array\t");
	for(i=1;i<=n;i++)
	scanf("%d",&heap[i]);
	while(op!=5)
	{
		printf("Enter Option\t1.Heapify\t2.Heap sort\t3.Insert and sort\t4.Delete\t5.Exit\n");
		scanf("%d",&op);
	switch(op)
	{
		case 1 : heapify(heap,n,1);
				printf("Array after heapifying\n");
				show(heap,n);
				break;
		case 2 : heapsort(heap,1,n,n);
				printf("Sorted Order of given array\n");
				show(heap,n);
				break;
		case 3	:printf("Enter Element");
				scanf("%d",&heap[++n]);
				heapsort(heap,1,n,n);
				show(heap,n);
				break;
		case 4 : n=delete(heap,n);
				show(heap,n);
		case 5 : break;
	    default :	printf("Enter Valid Option\n") ;
	   }
	   }
}
