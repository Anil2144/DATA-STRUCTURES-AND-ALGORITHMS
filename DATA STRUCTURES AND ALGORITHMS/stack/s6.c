#include<stdio.h>
#include<stdlib.h>
struct stack 
{
	int n;
	int top;
	int a[100];
}*s;
void main()
{
	int op,el;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	printf("enter the no.of elements.\n");
	scanf("%d",&s->n);
	do
	{
	 printf("1:push 2:pop 3:exit.\n");
	 scanf("%d",&op);
	 switch(op)
	 {
	 	case 1:if(s->top==s->n)
	 				printf("stack is full.\n");
	 			else 
	 			{
	 				printf("enter the element.\n");
	 				scanf("%d",&el);
	 				s->top++;
	 				s->a[s->top]=el;
	 			}break;
	 	case 2:if(s->top==-1)
	 				printf("stack is empty.\n");
	 			else
	 			{
	 				s->top--;
	 				printf("deleted no = %d\n",s->a[s->top+1]);
	 			}break;
	 	case 3:break;
	 	default:printf("invalid option.\n");
	 }
	}while(op!=3);
}
