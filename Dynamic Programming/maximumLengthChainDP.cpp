/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool comp(const val &v1, const val &v2)
{
    //if(v1.second>v2.second)
        return v1.second<v2.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val arr[],int n)
{
//Your code here

    int dp[n];
    
    
    int i,j;
    int max=0;
    
    sort(arr,arr+n,comp);
    
    for(int i=0;i<n;i++)dp[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].first>arr[j].second && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }
    /*for(int i=0;i<n;i++)cout<<dp[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<n;i++)if(max<dp[i])max=dp[i];
    //cout<<max<<endl;
   // free(dp);
    return max;
    
}
