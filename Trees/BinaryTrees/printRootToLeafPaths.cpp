#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left,*right;
	node(int x){
		data=x;
		left=right=NULL;
	}
};
 
 
vector<vector<int> >allpaths;
void paths(struct node* r,vector<int>v){
	if(!r){
		return;
	}
	v.push_back(r->data);
	if((!r->left)&&(!r->right)){
		allpaths.push_back(v);
	}
	paths(r->left,v);
	paths(r->right,v);
}
 
 
int main()
{
	struct node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	vector<int>v;
	paths(root,v);
	for(int i=0;i<allpaths.size();i++){
		for(int j=0;j<allpaths[i].size();j++){
			cout<<allpaths[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
