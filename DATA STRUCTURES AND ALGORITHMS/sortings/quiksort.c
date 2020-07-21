#include<stdio.h>
#include<time.h>
int main()
{
    int n,i,a[10000];
    printf("enter the size");
    scanf("%d",&n);
   // printf("enter the elements");
    for(i=0;i<n;i++)
     a[i]=rand();
    clock_t t1=clock();
    quicksort(a,0,n-1);
    clock_t t2=clock();
    double time=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%f\n",time);
    // for(i=0;i<n;i++)
    //printf("\n%d",a[i]);
}
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return(i+1);
}
void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
