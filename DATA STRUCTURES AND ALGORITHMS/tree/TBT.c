#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tbt
{
	int ele;
	struct tbt *left;
	struct tbt *right;
	bool lthread,rthread;
};
int c=0;
struct tbt* insert(struct tbt *);
struct tbt* preorder(struct tbt *);
struct tbt* inorder(struct tbt *);
struct tbt* postorder(struct tbt *);
struct tbt* search(struct tbt *);
struct tbt* max(struct tbt *);
struct tbt* min(struct tbt *);
struct tbt* even(struct tbt *);
struct tbt* odd(struct tbt *);
struct tbt* count(struct tbt *);
struct tbt* delete(struct tbt *);
int main()
{
	struct tbt *root=NULL;
	int opt;
	do
	{
	printf("\n1.insert\n2.preorderdisplay\n3.inorder\n4.postorder\n5.search\n6.max\n7.min\n8.even\n9.odd\n10.count\n11.delete\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:root=insert(root);
				break;
			case 2:root=preorder(root);
				break;
			case 3:root=inorder(root);
				break;
			case 4:root=postorder(root);
				break;
			case 5:root=search(root);
				break;
			case 6:root=max(root);
				break;
			case 7:root=min(root);
				break;
			case 8:root=even(root);
				printf("\neven count is %d ",c);
				c=0;
				break;
			case 9:root=odd(root);
				printf("\n odd count is %d ",c);
				c=0;
				break;
			case 10:root=count(root);
				printf("\ntotal count is %d ",c);
				c=0;
				break;
			case 11:root=delete(root);
				break;
			default:printf("invalid option");
		}
	}while(opt!=11);
}
struct tbt* insert(struct tbt *root)
{
	struct tbt* temp;
	temp=(struct tbt*)malloc(sizeof(struct tbt));
	printf("Enter an element to add\n");
	scanf("%d",&(temp->ele));
	temp->lthread=temp->rthread=true;
	if(root==NULL)
	{
		root=temp;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		struct tbt *temp1;
		temp1=root;
		while(1)
		{
			if((temp1->ele)>(temp->ele))
			{
				if(temp1->lthread==false)
				{
					temp1=temp1->left;
				}
				else
				{
					temp->right=temp1;
					temp->left=temp1->left;
					temp1->left=temp;
					temp1->lthread=false;
					break;
				}
			}
			else
			{
				if(temp1->rthread==false)
				{
					temp1=temp1->right;
				}
				else
				{
					temp->left=temp1;
					temp->right=temp1->right;
					temp1->right=temp;
					temp1->rthread=false;
					break;
				}
			}
		}
	}
	return root;
}
struct tbt* preorder(struct tbt *root)
{
	if(root)
	{	
		printf("%d ",root->ele);
		if(!root->lthread)
		{
			preorder(root->left);
		}
		if(!root->rthread)
		{
			preorder(root->right);
		}
	}
	return root;
}
struct tbt* inorder(struct tbt *root)
{
	if(root)
	{
		if(!root->lthread)
		{
			preorder(root->left);
		}
		printf("%d ",root->ele);	
		if(!root->rthread)
		{
			preorder(root->right);
		}
	}
	return root; 
}
struct tbt* postorder(struct tbt *root)
{
	if(root)
	{
		if(!root->lthread)
		{
			preorder(root->left);
		}	
		if(!root->rthread)
		{
			preorder(root->right);
		}
		printf("%d ",root->ele);
	}
	return root; 
}	
struct tbt* search(struct tbt *root)
{
	int ele;
	int flag=0;
	printf("enter an element to search\n");
	scanf("%d",&ele);
	if(root==NULL)
	{
		printf("no elments to search\n");
	}
	else
	{
		struct tbt *temp1;
		temp1=root;
		while(1)
		{	
			if(ele==(temp1->ele))
			{
				flag=1;
				break;
			}
			if(ele<(temp1->ele))
			{
				if(temp1->lthread==false)
				{
					temp1=temp1->left;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(temp1->rthread==false)
				{
					temp1=temp1->right;
				}
				else
				{
					break;
				}
			}
		}
	}
	if(flag==1)
	{
		printf("element found\n");
	}
	else
	{
		printf("not found\n");
	}
	return root;
}
struct tbt* max(struct tbt *root)
{
	if(root==NULL)
	{
		printf("no elements are present\n");
	}
	else
	{	while(1)
		{
			if(root->rthread==false)
			{
				root=root->right;
			}
			else
			{
				break;
			}
		}
	}
	printf("max element is %d",root->ele);
	return root;
}
struct tbt* min(struct tbt *root)
{
	if(root==NULL)
	{
		printf("no elements are present\n");
	}
	else
	{	
		while(root->left)
		{
			root=root->left;
		}
	}
	printf("min element is %d",root->ele);
	return root;
}
struct tbt* even(struct tbt *root)
{
	if(root)
	{
		if(root->ele%2==0)
		{
			printf("%d  ",root->ele);
			c++;
		}
		if(!root->lthread)
			even(root->left);
		if(!root->rthread)
			even(root->right);
	}
	return root;
}
struct tbt* odd(struct tbt *root)
{
	if(root)
	{
		if(root->ele%2!=0)
		{
			printf("%d ",root->ele);
			c++;
		}
		if(!root->lthread)
			odd(root->left);
		if(!root->rthread)
			odd(root->right);
	}
	return root;
}
struct tbt* count(struct tbt *root)
{
	if(root)
	{
		c++;
		if(!root->lthread)
			count(root->left);
		if(!root->rthread)
			count(root->right);
	}
	return root;
}
struct tbt* delete(struct tbt *root)
{
	
