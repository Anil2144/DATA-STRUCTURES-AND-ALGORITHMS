#include<stdio.h>
#include<stdlib.h>
void add(int a[20][20],int b[20][20],int c[20][20],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}

	}
}
void matrixmul(int a[20][20],int b[20][20],int c[20][20],int n)
{
     int i,j;
	if(n==1)
	{
		c[0][0]=a[0][0]*b[0][0];
	}
	else if(n==2)
	{
		c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
		c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
		c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
		c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	}
	else
	{
		int t1[20][20],t2[20][20];
		int a11[20][20],a12[20][20],a21[20][20],a22[20][20];
		int b11[20][20],b12[20][20],b21[20][20],b22[20][20];
		int c11[20][20],c12[20][20],c21[20][20],c22[20][20];
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
		matrixmul(a11,b11,t1,n/2);
		matrixmul(a12,b21,t2,n/2);
		add(t1,t2,c11,n/2);
		matrixmul(a11,b12,t1,n/2);
		matrixmul(a12,b22,t2,n/2);
		add(t1,t2,c12,n/2);
		matrixmul(a21,b11,t1,n/2);
		matrixmul(a22,b21,t2,n/2);
		add(t1,t2,c21,n/2);
		matrixmul(a21,b12,t1,n/2);
		matrixmul(a22,b22,t2,n/2);
		add(t1,t2,c22,n/2);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			   	if(i<n/2 && j<n/2)
				{
				 c[i][j]=c11[i][j];
			    }
			  else if(i<n/2 && j>=n/2)
			   {
			   	c[i][j]=c12[i][j%(n/2)];
			   	
			   }
			   else if(i>=n/2 && j<n/2)
			   {
			  	c[i][j]=c21[i%(n/2)][j];
			   }
			   else
			   {
			  	c[i][j]=c22[i%(n/2)][j%(n/2)];
			   }
			}
		}

	}
}

void main()
{
	int a[20][20],b[20][20],i,j,n,c[20][20];
	printf("Enter order of square matrix:");
	scanf("%d",&n);
	printf("Enter matrix 1:");
	for(i=0;i<n;i++)		
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	}
	printf("Enter matrix 2:");
	for(i=0;i<n;i++)		
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
		
	}
	matrixmul(a,b,c,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");

	}
	

}
