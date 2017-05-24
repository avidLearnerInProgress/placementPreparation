#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
  int data;
  Node *left,*right;
  Node(int x){
  	data=x;
  	left=right=NULL;
  }
};
 

void printKeys(Node *root, int k1, int k2)
{
   if(!root)return;
 
   if(k1<root->data)printKeys(root->left,k1,k2);
 
  if(k1<=root->data && k2>=root->data)cout<<root->data<<" ";
 
  if(k2>root->data)printKeys(root->right,k1,k2);
}
 
 
int main()
{
  Node *root=NULL;
  int k1=10,k2=25;
  root=new Node(20);
  root->left=new Node(8);
  root->right=new Node(22);
  root->left->left=new Node(4);
  root->left->right=new Node(12);
  printKeys(root,k1,k2);
  return 0;
}
