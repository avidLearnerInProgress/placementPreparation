#include<iostream>
#include<queue>
using namespace std;

void push(int val,queue<int>&q1,queue<int>&q2)
{
	if(q1.empty())
	{
		q1.push(val);
		while(!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}
	else //if (q2.empty())
	{
		q2.push(val);
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
	}
}

int pop(queue<int>&q1,queue<int>&q2)
{
	int front=-1;
	if(!q1.empty())
	{
		front=q1.front();
		q1.pop();
	}
	else
	{
		front=q2.front();
		q2.pop();
	}
	return front;
}

int main()
{
queue<int>q1,q2;
push(1,q1,q2);
push(2,q1,q2);
push(3,q1,q2);
push(4,q1,q2);
push(5,q1,q2);
cout<<pop(q1,q2);
cout<<pop(q1,q2);
cout<<pop(q1,q2);
cout<<pop(q1,q2);
cout<<pop(q1,q2);

}

