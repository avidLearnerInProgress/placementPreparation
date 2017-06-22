
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n)
{
//Your code here
    unordered_map<int,int> mp;
    int sum=arr[0]?1:-1;
    mp[sum]=0;
    int ans=0;
    for(int i=1;i<n;i++){
        if(arr[i]==1)sum++;
        else sum--;
        
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
        else{
            if(ans<(i-mp[sum]))ans=i-mp[sum];
        }
        if(sum==0)
        ans=i+1;
    }
    
   return ans;
    
}


int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<maxLen(a,n)<<endl;
		
	}
	return 0;
}
