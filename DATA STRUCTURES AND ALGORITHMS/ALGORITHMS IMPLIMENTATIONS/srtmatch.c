#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char m[100],s[100];
    int k;
    printf("enter the main string");
    gets(m);
    printf("enter the pattern");
    gets(s);
    k=string_match(m,s);
    if(k!=-1)
         printf("the substring is present %d",k+1);
     else
       printf("pattern is not there");
 }
 int string_match(char m[100],char s[100])
 {
    int i,l1,l2,j;
    l1=strlen(m);
    l2=strlen(s);
    for(i=0;i<=l1-l2;i++)
    {
      j=0;
      while(j<l2 && s[j]==m[i+j])
      {
       j++;
      }
      if(j==l2)
      {
        return i;
      }
    }
    return -1;
  }
  
    
