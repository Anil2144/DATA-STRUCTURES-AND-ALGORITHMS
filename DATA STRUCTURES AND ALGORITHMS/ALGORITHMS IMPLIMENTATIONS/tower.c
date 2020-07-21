#include<stdio.h>
void tower(int,char,char,char);
  void main()
  {
       int n;
       char a='A',b='B',c='C';
       printf("Enter how many disks:");
       scanf("%d",&n);
       tower(n,a,b,c);
  }
  void tower(int n,char a,char b,char c)      
  {
           if(n==1)
           {
              printf("Move from %c to %c\n",a,c);
              return;
           }
           tower(n-1,a,c,b),tower(1,a,b,c),tower(n-1,b,a,c);
 }            
