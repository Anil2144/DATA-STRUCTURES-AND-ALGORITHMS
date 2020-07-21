#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct student
{
	int id;
	char name[10];
}s[10];
struct queue
{
	int array[10];
	int top,rear;
};
void enqueue(struct queue *q,int p)
{
	q->top++;
	q->array[q->top]=p;
}
int IsEmpty(struct queue *q)
{
	if(q->rear==q->top)
	return 1;
	return 0;
}
int dequeue(struct queue *q)
{
	q->rear++;
	return q->array[q->rear];
}
void push(struct queue *q,int k)
{
	q->top++;
	q->array[q->top]=k;	
}
void BFS( int n,int a[10][10],int start,bool visit[10])
{
	int k,i,j,t;
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	q->top=-1;
	q->rear=-1;
	enqueue(q,start);
	while(!IsEmpty(q))
	{
		k=dequeue(q);
		if(visit[k]==0)
			{
				printf("Vertex ----%d\t",k);
				visit[k]=1;
				for(i=0;i<n;i++)
				{
					if(a[k][i]!=0 && visit[i]==0)
					enqueue(q,i);	
				}
			}
	}
				for(i=0;i<n;i++)
				{
					if(visit[i]==0)
					BFS(n,a,i,visit);
				}
				
}
void DFS(int n ,int a[10][10],int start,bool visit[10])
{	
	int k,i,flag=1,t,j;
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));	
	q->top=-1;
	push(q,start);
	while(q->top!=-1)
	{
		flag=0;
		k=q->array[q->top];
		if(visit[k]!=1)
		{
			visit[k]=1;
			printf("Vertex----->%d\t",k);
		}
		for(i=0;i<n;i++)
		{
			if(a[k][i]==1 && visit[i]!=1)
			{
				flag=1;
				push(q,i);
				break;
			}
		}	
			if(flag==0)
			q->top--;
	}
		for(i=0;i<n;i++)
		{
			if(visit[i]!=1)
			DFS(n,a,i,visit);
		}
}
void main()
{
	int op,i,j,n,t,start;
	int a[10][10];
	bool visit[10];
	printf("Enter the no.of elements in the graph\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	visit[i]=0;
	printf("Enter Matrix\n");
	for(i=0;i<n;i++)
	{ 
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("1.DFS\n2.BFS\n");
	scanf("%d",&op);
	printf("Enter starting Vertex present in the graph\n");
	scanf("%d",&start);
	switch(op)
	{
			 case 1 : DFS(n,a,start,visit);
			 		break;
			case 2 : BFS(n,a,start,visit);
					break;
			default : printf("Enter Valid OPtion\n");
	}
}
