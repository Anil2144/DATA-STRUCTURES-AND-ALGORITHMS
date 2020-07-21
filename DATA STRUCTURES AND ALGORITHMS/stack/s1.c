#include<stdio.h>
void main()
{
 int op,n,el,top=-1,a[100];
 printf("enter the no.of elements.\n");
 scanf("%d",&n);
do
{
 printf("1:push\n2:pop\n3:exit\n");
 scanf("%d",&op);
	switch(op)
	{
		case 1:if(top==n)
					printf("stack is full.\n");
				 else
					{
						printf("enter the element.\n");
						scanf("%d",&el);
						top++;
						a[top]=el;
					}
					break;
		case 2:if(top==-1)
					printf("stack is empty.\n");
				 else
				 {
				 	top--;
				 	printf("%d\n",a[top++]);
				 }
				 break;
		case 3:break;
		default:printf("invalid option.\n");
	}
}while(op!=3);
}
