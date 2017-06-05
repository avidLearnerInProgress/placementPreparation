#include<bits/stdc++.h>
using namespace std;
 

struct node
{
    int data;
    node* left, *right;
};
 
node *newNode(int data)
{
    node *temp = new node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
bool inRange(node *root,int min,int max){
	return root->data>=min && root->data<=max;
}

bool getCountUtil(node *root,int min,int max,int *count){
	if(root==NULL)return true;
	
	bool l=(root->left)?getCountUtil(root->left,min,max,count):true;
	bool r=(root->right)?getCountUtil(root->right,min,max,count):true;
	
	if(l&&r && inRange(root,min,max)){
		++*count;
		return true;
		
	}
	return false;
}

int getCount(node *root, int low, int high)
{
    int count=0;
    getCountUtil(root, low, high, &count);
    return count;
}
 

 
int main()
{
    // Let us construct the BST shown in the above figure
    node *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 5;
    int h = 45;
    cout << "Count of subtrees in [" << l << ", "
         << h << "] is " << getCount(root, l, h);
    return 0;
}
