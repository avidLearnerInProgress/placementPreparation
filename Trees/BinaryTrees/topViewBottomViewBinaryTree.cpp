#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data,hd;
	Node *left,*right;
	
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void printBottomView(Node *root){
	if(root==NULL)return;
	queue<Node *> q;
	map<int,int> m;
	int hd=INT_MAX;
	root->hd=hd;
	q.push(root);
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		hd=temp->hd;
		m[hd]=temp->data;
		if(temp->left){
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		if(temp->right){
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}
	for(auto it=m.begin();it!=m.end();it++)
		cout<<it->second<<" ";
	
}

void printTopView(Node *root){
	
	if(root==NULL)return;
	
	queue<Node *> q;
	map<int,int> m;
	int hd=0;
	root->hd=hd;
	q.push(root);
	while(q.size()){
		
		hd=root->hd;
		if(m.count(hd)==0)
			m[hd]=root->data;
		
		if(root->left){
			root->left->hd=hd-1;
			q.push(root->left);
		}
		if(root->right){
			root->right->hd=hd+1;
			q.push(root->right);
		}
		q.pop();
		root=q.front();
	}
	vector<int> v;
	for(auto it=m.begin();it!=m.end();it++)
		v.push_back(it->second);
		
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++) 
		cout<<v[i]<<" ";
		
}

int main()
{
   Node *root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->right=new Node(4);
   root->left->right->right=new Node(5);
   root->left->right->right->right=new Node(6);
   printTopView(root);
   cout<<endl;
   printBottomView(root);
}
