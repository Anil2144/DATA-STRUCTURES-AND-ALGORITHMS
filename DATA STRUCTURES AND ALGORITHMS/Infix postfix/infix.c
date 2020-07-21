#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
	char a[100];
	int top;
};
void push(struct stack *st,char ch)
{
	st->top+=1;
	st->a[st->top]=ch;
}
char pop(struct stack *st)
{
	char k=st->a[st->top];
	st->top-=1;
	return k;
}
char top(struct stack *st)
{
	if(st->top==-1)
	{
		return '&';
	}
	else
	{
		char c=st->a[st->top];
		return c;
	}
}
int prec(char ch)
{
	if(ch=='^')
		return 4;
	else if(ch=='*' || ch=='/')
		 return 3;
	else if(ch=='+' || ch=='-')
		 return 2;
	else
		return -1;
}
void main()
{
	char s[100],c;
	int n,k,i;
	struct stack *st;
	st=(struct stack *)malloc(sizeof(struct stack));
	st->top=-1;
	printf("Enter the expression:");
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
		{
			printf("%c",s[i]);
		}
		else if(s[i]=='(')
		{
			push(st,s[i]);
		}
		else if(s[i]==')')
		{
			while(top(st)!='(')
			{
				c=pop(st);
				printf("%c",c);
			}
			pop(st);
		}
		else if(prec(top(st))<prec(s[i]))
		{
			push(st,s[i]);
			
		}
		else if(prec(top(st))>=prec(s[i]))
		{
			while(prec(top(st))>=prec(s[i]))
			{
				c=pop(st);
				printf("%c",c);
			}
			push(st,s[i]);
		}
	}
	while(st->top!=-1)
	{
		c=pop(st);
		printf("%c",c);
	}
}
