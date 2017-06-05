#include <iostream> 
#include <stack> 
using namespace std;
 
/* Author : Dilip.K */
struct node
{
    node* left;
    node* right; 
    int data;
};
 
node* newNode(int x)
{
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=x;
    return temp;
}
 
struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data <= node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
 
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}
 
 void printCommon(node* root1,node* root2)
 {
     if(root1==NULL || root2==NULL)
         return;
 
     stack<node*> s1,s2;
     int x,y;
     while(1)
     {
         while(root1)
         {
             s1.push(root1);
             root1=root1->left;
         }
         while(root2)
         {
             s2.push(root2);
             root2=root2->left;
         }
 
         if(s1.empty()||s2.empty())
             break;
 
         x=s1.top()->data;
         y=s2.top()->data;
 
         if(x==y)
         {
                 cout<<x<<" ";
                 root1=s1.top()->right;
                 root2=s2.top()->right;
                 s1.pop();
                 s2.pop(); 
         }
         else if(x<y)
         { 
                 root1=s1.top()->right;
                 s1.pop(); 
         }
         else
         {
             root2=s2.top()->right;
                 s2.pop(); 
         }
     }
     cout<<endl;
 }
 
int main()
{
    // Create first tree as shown in example
    node *root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);
 
    // Create second tree as shown in example
    node *root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
 
    cout << "Tree 1 : ";
    inorder(root1);
    cout << endl;
 
    cout << "Tree 2 : ";
    inorder(root2);
 
    cout << "\nCommon Nodes: ";
    printCommon(root1, root2);
 
    return 0;
}
