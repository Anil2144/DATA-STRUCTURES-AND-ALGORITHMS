#include<stdio.h>
#include<stdlib.h>
struct tnode{
int key;
struct tnode *left,*right;
};
struct tnode* insert(struct tnode*,int);
struct tnode* nnode(int);
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
        inorder(root);
    }
    }while(op!=3);
}
struct tnode* insert(struct tnode *root,int ele)
{
    struct tnode *temp=root;
    if(root==NULL)
    {
     return(nnode(ele));
    }
    if(ele<root->key)
        root->left=insert(root->left,ele);
    if(ele>root->key)
        root->right=insert(root->right,ele);
    return(root);
}
struct tnode* nnode(int ele)
{
    struct tnode *temp;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=ele;
    printf(".......");
    return(temp);
}
int inorder(struct tnode *root)
{

    if(root!=NULL)
    {`
        inorder(root->left);
        printf("%d",root->key);
        inorder(root->right);
    }
}
