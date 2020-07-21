#include<stdio.h>
#include<time.h>
int main()
{
int temp,n,a[10000],i,j;
printf("enter the number of elements:");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<n;i++)
{
a[i]=rand();
}
clock_t t1=clock();
for(i=0;i<n;i++)
{
 for(j=0;j<n-1-i;j++)
 {
  if(a[j]>a[j+1])
  {
   int temp;
   temp=a[j];
   a[j]=a[j+1];
   a[j+1]=temp;
  }
 }
}
clock_t t2=clock();
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
double time=(double)(t2-t1)/CLOCKS_PER_SEC;
printf("%f",time);
}
