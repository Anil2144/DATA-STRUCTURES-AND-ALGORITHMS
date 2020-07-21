#include<stdio.h>
int swap(int*,int*);
int main()
{
    int n,i,j,a[10];
    printf("enter the arrey size:");
    scanf("%d",&n);
    printf("enter the arrey elements");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      for(j=0;j<n;j++)
      {
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
                swap(&a[i],&a[i+1]);
        }
     }
     for(i=0;i<n;i++)
          printf("%d",a[i]);
}
int swap(int *a,int *b)
{
 *a=*a+*b;
 *b=*a-*b;
 *a=*a-*b;
}
