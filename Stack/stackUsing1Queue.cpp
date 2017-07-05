#include<iostream>
#include<queue>
using namespace std;

void push(int val,queue<int>&q1)
{
    int s=q1.size();
    q1.push(val);
    
    for(int i=0;i<s;i++){
        q1.push(q1.front());
        q1.pop();
    }
}

int pop(queue<int>&q1)
{
    if(q1.empty())return -1;
    int x=q1.front();
    q1.pop();
    return x;
}

int main()
{
queue<int>q1,q2;
push(1,q1);
push(2,q1);
push(3,q1);
push(4,q1);
push(5,q1);
cout<<pop(q1);
cout<<pop(q1);
cout<<pop(q1);
cout<<pop(q1);
cout<<pop(q1);

}

