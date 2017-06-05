#include<iostream>
#include<queue>
using namespace std;
 
int minCost(int arr[], int n)
{
	//BY DEFAULT 'LESS' IS USED WHICH IS FOR DECREASING ORDER 
	//AND 'GREATER' IS USED FOR INCREASING ORDER
	priority_queue< int, vector<int>, greater<int> > pq1(arr,arr+n);
	int res = 0;
	while(pq1.size() > 1)
	{
		int first = pq1.top();
		pq1.pop();
		int second = pq1.top();
		pq1.pop();
		res+=first + second;
		pq1.push(first + second);
	}
	return res;	
}
 
int main()
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len)/sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size);
    return 0;
}
