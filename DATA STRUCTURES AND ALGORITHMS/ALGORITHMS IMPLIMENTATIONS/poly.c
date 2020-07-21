#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node *next;
};
struct node* insert(struct node *head,int ele)
{
	struct node *temp=head,*new;
	new=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		new->e=ele;
		new->next=NULL;
		head=new;
		return head;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
		new->e=ele;
		new->next=NULL;
		return head;
	}
}
void main()
{
	struct node *head=NULL,*head1=NULL,*head2=NULL;
	int i,j,n1,n2,ele,n3,n4;
	printf("enter degree of polynomial 1: ");
	scanf("%d",&n1);
	for(i=n1;i>=0;i--)
	{
		printf("Enter coefficient of x^%d:",i);
		scanf("%d",&ele);
		head=insert(head,ele);
	}
	printf("enter degree of polynomial 2:");
	scanf("%d",&n2);
	n3=n1;
	n4=n2;
	for(i=n2;i>=0;i--)
	{
		printf("Enter coefficient of x^%d:",i);
		scanf("%d",&ele);
		head1=insert(head1,ele);
	}
	struct node *temp1=head;
	struct node *temp2=head1;
	if(n1==n2)
	{
		while(temp1!=NULL && temp2!=NULL)
		{
			ele=(temp1->e)+(temp2->e);
			head2=insert(head2,ele);
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	else if(n1>n2)
	{
		while(n1!=n2)
		{
			ele=temp1->e;
			head2=insert(head2,ele);
			temp1=temp1->next;
			n1--;
		}
		while(temp1!=NULL && temp2!=NULL)
		{
			ele=(temp1->e)+(temp2->e);
			head2=insert(head2,ele);
			temp1=temp1->next;
			temp2=temp2->next;
		}

	}
	else if(n1<n2)
	{
		while(n2!=n1)
		{
			ele=temp2->e;
			head2=insert(head2,ele);
			temp2=temp2->next;
			n2--;
		}
		while(temp1!=NULL && temp2!=NULL)
		{
			ele=(temp1->e)+(temp2->e);
			head2=insert(head2,ele);
			temp1=temp1->next;
			temp2=temp2->next;
		}

	}
	struct node *temp3=head2;
	printf("Result is:\n");
	if(n3==n4)
	{
		for(i=n3;i>=0;i--)
		{
			printf("Degree of x^%d is %d\n",i,temp3->e);
			temp3=temp3->next;
		}
	}
	else if(n3>n4)
	{
		for(i=n3;i>=0;i--)
		{
			printf("Degree of x^%d is %d\n",i,temp3->e);
			temp3=temp3->next;
		}
	}
	else if(n3<n4)
	{
		for(i=n4;i>=0;i--)
		{
			printf("Degree of x^%d is %d\n",i,temp3->e);
			temp3=temp3->next;
		}

	}



}