#include <bits/stdc++.h>
using namespace std;

/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    //Your code here
    
    unordered_set<int> s;
    
    int count;
    
    for(int i=0;i<=n-k;i++){   //go upto n-k only as last iteration will traverse further elements
        
        count=0;
        s.clear();
        
        for(int j=i;j<i+k;j++){  //sliding window of size 4
            
            if(s.find(A[j])==s.end()){
                
                s.insert(A[j]);
                count++;
            }
                
        }
        
        cout<<count<<" ";
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}


