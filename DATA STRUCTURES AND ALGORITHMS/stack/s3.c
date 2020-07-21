#include<stdio.h>
struct stack 
{
	int a[100];
	int top;
	int el;
	int n;
}s;
void main()
{
 int op;
 s.top=-1;
 printf("enter the no of elememts.\n");
 scanf("%d",&s.n);
 do
 {
 	printf("1:push.\n2:pop.\n:3:exit.\n");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:if(s.top==s.n)
 			printf("stack is full.\n");
 				 else
 				 {
 				 	printf("enter the element\n");
 				 	scanf("%d",&s.el);
 				 	s.top++;
 				 	s.a[s.top]=s.el;
 				 }break;
 		case 2:if(s.top==-1)
 						printf("stack is empty.\n");
 				 else
 				 {
 				  		s.top--;
 				  		printf("deleted element = %d\n",s.a[s.top+1]);
 				 }break;
 		case 3:break;
 		default :printf("invalid option.\n");
 	}
 }while(op!=3);
}



 			
