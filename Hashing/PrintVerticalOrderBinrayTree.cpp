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


void getHorizontalDistance(Node *root,int hd,map<int,vector<int>> &mp){
    
    if(root==NULL)return;
    mp[hd].push_back(root->data);
    
    getHorizontalDistance(root->left,hd-1,mp);
    getHorizontalDistance(root->right,hd+1,mp);
}

void printVerticalOrder(Node *root){
    
    map<int,vector<int>> mp;
    int hd=0;
    getHorizontalDistance(root,hd,mp);
    
    for(auto it=mp.begin();it!=mp.end();++it){
         
         for(int i=0;i<it->second.size();i++)
             cout<<it->second[i]<<" ";
         cout<<endl;     
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
