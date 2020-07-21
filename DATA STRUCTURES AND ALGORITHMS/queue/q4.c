#include<stdio.h>
struct queue enqueue(struct queue);
struct queue dequeue(struct queue);
struct queue
{
	int r;
	int f;
	int n;
	int a[100];
}s;
void main()
{
 int op;
 s.r=0;
 s.f=0;
 printf("enter the limit.\n");
 scanf("%d",&s.n);
 do
 {
 printf("1:enqueue 2:dequeue 3:exit \n");
 scanf("%d",&op);
 switch(op)
 {
 	case 1:s=enqueue(s);
 				break;
 	case 2:s=dequeue(s);
 				break;
 	case 3:break;
 	default:printf("invalid option.\n");
 }
 }while(op!=3);
}
 	struct queue enqueue(struct queue s)
 	{
 		int el;
 		if(s.r==(s.n-1))
 			printf("stack is full.\n");
 		else
 		{
 			printf("enter the element.\n");
 			scanf("%d",&el);
 			s.r++;
 			s.a[s.r]=el;
 		}
 		return(s);
 	}
 	struct queue dequeue(struct queue s)
 	{
 		if(s.f==s.r)
 			printf("stack is empty.\n");
 		else
 		{
 			s.f++;
 			printf("deleted = %d\n",s.a[s.f]);
 		}
 		return(s);
 	}

 	
