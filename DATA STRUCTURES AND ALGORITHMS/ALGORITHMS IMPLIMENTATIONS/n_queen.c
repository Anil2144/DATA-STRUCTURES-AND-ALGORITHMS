  #include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	int i,j,n,a[10][10];
	printf("enter no of queens :\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]= 0;	
		}
	}
	if(queen(a,0,n)==0)
		printf("no solution");
 else
   {
   	queen(a,0,n);
   	printf("\nthe solution is\n");
   	printing(a,n);
	}	
}
int queen(int a[10][10],int row,int n)
{
	int j,i;
	if(row>=n)
		return 1;
	for(j=0;j<n;j++)
	{
		if(check(j,row,n,a)==1)
		{
			a[j][row]=1;
			if(queen(a,row+1,n)==1)
			return 1;
			a[j][row]=0;
	}
	}
	return 0;
}
int check(int row,int col,int n,int a[10][10]) 
{
   int i,j;
  for(i=0;i<col;i++)
   if(a[row][i]==1)
    return 0;
 	for(i=row,j=col;i>=0&&j>=0&&i<n;i--,j--)
 	if(a[i][j]==1)
 	return 0;
 	for(i=row,j=col;j>=0&&i<n;i++,j--)
 	if(a[i][j]==1)
   return 0;
   return 1;
}
int printing(int a[10][10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
   	{
   		for(j=0;j<n;j++)
   		{
   			printf("%d\t",a[i][j]);
		   }printf("\n");
	   }
   }
