#include<stdio.h>
#include<string.h>
struct stack
{
  char a[100];
  int top;
}s;
int push(struct stack *,char);
int pop(struct stack *);
int precise(char);
int main()
{
    int i,l,g;
    char str[100];
    printf("enter the string:");
    scanf("%s",str);
    l=strlen(str);
    s.top=-1;
for(i=0;i<l;i++)
    {
       // printf("%d\n",l);
        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
        {
            printf("%c",str[i]);
        }
        else if(str[i]=='(')
        {
            push(&s,str[i]);
        }
        else if(str[i]==')')
        {
            while(s.a[s.top]!='(')
            {
              pop(&s);
            }
            s.top--;
        }
        else
        {
            while(precise(str[i])<=precise(s.a[s.top])&&s.top!=-1)
            {
                pop(&s);
            }
            push(&s,str[i]);
        }
    }
    while(s.top!=-1)
    {
        printf("%c",s.a[s.top]);
        s.top--;
    }
}
int pop(struct stack *s)
{
    printf("%c",s->a[s->top]);
    s->top=s->top-1;
}
int push(struct stack *s,char e)
{
    s->top=s->top+1;
    s->a[s->top]=e;
   // printf("...%c\n",s->a[s->top]);
}
int precise(char e)
{
    if(e=='*'||e=='/')
        return(3);
    else if(e=='+'||e=='-')
        return(2);
     else
        return(1);
}
