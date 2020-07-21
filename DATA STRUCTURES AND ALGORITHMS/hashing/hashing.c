#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
	int data;
	struct node*next;
};
void insert(struct node ** head)
{
	int k;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter element\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	k=temp->data%10;
	if(head[k]==NULL)
	head[k]=temp;
	else
	{
		struct node *temp1=(struct node*)malloc(sizeof(struct node));
		temp1=head[k];
		while(temp1->next!=NULL)
		temp1=temp1->next;
		temp1->next=temp;
	}
}
void display(struct node **head)
{
	struct node *temp;
	int i;
	for(i=0;i<10;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp=head[i];
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}
struct node* search(struct node **head,int key)
{
	int rem;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	rem=key%10;
	temp=head[rem];
	while(temp!=NULL)
	{
		if(temp->data==key)
		break;
		temp=temp->next;
	}
	return temp;
}
void delete(struct node **head)
{
	int key,f=0,rem;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*temp1=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to delete\t");
	scanf("%d",&key);
	rem=key%10;
	temp1=temp=head[rem];
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			f=1;
			printf("%d is deleted successfully\n",key);
			break;
		}
		temp1=temp;
		temp=temp->next;
	}
	if(f==1)
	{
		if(temp==head[rem])
		head[rem]=head[rem]->next;
		else
		temp1->next=temp->next;
	}
	else
	printf("%d is not found to delete\n",key);
}
void count(struct node **head)
{
	int i=0,c=0;
	struct node *temp;
	for(i=0;i<10;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp=head[i];
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;
		}
	}
	printf("Total Count=%d\n",c);
}		
void main()
{
	struct node **head,*temp;
	int i,n,k,t,op=1,key;
	head=(struct node**)malloc(10*sizeof(struct node));
	temp=(struct node *)malloc(sizeof(struct node));
	for(i=0;i<10;i++)
	head[i]=NULL;
	while(op!=6)
	{
		printf("Enter option\n1.Insert\t2.Display\t3.Search\t4.Delete\t5.Count\t6.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : insert(head);
					break;
			case 2 : display(head);
					break;
			case 3 : printf("Enter key to Search\t");
					scanf("%d",&key);
					temp=search(head,key);
					if(temp)
					printf("%d is found\n",key);
					else
					printf("%d is not found\n",key);
					break;
			case 4 :delete(head);
			case 5 : count(head);
			case 6 : break;
		}
	}
}
