#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left,*right;
};

Node* build(int *inorder,int N)
{
  if(N==0) return NULL;
  
  Node *root=new Node();
  Node *head=root;
  Node *temp;
  
  stack<Node*> S;
  root->data=inorder[0];
  root->left=root->right=NULL;
  
  for(int i=1;i<N;++i)
  {
    temp=new Node();
    temp->data=inorder[i];

    if(inorder[i]<root->data)
    {
        root->right=temp;
        temp->left=temp->right=NULL;
        S.push(root);
    }
    else if(inorder[i]>root->data)
    {
        while(S.empty()==false&&S.top()->data<inorder[i])
        {
           root=S.top();
           S.pop();
        }
        
        if(S.empty())
           head=temp;
        else
           S.top()->right=temp;
           
        temp->left=root;
        
    }
    root=temp;
  }
  return head;
}

void Preorder(Node *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if(root==NULL)
        return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if(root==NULL)
        return ;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int N,i,data,inorder[20];
    Node *root=NULL;
    cin>>N;
    for(i=0;i<N;++i)
        cin>>inorder[i];
    root=build(inorder,N);
    Preorder(root);         
        cout<<endl;
    Inorder(root);          
        cout<<endl;
    
    Postorder(root);        
        cout<<endl;
        
}

