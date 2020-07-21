#include<stdio.h>
int enqueue(int,int,int[]);
int dequeue(int,int,int[]);
void main()
{
 int op,n,r=0,f=0,a[100];
 printf("enter the limit.\n");
 scanf("%d",&n);
 do
 {
 	printf("1:enqueue 2:dequeue 3:exit \n");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:r=enqueue(r,n,a);
 					break;
 		case 2:f=dequeue(r,f,a);
 					break;
 		case 3:break;
 		default:printf("invalid option,\n");
 	}
 }while(op!=3);
}
		int enqueue(int r,int n,int a[])
		{
			int el;
			if(r==(n-1))
					printf("queue is full.\n");
			else
			{
				printf("enter the element.\n");
				scanf("%d",&el);
				r++;
				a[r]=el;
			}
			return(r);
		}
		int dequeue(int r,int f,int a[])
		{
			if(f==r)
				printf("queue is empty.\n");
			else
			{
			 f++;
			 printf("deleted element = %d\n",a[f]);
			}
			return(f);
		}



		
