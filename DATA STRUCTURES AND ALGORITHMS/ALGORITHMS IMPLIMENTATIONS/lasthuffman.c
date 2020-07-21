#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct code
{
	char c;
	int f;
	struct code *left,*right;
};
struct node
{
	struct code *arr[100];
};

void heapify(struct node *map,int k,int i)
{
	int max=i,left,right;
	struct code *temp;
	left=2*i,right=2*i+1;
	if(left>=k)
		left=-1;
	if(right>=k)
		right=-1;
	if(left!=-1 && map->arr[max]->f>map->arr[left]->f)
	{
		max=left;
	}
	if(right!=-1 && map->arr[max]->f>map->arr[right]->f)
	{
		max=right;
	}
	if(max!=i)
	{
		temp=map->arr[max];
		map->arr[max]=map->arr[i];
		map->arr[i]=temp;
		heapify(map,k,max);
	}
}

void minheapify(struct node *map,int k)
{
	int i;
	for(i=k/2;i>=0;i--)
	{
		heapify(map,k,i);
	}
}
void display(struct code *final,int i,char co[])
{
	int j;
	if(final->left==NULL && final->right==NULL)
	{
		printf("\n%c--%d---",final->c,final->f);
		for(j=0;j<i;j++)
		{
			printf("%c",co[j]);
		}
	}
	else
	{
		display(final->left,i+1,co);
		co[i]='1';
		display(final->right,i+1,co);
		co[i]='0';
	}
}
void unique(char a[],int n,char u[],int *k)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]==a[i])
			{
				break;
			}
		}
		if(j==-1)
			u[(*k)++]=a[i];
	}
}
void frequency(char a[],char u[],int n,int k,int freq[])
{
	int i,j;
	for(i=0;i<k;i++)
	{
		int cnt=0;
		for(j=0;j<n;j++)
		{
			if(a[j]==u[i])
				cnt+=1;
		}
		freq[i]=cnt;
	}

}
void main()
{
	char a[60],u[30];
	int freq[30];
	int i,j,n,k=0;
	printf("Enter string:");
	gets(a);
	n=strlen(a);
	unique(a,n,u,&k);
	frequency(a,u,n,k,freq);
	struct node *map=(struct node *)malloc(sizeof(struct node));
	for(i=0;i<k;i++)
	{
		map->arr[i]=(struct code*)malloc(sizeof(struct code));
		map->arr[i]->c=u[i];
		map->arr[i]->f=freq[i];
		map->arr[i]->left=map->arr[i]->right=NULL;
	}
	minheapify(map,k);
	struct code *t,*p,*final;
	while(k>0)
	{
		t=map->arr[0];
		map->arr[0]=map->arr[k-1];
		k--;
		if(k!=0)
		{
			heapify(map,k,0);
			p=map->arr[0];
			struct code *n=(struct code *)malloc(sizeof(struct code*));
			n->c='I';
			n->f=t->f+p->f;
			n->left=t;
			n->right=p;//tree buliding
			map->arr[0]=n;
			heapify(map,k,0);
		}
		else
		{
			final=t;
			break;
		}
	}
	char co[]="000000000000000";
	display(final,0,co);
}
