#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    Node* next;
    int data;
    Node(int val)
    {
     next=NULL;
     data=val;
    }
};

void push_b(stack<int>&s,int v)
{
if(s.empty())
{
s.push(v);
return;
}

int temp=s.top();
s.pop();
push_b(s,v);
s.push(temp);
}

void reverse(stack<int>&s)
{
if(!s.empty())
{
int v=s.top();
s.pop();
reverse(s);
push_b(s,v);
}
}

int main()
{
stack<int>s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);

reverse(s);
while(!s.empty())
{
cout<<s.top()<<endl;
s.pop();
}
}

