#include<stdio.h>
#include<stdlib.h>
struct tnode
{
    int e;
    struct tnode *left,*right;
};
struct queue{
int a[10];
int f,r,n;
};
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
            if(temp1->left==NULL)
                break;
            else
                enqueue(q,temp1->left);
            if(temp1->right==NULL)
                break;
            else
                enqueue(q,temp1->right);
        }
        if(temp1->left=NULL)
           temp1->left=temp;
        else
            temp1->right=temp;
    }
}
int display(struct tnode *root)
{
    struct tnode *temp1=root;
    if(root==NULL)
    {
        printf("tree is empty");
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
            printf("%d",temp1->e);
            if(temp1->left==NULL)
               break;
            else
                enqueue(q,temp1->left);
            if(temp1->right==NULL)
               break;
            else
                enqueue(q,temp1->right);
        }
    }

}
int enqueue(struct queue *q,int ele)
{
    q->r=q->r+1;
    q->a[q->r]=ele;
}
struct queue* dequeue(struct queue *q)
{
    q->f=q->f+1;
    return(q->a[q->f]);
}
int main()
{
 struct tnode *root=NULL;
 int op,ele;
 do{
 printf("enter the option 1-insert,2-display");
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
 }
 }while(op!=3)

}
