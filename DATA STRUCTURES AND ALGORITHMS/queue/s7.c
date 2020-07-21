#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int n;
	int f;
	int r;
	int a[100];
}(*s);
void enqueue(struct queue *);
void dequeue(struct queue *);
void main()
{
	s=(struct queue *)malloc(sizeof(struct queue));
	int op,n;
	s->r=0;
	s->f=0;
	printf("enter the limit \n");
	scanf("%d",&s->n);
	do
	{
		printf("1:enqueue 2:dequeue 3:exit");
		scanf("%d",&op);
		switch(op)
		{
			case 1:enqueue(s);
						break;
			case 2:dequeue(s);
						break;
			case 3:break;
			default:printf("invalid option\n");
		}
	}while(op!=3);
}
	void enqueue(struct queue *s)
	{
			int el;
				if((s->r)==(s->n))
 					printf("queue is full.\n");
 					
 				else
 				{
 					printf("enter the element\n");
 					scanf("%d",&el);
 					s->a[s->r]=el;
 					(s->r)++;
 				}
 	}
 		void dequeue(struct queue *s)
 		{
 				if((s->r)==(s->f))
 					printf("queue is empty\n");
 				else
 				{
 					printf("deleted element=%d\n",s->a[s->f]);
 					(s->f)++;
 				}
 		}
 					
