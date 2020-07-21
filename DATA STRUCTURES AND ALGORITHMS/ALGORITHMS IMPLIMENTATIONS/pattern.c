#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,n=10;
    for(i=1;i<n;i=i+2)
    {
        for(j=((n/2)-i);j>0;j--)
        {
            printf("\t");
        }
        for(k=1;k<=i;k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
