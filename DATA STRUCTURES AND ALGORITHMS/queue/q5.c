#include<stdio.h>
struct queue
{
	int r;
	int a[100];
	int f;
	int n;
}s;
void enqueue(struct queue *);
void dequeue(struct queue *);
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
			case 1:enqueue(&s);
						break;
			case 2:dequeue(&s);
						break;
			case 3:break;
			default:printf("invalid option\n");
		}
	}while(op!=3);
}
					void enqueue(struct queue *s)
					{
						if(s->r==s->n)
							printf("queue is full\n");
						else
						{
							int el;
							printf("enter the element.\n ");
							scanf("%d",&el);
							s->r++;
							s->a[s->r]=el;
						}
					}
					void dequeue(struct queue *s)
					{
						if(s->f==s->r)
							printf("queue is empty.\n");
						else
						{
							s->f++;
							printf("deleted element = %d\n",s->a[s->f]);
						}
					}
