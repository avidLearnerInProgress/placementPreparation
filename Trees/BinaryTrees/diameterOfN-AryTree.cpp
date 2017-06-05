#include<bits/stdc++.h>
using namespace std;

struct Node{
	char key;
	vector<Node *> child;
};


Node *newNode(char key){
	Node *temp=new Node;
	temp->key=key;
	return temp;
}

int diameter(Node *root,int *height){
	if(root==NULL){
		*height=0;return 0;
	}
	
	int max1=0,max2=0,length=0;
	int maxChildDiameter=0;
	
	for(auto it=root->child.begin();it!=root->child.end();it++){
		maxChildDiameter=max(maxChildDiameter,diameter(*it,&length));
		if(length>max1){
			max2=max1;max1=length;
		}
		if(length>max2)max2=length;
	}
	*height=max(max1,max2)+1;
	
	return max(maxChildDiameter,max1+max2+1);
}


int main(){
	Node *root = newNode('A');
	(root->child).push_back(newNode('B'));
	(root->child).push_back(newNode('F'));
	(root->child).push_back(newNode('D'));
	(root->child).push_back(newNode('E'));
	(root->child[0]->child).push_back(newNode('K'));
	(root->child[0]->child).push_back(newNode('J'));
	(root->child[2]->child).push_back(newNode('G'));
	(root->child[3]->child).push_back(newNode('C'));
	(root->child[3]->child).push_back(newNode('H'));
	(root->child[3]->child).push_back(newNode('I'));
	(root->child[0]->child[0]->child).push_back(newNode('N'));
	(root->child[0]->child[0]->child).push_back(newNode('M'));
	(root->child[3]->child[2]->child).push_back(newNode('L'));
	int height=0;
	cout<<diameter(root,&height)<<endl;

return 0;
}
