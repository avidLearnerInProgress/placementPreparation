#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void printAncestorsOfNode(Node* root,int key)
{
    if(!root||root->data==key)
        return;
 
    stack<Node*> s;
 
    while(true)
    {
        while(root&&root->data!=key)
        {
            s.push(root);
            root=root->left;
        }
 
        if(root&&root->data==key)
            break;
 
        if(s.empty())
            break;
 
        if(!s.top()->right)
        {
            root=s.top();
            s.pop();
            while(!s.empty()&&s.top()->right==root)
            {
                root=s.top();
                s.pop();
            }
        }
 
        if(s.empty())
            break;
 
        root=s.top()->right;
    }
 
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main()
{
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);
 
    printf("Following are all keys and their ancestors\n");
    for (int key = 1; key <= 10; key++)
    {
        printf("%d: ", key);
        printAncestorsOfNode(root, key);
        printf("\n");
    }
    return 0;
}

