#include<stdio.h>
int swap(int*,int*);
int main()
{
    int n,i,j,a[10];
    printf("enter the size of an arrey");
    scanf("%d",&n);
    printf("enter the arrey elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>a[j+1])
            {
              swap(&a[j],&a[j+1]);
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
