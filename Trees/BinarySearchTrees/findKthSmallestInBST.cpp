#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};


Node *insertBST(Node *root,int key){
	if(root==NULL){
		Node *temp=new Node(key);
		return temp;
	}
	
	if(key<root->data){
		root->left=insertBST(root->left,key);
	}
	if(key>root->data){
		root->right=insertBST(root->right,key);
	}
	return root;
}

void inorder_traversal(Node *root , vector<int> &v1) //finding kth e;ement using simply vector pushback 
{
    if (root != NULL)
    {
        inorder_traversal(root->left, v1);
        printf("%d ", root->data);
        v1.push_back(root->data);
        inorder_traversal(root->right,v1);
    }
}


Node *findKthSmallestInBST(Node *root,int k){
	if(root==NULL)return NULL;
	
	stack<Node *> s;
	int current=0;
	
	s.push(root);
	while(root){
		
		while(root){
			s.push(root);
			root=root->left;
		}
	
		while(!s.empty()){
		
			Node *cNode=s.top();
			s.pop();
			current++;
		
			if(current==k){
				cout<<cNode->data<<" ";
				return cNode;
			}
		
			if(cNode->right){
				root=cNode->right;
				break;
			}
		}
	}
	return NULL;
}


int main()
{
	Node*root=NULL;
	root=insertBST(root,50);
    insertBST(root,30);
    insertBST(root,20);
    insertBST(root,40);
    insertBST(root,70);
    insertBST(root,60);
    insertBST(root,80);
	vector<int> v1;
	int k=4;
    
    inorder_traversal(root,v1);
    
    printf("\nKth smallest element is %d \n", v1[k-1]);
    
    Node *kth=findKthSmallestInBST(root,k);
    if(kth)
    printf("\nKth node is %d ",kth->data);
    else
    printf("\nNo node exists");
	return 0;
}
