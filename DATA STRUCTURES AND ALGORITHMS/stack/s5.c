#include<stdio.h>
struct stack
{
	int a[100];
	int n;
	int el;
	int top;
}s;
void push(struct stack *);
void pop(struct stack *);
void main()
{
 int op;
 s.top=-1;
 printf("enter the no.of elements .\n");
 scanf("%d",&s.n);
 do
 {
 	printf("1:push.\n2:pop.\n3:exit.\n");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:push(&s);
 					break;
 		case 2:pop(&s);
 					break;
 		case 3:break;
 		default:printf("invalid option.\n");
 	}
 }while(op!=3);
}
 		void push(struct stack *s)
 		{
 			if(s->top==s->n)
 				printf("stac is full.\n");
 			else
 			{
 				printf("enter the element.\n");
 				scanf("%d",&s->el);
 				s->top++;
 				s->a[s->top]=s->el;
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



 				
