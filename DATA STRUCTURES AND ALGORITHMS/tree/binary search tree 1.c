#include<stdio.h>
#include<stdlib.h>
struct node{
int ele;
struct node *left,*right;
};
struct node* insert(struct node*,int);
struct node* newnode(int);
void display(struct node*);
int main()
{
    int n,ele;
    struct node *root=NULL;
    do{
        printf("1-insert,2-delete,3-display");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("enter the element to insert");
                    scanf("%d",&ele);
                    root=insert(root,ele);
                    break;
            case 2:display(root);
        }
    }while(n!=3);
}
struct node* insert(struct node* root,int ele)
{
    if(root==NULL)
        return newnode(ele);
    if(root->ele<ele)
        root->left=insert(root->left,ele);
        //printf("%d",root->ele);
    else if(root->ele>ele)
        root->right=insert(root->right,ele);
    return root;
}
struct node* newnode(int ele)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->ele=ele;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void display(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->ele);
        display(root->left);
        display(root->right);
    }
}
struct node* deleted(struct node* root,int ele)
{
    if(root==NULL)
    {
        return root;
    }
    if()
};
