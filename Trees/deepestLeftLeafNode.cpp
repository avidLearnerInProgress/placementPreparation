#include<bits/stdc++.h>
using namespace std;

struct Node
{
       int info;
       Node *left;
       Node *right;
 
};

Node* newNode(int n)
{
      Node *newN=new Node();
      newN->info=n;
      newN->left=NULL;
      newN->right=NULL;
      return newN;
}

void printdll(Node *temp)
{
              while(temp!=NULL)
              {
                               printf("%d ",temp->info);
                               temp=temp->right;
              }
}

void inorder(Node *root)
{
             if(root==NULL)return ;
             inorder(root->left);
             printf("%d ",root->info);
             inorder(root->right);
             return ;
}

Node* deepest(Node *root,int level)
{
      static int max=0;
      if(root==NULL)return NULL;
 
      if(root->left==NULL&&root->right==NULL)
      {
                                             if(level>max){
                                                       max=level;
                                                       return root;
                                                       }
                                             else
                                             {
                                                 return NULL;
 
                                             }
 
      }
 
      Node *a=deepest(root->left,level+1);
      Node *b=deepest(root->right,level+1);
      if(b!=NULL)return b;
      else return a;
   
}


int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    inorder(root);
    printf("\n");
    Node *temp=deepest(root,1);
    printf("%d",temp->info);

    return 0;
}    
