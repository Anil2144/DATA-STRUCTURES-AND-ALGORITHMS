#include<stdio.h>
void main()
{
 int r=-1,f=-1,el,op,n,a[100];
 printf("enter the no. of elements.\n");
 scanf("%d",&n);
 do
 {
  printf("1:enqueue 2:dequeue 3:exit.\n");
  scanf("%d",&op);
  switch(op)
  {
  	case 1: if(r==n)
  					printf("queue is full.\n");
  			 else
  			 {
  			 	printf("enter the element .\n");
  			 	scanf("%d",&el);
  			 	r++;
  			 	a[r]=el;
  			 }break;
  	case 2:if(r==f)
  				printf("queue is empty.\n");
  			 else
  			 {
  			 	f++;
  			 	printf("deleted element = %d\n",a[f]);
  			 }break;
  	case 3:break;
  	default:printf("invalid option.\n");
  }
 }while(op!=3);
}
