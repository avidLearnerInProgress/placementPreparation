#include<bits/stdc++.h>
using namespace std;

/*You are required to complete this function*/
int maxLen(int A[],int n)
{
  //Your code here
  map<int,int> mp;
  
  int sum=0;
  int max_len=0;
  
  for(int i=0;i<n;i++){
      
      sum+=A[i];
      
      if(A[i]==0 && max_len==0)max_len=1;
      if(sum==0)max_len=i+1;
      
      
      if(mp.find(sum)!=mp.end()){
          max_len=max(max_len,i-mp[sum]);
      }
      
      else mp[sum]=i;
  }
  
  return max_len;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}



