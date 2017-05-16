#include <bits/stdc++.h>
using namespace std;
struct node
{
	int  data;
	node *left;
	node *right;
	node(int x){
		data=x;
		left=right=NULL;
	}
};

node *root=NULL;
queue<node *> q;

void Insert(int data)
{
	node *temp=new node(data);
	if(!root)
	{
		root=temp;
	}
	else{
		node *temp1=q.front();
	
		if(!(temp1->left))
			temp1->left=temp;
		
		else if((!temp1->right))
			temp1->right=temp;
		
		if(temp1&&temp1->left&&temp1->right)
			q.pop();
	}
	
	q.push(temp);
}

void LevelOrder(node *root)
{
	queue<node *> q1;
	q1.push(root);
	
	while(!q1.empty())
	{
		node *temp=q1.front();
		
		q1.pop();
		cout<<temp->data<<" ";
		if(temp->left)
		q1.push(temp->left);
		if(temp->right)
		q1.push(temp->right);
	}
}

int main()
{
	for(int i=1;i<=12;++i)
	{
		Insert(i);
	}
	LevelOrder(root);
 return 0;
}

