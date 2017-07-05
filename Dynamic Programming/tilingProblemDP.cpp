#include <bits/stdc++.h>

using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    long int fib[n];
	    fib[0]=1;
	    fib[1]=2;
	    for(int i=2;i<n;i++)
	    fib[i]=fib[i-1]+fib[i-2];
	    cout<<fib[n-1]<<endl;

	}
}
