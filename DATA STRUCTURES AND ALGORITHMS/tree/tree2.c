#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
    int e;
    struct tnode *left,*right;
};
struct queue{
struct tnode* a[10];
int f,r,n;
};
int display(struct tnode*);
struct tnode* insert(struct tnode* ,int);
struct tnode* dequeue(struct queue*);
int enqueue(struct queue*,struct tnode*);
struct tnode* parent(struct tnode*,struct tnode*);
struct tnode* insert(struct tnode *root,int ele)
{
    struct tnode *temp,*temp1;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    temp->left=NULL;
    temp->right=NULL;
    temp->e=ele;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct queue *q;
        q=(struct queue*)malloc(sizeof(struct queue));
        q->f=-1,q->r=-1,q->n=50;
        enqueue(q,root);
        while(q->r!=q->f)
        {
            temp1=dequeue(q);
            if(temp1->left!=NULL)
                enqueue(q,temp1->left);
            else
                break;
            if(temp1->right!=NULL)
                enqueue(q,temp1->right);
            else
                break;
        }
        if(temp1->left==NULL)
           temp1->left=temp;
        else
            temp1->right=temp;
    }
    return(root);
}
int display(struct tnode *root)
{
    struct tnode *temp1,*temp;
    if(root==NULL)
    {
        printf("tree is empty\n");
    }
    else
    {
     struct queue *q;
        q=(struct queue*)malloc(sizeof(struct queue));
        q->f=-1,q->r=-1,q->n=50;
        enqueue(q,root);
        while(q->r!=q->f)
        {
            temp1=dequeue(q);
            printf("%d\n",temp1->e);
            if(temp1->left!=NULL)
            {
                enqueue(q,temp1->left);
            }
            if(temp1->right!=NULL)
            {
                enqueue(q,temp1->right);
            }
        }
    }
}
int max(struct tnode *root,int o)
{

    struct tnode *temp1,*temp;
    int tem,max=0,min=0,i,c=0;
    if(root==NULL)
    {
        printf("tree is empty\n");
    }
    else
    {
     struct queue *q;
        q=(struct queue*)malloc(sizeof(struct queue));
        q->f=-1,q->r=-1,q->n=50;
        enqueue(q,root);
        min=root->e;
        while(q->r!=q->f)
        {
            temp1=dequeue(q);
            tem=temp1->e;
            if(o==1)
            {
            if(max<tem)
                max=tem;
            }
            if(o==2)
            {
            if(min>tem)
                min=tem;
            }
            if(o==3)
            {
                if(tem%2==0)
                    printf("%d\n",tem);
            }
            if(o==4)
            {
                if(tem%2!=0)
                  printf("%d\n",tem);
            }
            if(o==5)
            {
                c=0;
                for(i=2;i<=tem;i++)
                {
                    if(tem%i==0)
                        c++;
                }
                if(c==1)
                    printf("%d",tem);
            }
            if(temp1->left!=NULL)
            {
                enqueue(q,temp1->left);
            }
            if(temp1->right!=NULL)
            {
                enqueue(q,temp1->right);
            }
        }
        if(o==1)
         printf("%d is maximum element among all\n",max);
        if(o==2)
          printf("%d is manimum element among all\n",min);
    }
}
int enqueue(struct queue *q,struct tnode *temp1)
{
    (q->r)=(q->r)+1;
    q->a[q->r]=temp1;
}
struct tnode* dequeue(struct queue *q)
{
    (q->f)=(q->f)+1;
    return((q->a)[q->f]);
}
struct tnode* del(struct tnode *root)
{
    int d;
    printf("enter the element to delete");
    scanf("%d",&d);
    struct tnode *temp=root,*tem,*t;
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct tnode));
    q->f=-1,q->r=-1;
    enqueue(q,temp);
    while(q->f!=q->r)
    {
        temp=dequeue(q);
        if(temp->e==d)
            tem=temp;
        if(temp->left!=NULL)
            enqueue(q,temp->left);
        if(temp->right!=NULL)
            enqueue(q,temp->right);
    }
    tem->e=temp->e;
    printf("hoooo");
    t=parent(root,temp);
    if(t->left==temp)
        t->left=NULL;
    else
        t->right=NULL;
    return(root);
}
struct tnode* parent(struct tnode *root,struct tnode *tem)
{
    struct tnode *temp=root;
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->f=-1,q->r=-1;
    enqueue(q,temp);
    while(q->f!=q->r)
    {
        temp=dequeue(q);
        if(temp->left==tem)
            return (temp);
        if(temp->left!=NULL)
        {
          enqueue(q,temp->left);
        }
        if(temp->right==tem)
            return (temp);
        if(temp->right!=NULL)
        {
            enqueue(q,temp->right);
        }
    }

}
int main()
{
 struct tnode *root=NULL;
 int op,ele,opt;
 do{
 printf("enter the option 1-insert;2-display;3-(max,min,even,odd),4-delete,5-exit");
 scanf("%d",&op);
 switch(op)
 {
 case 1:
    printf("enter the element to insert:");
    scanf("%d",&ele);
    root=insert(root,ele);
    break;
 case 2:
    display(root);
    break;
 case 3:
    printf("enter 1-max,2-min,3-even,4-odd,5-prime");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        max(root,1);
        break;
    case 2:
        max(root,2);
        break;
    case 3:
        max(root,3);
        break;
    case 4:
        max(root,4);
        break;
    case 5:
        max(root,5);
    }
    break;
 case 4:
     root=del(root);
     break;
 }
 }while(op!=5);
}

