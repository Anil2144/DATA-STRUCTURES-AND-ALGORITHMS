#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble(int *a,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
   }
	//	for(i=0;i<n;i++)
	//	printf("%d ",a[i]);

	
}

void main()
{
	int i,j;
	int *a;
	srand(time(0));
	a=(int *)malloc(1000*sizeof(int));
	for(i=0;i<=1000;i++)
	{
	   a[i]=rand();
	}
	clock_t t1=clock();
	bubble(a,1000);
	clock_t t2=clock();
	double time=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\n%f ",time);

}
