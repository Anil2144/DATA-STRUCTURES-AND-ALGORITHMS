#include<stdio.h>
#include<stdlib.h>
struct stack 
{
	int a[100];
	int n;
	int top;
}(*s);
void push(struct stack *);
void pop(struct stack *);
void main()
{
	s=(struct stack *)malloc(sizeof(struct stack));
	int op;
	s->top=-1;
	printf("enter the limit.\n");
	scanf("%d",&s->n);
	do
	{
		printf("1:push 2:pop 3:exit.\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:push(s);
						break;
			case 2:pop(s);
						break;
			case 3:break;
			default:printf("invalid option.\n");
		}
	}while(op!=3);
}
		void push(struct stack *s)
		{
			int el;
			if(s->top==s->n)
				printf("stack is full.\n");
			else
			{
				printf("enter the element.\n");
				scanf("%d",&el);
				s->top++;
				s->a[s->top]=el;
			}
		}
		void pop(struct stack *s)
		{
			if(s->top==-1)
				printf("stack is empty.\n");
			else
			{
				s->top--;
				printf("deleted element = %d",s->a[s->top+1]);
			}
		}
