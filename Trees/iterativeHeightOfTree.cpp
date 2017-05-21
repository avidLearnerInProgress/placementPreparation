 #include<bits/stdc++.h>
using namespace std;

struct Node{
	
	int data;
	struct Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}

};

int iterativeHeight(Node *root){
	
	
	if(!root)
		return 0;
	int count=0;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		if(temp!=NULL){
			if(temp->left)q.push(temp->left);
			if(temp->right)q.push(temp->right);
		}
		else{
			count++;
			if(!q.empty())q.push(NULL);
		}
		
	}
	return count;
}

int main(){
	Node *root = new Node(1);
	root->left =  new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	cout<<iterativeHeight(root)<<endl;
}
