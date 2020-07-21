#include<stdio.h>
struct queue
{
	int r;
	int f;
	int a[100];
	int n;
}s;
void main()
{
 int op,el;
 s.r=0;s.f=0;
 printf("enter the limit.\n");
 scanf("%d",&s.n);
 do
 {
 	printf("1:enqueue 2:dequeue 3:exit \n");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:if(s.r==(s.n-1))
 					printf("queue is full.\n");
 				 else
 				 {
 				 	printf("enter the element \n");
 				 	scanf("%d",&el);
 				   s.r++;
 				 	s.a[s.r]=el;
 				 }break;
 		case 2:if(s.f==s.r)
 					printf("queue is empty \n");
 				 else
 				 {
 				 	s.f++;
 				 	printf("deleted element = %d\n",s.a[s.f]);
 				 }break;
 		case 3:break;
 		default:printf("invalid option \n");
 	}
 }while(op!=3);
}
 				 
