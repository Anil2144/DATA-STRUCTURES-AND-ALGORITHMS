#include<stdio.h>
int swap(int*,int*);
int main()
{
    int n,i,a[10],j;
    printf("enter the size of an arrey:");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n;j++)
    {
    for(i=j+1;i<n;i++)
    {
     if(a[i]<a[j])
     {
         swap(&a[j],&a[i]);
     }
    }
    }
     for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
int swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
