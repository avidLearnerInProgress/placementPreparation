#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}


void reversePrint(Node *root)
{
    //Your code here
    if(!root)return;
    
    stack<Node *> s;
    queue<Node *> q;
    
    q.push(root);
    while(!q.empty()){
        
        Node *temp=q.front();
        s.push(temp);
        q.pop();
        
        if(temp->right)q.push(temp->right);
        if(temp->left)q.push(temp->left);
        

    }
    
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    
}


int main()
{
   int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

   reversePrint(root);
   cout<<endl;

  }
    return 0;
}



/* STD INPUT
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
*/
