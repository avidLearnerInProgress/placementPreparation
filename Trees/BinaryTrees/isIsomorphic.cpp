#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=NULL;right=NULL;
	}
};

bool isIsomorphic(Node* n1, Node *n2)
{

 if (n1==NULL && n2==NULL)
    return true;
 if (n1==NULL||n2==NULL||n1->data!=n2->data)
    return false;
 
 return(isIsomorphic(n1->left,n2->left)&&isIsomorphic(n1->right,n2->right))||(isIsomorphic(n1->left,n2->right)&&isIsomorphic(n1->right,n2->left));
}

int main(){
    
    Node *n1=new Node(1);
    n1->left=new Node(2);
    n1->right=new Node(3);
    n1->left->left=new Node(4);
    n1->left->right=new Node(5);
    n1->right->left=new Node(6);
    n1->left->right->left=new Node(7);
    n1->left->right->right=new Node(8);
    
    Node *n2=new Node(1);
    n2->left=new Node(2);
    n2->right=new Node(3);
    n2->left->left=new Node(4);
    n2->left->right=new Node(5);
    n2->right->left=new Node(6);
    n2->left->right->left=new Node(7);
    n2->left->right->right=new Node(8);
 
   
    if(isIsomorphic(n1,n2))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 
    return 0;
}
