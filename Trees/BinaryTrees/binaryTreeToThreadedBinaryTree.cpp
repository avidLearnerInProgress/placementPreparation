#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	bool isThreaded;
	Node(int x){
		data=x;
		left=right=NULL;
	
	}
};

void insertIntoQueue(Node *root,queue<Node *> *q){
	if(root==NULL)return;
	if(root->left)insertIntoQueue(root->left,q);
	q->push(root);
	if(root->right)insertIntoQueue(root->right,q);
}



void createTBTUtil(Node *root,queue<Node *> *q){
	if(root==NULL)return;
	if(root->left)createTBTUtil(root->left,q);
	q->pop();
	if(root->right)createTBTUtil(root->right,q);
	else{
		root->right=q->front();
		root->isThreaded=true;
	}
	
}

void createTBT(Node *root){
	
	queue<Node *> q;
	
	insertIntoQueue(root,&q);
	createTBTUtil(root,&q);
	
}


Node *leftMostNode(Node *root){

	while(root!=NULL && root->left!=NULL){
		root=root->left;
	}
	return root;

}

void inOrder(Node *root){
	if(root==NULL)return;
	Node *current=leftMostNode(root);
	
	while(current!=NULL){
		cout<<current->data<<" ";
		
	
		if(current->isThreaded)current=current->right;
		else{
			current=leftMostNode(current->right);
		}
	}	
	
}

int main()
{
    /*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    createTBT(root);
 
    cout << "Inorder traversal of creeated threaded tree is\n";
    inOrder(root);
    return 0;
}
