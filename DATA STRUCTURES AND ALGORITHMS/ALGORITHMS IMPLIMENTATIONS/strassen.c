#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int a[10][10],int b[10][10],int c[10][10],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=b[i][j]+a[i][j];
		}
	}
}

void sub(int a[10][10],int b[10][10],int c[10][10],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
}

void mul(int a[10][10],int b[10][10],int c[10][10],int n)
{
	if(n==1)
	{
		c[0][0]=a[0][0]*b[0][0];
	}
/*	else if(n==2)
	{
		int i,j;
		c[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0]);
		c[0][1]=(a[0][0]*b[0][1])+(a[0][1]*b[1][1]);
		c[1][0]=(a[1][0]*b[0][0])+(a[1][1]*b[1][0]);
		c[1][1]=(a[1][0]*b[0][1])+(a[1][1]*b[1][1]);
	} */
	else
	{
		int i,j,k,l,m;
		int a11[10][10],a12[10][10],a21[10][10],a22[10][10],b11[10][10],b12[10][10],b21[10][10],b22[10][10];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i<n/2 && j<n/2)
				{
					a11[i][j]=a[i][j];
					b11[i][j]=b[i][j];	
				}
				else if(i<n/2 && j>=n/2)
				{
					a12[i][j%(n/2)]=a[i][j];
					b12[i][j%(n/2)]=b[i][j];
				}
				else if(i>=n/2 && j<n/2)
				{
					a21[i%(n/2)][j]=a[i][j];
					b21[i%(n/2)][j]=b[i][j];	
				}
				else
				{
					a22[i%(n/2)][j%(n/2)]=a[i][j];
					b22[i%(n/2)][j%(n/2)]=b[i][j];	
				}
			}
		}
		
		int p1[10][10],p2[10][10],p3[10][10],p4[10][10],p5[10][10],p6[10][10],p7[10][10];
		int t1[10][10],t2[10][10],t3[10][10],t4[10][10];

		sub(b12,b22,t1,n/2);
		mul(a11,t1,p1,n/2);
		add(a11,a12,t1,n/2);
		mul(t1,b22,p2,n/2);
		add(a22,a21,t1,n/2);
		mul(t1,b11,p3,n/2);
		sub(b21,b11,t1,n/2);
		mul(a22,t1,p4,n/2);
		add(a11,a22,t1,n/2);
		add(b11,b22,t2,n/2);
		mul(t1,t2,p5,n/2);
		sub(a12,a22,t1,n/2);
		add(b21,b22,t2,n/2);
		mul(t1,t2,p6,n/2);
		sub(a11,a21,t1,n/2);
		add(b11,b12,t2,n/2);
		mul(t1,t2,p7,n/2);

		int c11[10][10],c12[10][10],c21[10][10],c22[10][10];
		add(p5,p4,t1,n/2);
		sub(t1,p2,t2,n/2);
		add(t2,p6,c11,n/2);
		add(p1,p2,c12,n/2);
		add(p3,p4,c21,n/2);
		add(p5,p1,t1,n/2);
		sub(t1,p3,t2,n/2);
		sub(t2,p7,c22,n/2);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i<n/2 && j<n/2)
					c[i][j]=c11[i][j];
				else if(i<n/2 && j>=n/2)
					c[i][j]=c12[i][j%(n/2)];
				else if(i>=n/2 && j<n/2)
					c[i][j]=c21[i%(n/2)][j];
				else if(i>=n/2 && j>=n/2)
					c[i][j]=c22[i%(n/2)][j%(n/2)];
			}
		}
	}

}

void main()
{
	int i,j,k,l,m,n;
	int a[10][10],c[10][10],b[10][10];
	printf("enter value of n : ");
	scanf("%d",&n);
	printf("enter %d elements of matrix 1 : \n",n*n);
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[j][i]);
		}
	}

	printf("enter %d elements of matrix 2 : \n",n*n);
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[j][i]);
		}
	}
	mul(a,b,c,n);
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",c[j][i]);
		}
		printf("\n");
	}
}
