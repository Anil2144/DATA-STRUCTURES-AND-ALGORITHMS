#include<stdio.h>
#include<string.h>
struct stack {
int top;
char a[20];
}s;
int pre(char);
int main()
{
    int l,i;
char str[20];
printf("enter th expression:");
gets(str);
puts(str);
l=strlen(str);
for(i=0;i<l;i++)
{
if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
{
 printf("%c",str[i]);
}
else if(str[i]=='(')
{
   s.a[++s.top]=str[i];
}
else if(str[i]==')')
{
    while(s.a[s.top]!='(')
    {
        printf("%c",s.a[s.top]);
        s.top--;
    }
    s.top--;
}
else if((pre(s.a[s.top]))<(pre(str[i])))
{
    s.a[(++(s.top))]=str[i];

}
else if(pre(s.a[s.top])>=pre(str[i]))
{
    while(pre(s.a[s.top])>=pre(str[i]))
    {
        printf("%c",s.a[s.top]);
        s.top--;
    }
    s.a[(++s.top)]=str[i];
}
}
while(s.top!=-1)
{
    printf("%c",s.a[s.top--]);
}
}
int pre(char c)
{
    if(c=='+'||c=='-')
      return 1;
    else if(c=='/'||c=='*')
      return 2;
   else if(c=='^')
      return 3;
    else
    return -1;
}
