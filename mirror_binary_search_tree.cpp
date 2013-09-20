#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
typedef struct Node
{
    int data;
    struct Node* left;
   struct Node* right;
}Node;

Node* insert_util(Node*root , Node* temp)
{
    if(root==NULL)
        root=temp;
    else if(temp->data>root->data)
    {
        root->right=insert_util(root->right,temp);
    }
    else
        root->left=insert_util(root->left,temp);

    return root;
}
Node* insert(Node* root,int val)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->left=temp->right=NULL;
    temp->data=val;
    return insert_util(root,temp);
}

void display_inorder(Node* root)
{
    if(root==NULL)
        return;

    display_inorder(root->left);
    cout<<root->data<<"\t";
    display_inorder(root->right);
}
Node* insert_mirror(Node* root,Node* temp)//insert in mirror order i.e greater to left and lower to right( reverse of usual binary tree)
{
    if(root==NULL)
        root=temp;
    else if(temp->data>root->data)
        root->left=insert_mirror(root->left,temp);
    else
        root->right=insert_mirror(root->right,temp);
    return root;
}
Node* mirror_new_tree(Node* root)
{
    if(root==NULL)
        return NULL;
    Node* new_root=NULL;
    queue<Node*> s;
    s.push(root);
    Node* temp;
    Node* temp2;
    while(s.empty()==false)
    {


        temp=s.front();
        temp2=(Node*)malloc(sizeof(Node));
        temp2->right=temp2->left=NULL;
        temp2->data=temp->data;
        new_root=insert_mirror(new_root,temp2);

        s.pop();
        if(temp->left)s.push(temp->left);
        if(temp->right)s.push(temp->right);
    }
    return new_root;



}
int main()
{
    Node* root=NULL;
    Node* new_root=NULL;
    root=insert(root,6);
    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,9);
    display_inorder(root);
    cout<<endl;
    new_root=mirror_new_tree(root);
    display_inorder(new_root);
}
