#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *left;
int data;
struct node *right;
};
struct node* newnode(int ele)
{
 struct node* temp=(struct node*)malloc(sizeof(struct node));
       temp->left=NULL;
       temp->right=NULL;
       temp->data=ele;
       return temp;
}
struct node* insert(struct node* head,int ele)
{
    if(head==NULL)
    {
        return newnode(ele);
    }
    if(ele<head->data)
    {
        head->left=insert(head->left,ele);
    }
    else
    {
        head->right=insert(head->right,ele);
    }
    return head;
}
void inorder(struct node* head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        printf("%d",head->data);
        inorder(head->right);
    }
}
void preorder(struct node* head)
{
    if(head!=NULL)
    {
        printf("%d",head->data);
        preorder(head->left);
        preorder(head->right);
    }
}
void postorder(struct node* head)
{
    if(head!=NULL)
    {
        postorder(head->left);
        postorder(head->right);
        printf("%d",head->data);
    }
}

int main()
{
    int n,ele,op;
    struct node *head=NULL;
    do
    {
    printf("enter 1-insert,2-inorder,3-postorder,4-preorder");
    scanf("%d",&n);
    switch(n)
    {
    case 1: printf("enter the value to insert");
            scanf("%d",&ele);
            head=insert(head,ele);
            break;
    case 2:inorder(head);
           break;
    case 3:postorder(head);
           break;
    case 4:preorder(head);
           break;
    }
    }while(op!=5);

}
