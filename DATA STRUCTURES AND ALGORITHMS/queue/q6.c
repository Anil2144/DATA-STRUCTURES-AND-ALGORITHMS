#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int r;
	int f;
	int a[100];
	int n;
}*s;
void main()
{
 int el,op;
 s=(struct queue *)malloc(sizeof(struct queue));
 s->r=0;
 s->f=0;
 printf("enter the limit.\n");
 scanf("%d",&(s->n));
 do
 {
 	printf("1:enqueue 2:dequeue 3:exit \n");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:if((s->r)==(s->n))
 					printf("queue is full.\n");
 					
 				else
 				{
 					printf("enter the element\n");
 					scanf("%d",&el);
 					s->a[s->r]=el;
 					(s->r)++;
 				}break;
 		case 2:if((s->r)==(s->f))
 					printf("queue is empty\n");
 				else
 				{
 					printf("deleted element=%d\n",s->a[s->f]);
 					(s->f)++;
 					
 				}break;
 		case 3:break;
 		default:printf("invalid input \n");
 	}
 }while(op!=3);
}
 

