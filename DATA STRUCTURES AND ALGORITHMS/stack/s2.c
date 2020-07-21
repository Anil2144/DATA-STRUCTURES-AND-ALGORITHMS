#include<stdio.h>
int push(int,int,int[]);
int pop(int,int[]);
void main()
{
 int n,top=-1,op,a[100];
 printf("enter the limit.\n");
 scanf("%d",&n);
 do
 {
 	printf("1:push\n2:pop\n3:exit\n");
 	scanf("%d",&op);
 		switch(op)
 		{
 			case 1:top=push(top,n,a);
 						break;
 			case 2:top=pop(top,a);
 						break;
 			case 3:break;
 			default:printf("option invalid.\n");
 		}
 }while(op!=3);
 }
 						int push(int top,int n,int a[])
 						{
 							int el;
 							if(top==(n-1))
 								printf("stack is full.\n");
 							else
 							{
 								printf("enter the element.\n");
 								scanf("%d",&el);
 								top++;
 								a[top]=el;
 							}
 						 return top;
 						}
 								int pop(int top,int a[])
 								{
 									if(top==-1)
 										printf("stack is empty.\n");
 									else
 									{
 										top--;
 										printf("deleted element = %d\n",a[top+1]);
 									}
 									return top;
 								}





 						
