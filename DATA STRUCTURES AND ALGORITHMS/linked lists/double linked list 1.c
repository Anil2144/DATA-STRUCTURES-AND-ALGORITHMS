#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *pre;
    int e;
    struct node *nxt;
};
struct node* insert(struct node*);
struct node* insertf(struct node *);
//int insertm(struct node *);
//int find(struct node*);
void display(struct node*);
int deletem(struct node*);
int deleteb(struct node*);
struct node* deletebig(struct node*);
int print();
int main()
{
    struct node *head;
    head=NULL;
    int op;
    do{
    printf("enter 1-insertback,2-insertfront,3-insertmiddle,4-deleteb,5-deletem,6-deletebig,7-find,8-display,9-exit\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:head=insert(head);
        break;
        case 2:head=insertf(head);
        break;
        //case 3:insertm(head);
        //break;
        case 4:deleteb(head);
        break;
        case 5:deletem(head);
        break;
        case 6:head=deletebig(head);
        break;
       // case 7:find(head);
        //break;
        case 8:display(head);
        break;
        case 9:break;
    }
}while(op!=9);
}
struct node* insert(struct node *head)
{
    struct node *temp,*temp1=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->e=print();
    temp->nxt=NULL;
    temp->pre=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(temp1->nxt!=NULL)
        {
            temp1=temp1->nxt;
        }
        temp1->nxt=temp;
        temp->pre=temp1;
    }
    return head;
}
/*int find(struct node *head)
{
    struct node *temp;
    temp=head;
    int ele,c=0;
    printf("enter the element to search:");
    scanf("%d",&ele);
    while(temp!=NULL)
    {

        if(temp->e==ele)
        {
            c=1;
            printf("%d element find at %d\n",ele,c);
            break;
        }

        temp=temp->nxt;
    }
    if(c==0)
      printf("invalid element");
}*/
void display(struct node *head)
{
    int c=0;
    while(head!=NULL)
   {
      c++;
     printf("%d->",head->e);
     head=head->nxt;
   }
printf("\nlinks count=%d\n",c);
}
struct node* insertf(struct node *head)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->e=print();
    temp->nxt=NULL;
    temp->pre=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->nxt=head;
        temp->nxt->pre=temp;
        head=temp;
    }
    return(head);
}
int insertm(struct node *head)
{
    struct node *temp,*temp1=head,*tem;
    int ele;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->e=print();
    printf("enter the element before which u want 2 insert:");
    scanf("%d",&ele);
    while(temp1->e!=ele)
    {
        tem=temp1;
        temp1=temp1->nxt;
    }
    temp->nxt=tem->nxt;
    temp->pre=tem;
    tem->nxt=temp;
    temp1->pre=temp;
}
int print()
{
    int ele;
     printf("enter the element to insert:");
     scanf("%d",&ele);
     return(ele);
}
int deleteb(struct node *head)
{
    struct node *temp1=head,*tem;
    while(temp1->nxt!=NULL)
    {
        tem=temp1;
        temp1=temp1->nxt;
    }
    tem->nxt=NULL;
}
int deletem(struct node *head)
{
    int ele;
    struct node *temp1=head,*tem;
    printf("enter the element to delete:");
    scanf("%d",&ele);
    while(temp1->e!=ele)
    {
        tem=temp1;
        temp1=temp1->nxt;
    }
    tem->nxt=temp1->nxt;
    temp1->nxt->pre=tem;
}
struct node* deletebig(struct node *head)
{
    head=head->nxt;
    head->pre=NULL;
    return(head);
}
