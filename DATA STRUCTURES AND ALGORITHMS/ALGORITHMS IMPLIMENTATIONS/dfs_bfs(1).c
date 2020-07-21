#include<stdio.h>
#include<stdlib.h>
struct queue
{
			int a[100];
			int r,f,n;
};
void enque(struct queue *q,int ele)
{
			q->r+=1;
			q->a[q->r]=ele;
}
int deque(struct queue *q)
{
			q->f+=1;
			int k=q->a[q->f];
			return k;
}
int isempty(struct queue *q)
{
			if(q->r==q->f)
					return 1;
			else
					return 0;
}		
void bfs(int a[50][50]	,int visit[50],int n,int st)
{
			struct queue *q;
			q=(struct queue *)malloc(sizeof(struct queue));
			q->r=q->f=-1;
			q->n=100;
			int i,j,f=0;
			enque(q,st);
			while(!isempty(q))
			{
					i=deque(q);
					if(visit[i]!=1)
					{
								visit[i]=1;
								printf("%d  ",i);
								for(j=0;j<n;j++)
								{			
											if(a[i][j]==1 && visit[j]==0)
											{
														enque(q,j);
											}
								}
				}
			}		
				for(i=0;i<n;i++)
				{
							if(visit[i]!=1)
							{
									f=1;
									break;
							}
				}
				if(f==0)
					printf("Graph is connected\n"	);
				else
					printf("Graph is disconnected\n"	);
												
				
		
}	
void dfs(int a[50][50],int visit[50],int n,int i)
{
					if(visit[i]==0)
					{
						visit[i]=1;
						int j;
						printf("%d  ",i); 
						for(j=0;j<n;j++)
						{
								if(a[i][j]==1 && visit[j]==0)
								{
											dfs(a,visit,n,j);
								}
						}	
					}			
}																			
 void main()
 {
 				int i,j,n,visit[50]={0},st,a[50][50];
 				printf("Enter the no.of nodes:");
 				scanf("%d",&n);
				printf("Enter the graph in matrix form:");
				for(i=0;i<n;i++)
				{
						for(j=0;j<n;j++)
						{
									scanf("%d",&a[i][j]);
						}
			}
			for(i=0;i<n;i++)
					visit[i]=0;
					
			printf("Enter starting node:");
			scanf("%d",&st);
			bfs(a,visit,n,st);
			printf("\n");
			int visit1[30]={0};
			dfs(a,visit1,n,0);
			printf("\n");
			
}
															
			
									 				
