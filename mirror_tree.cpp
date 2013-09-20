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
Node* mirror_new_tree(Node* root)
{
    if(root==NULL)
        return NULL;
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    root->left=mirror_new_tree(root->left);
    root->right=mirror_new_tree(root->right);
    return root;
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
        root=insert(root,1);

    root=insert(root,2);

    display_inorder(root);
    cout<<endl;
    new_root=mirror_new_tree(root);
    display_inorder(new_root);
}

