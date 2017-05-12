#include<bits/stdc++.h>
using namespace std;

void print(stack<int>&s)
{
    if(s.empty())
    {
        cout<<endl;
        return;
    }
        int x=s.top();
        cout<<x<<" ";
        s.pop();
        print(s);
        s.push(x);
}

void main_sort(stack<int>&s,int data)
{
    if(s.empty())
    {
        s.push(data);
    }
    else
    {
        if(data>s.top())
            s.push(data);
        else
        {
            int temp=s.top();
            s.pop();
            main_sort(s,data);
            s.push(temp);
        }
    }
}
void sort(stack<int>&s)
{
    if(!s.empty())
    {
        int temp=s.top();
        s.pop();
        sort(s);
        main_sort(s,temp);
    }
}
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    print(s);
    sort(s);
    print(s);
}
 
