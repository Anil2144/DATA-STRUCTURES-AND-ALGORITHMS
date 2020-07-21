#include<stdio.h>
int main()
{
  int n,i,a[20];
    printf("enter the size");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergesort(a,0,n-1);
     for(i=0;i<n;i++)
    printf("%d",a[i]);
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
  int    mid=(l+(r-1))/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);
    }
}
void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int l1[n1],l2[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
    {
        l1[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        l2[j]=a[m+1+j];
    }
    i=0,j=0,k=1;
    while(i<n1 && j<n2)
    {
        if(l1[i]<=l2[j])
        {
            a[k]=l1[i];
            i++;
        }
        else
        {
            a[k]=l2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=l1[i];
        i++;
        k++;
    }
     while(j<n2)
    {
        a[k]=l2[j];
        j++;
        k++;
    }
}
