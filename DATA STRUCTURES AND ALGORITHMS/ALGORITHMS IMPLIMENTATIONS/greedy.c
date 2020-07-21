#include<stdio.h>
#include<stdlib.h>
int visit(int s[],int n,int v)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i]==v)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
void dijkstras(int n,int d[],int p[],int st,int a[n][n])
{
	int s[n],q[n],i;
	for(i=0;i<n;i++)
	{
		s[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		q[i]=i;
	}
	int u,v,k,w;
	int j=0;
	while(j<n)
	{
		u=q[j];
		s[j]=u;
		for(v=0;v<n;v++)
		{
			if(a[u][v]>0&&visit(s,n,v)==0)
			{
				w=a[u][v];
				if(d[v]>d[u]+w)
				{
					d[v]=d[u]+w;
					p[v]=u;
				}
			}
		}
		j++;
	}
	
}
void main()
 {
	int n,i,j,start=0;
	printf("enter no.of vertices");
	scanf("%d",&n);
	int a[n][n];
	printf("enter matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int d[n],p[n];
	p[0]=NULL;
	d[0]=0;
	for(i=1;i<n;i++)
	{
		d[i]=1000;
	}
	dijkstras(n,d,p,start,a);
	printf("shortest path is\n");
	printf("vertex distance parent\n");
	for(i=0;i<n;i++)
	{
		printf("%d       %d       %d",i,d[i],p[i]);
		printf("\n");
	}
}
