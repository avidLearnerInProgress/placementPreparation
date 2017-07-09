#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int w,int val[],int wt[])
{
    int k[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            k[i][j]=0;
            else if(wt[i-1]<=j)
            k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            else
            k[i][j]=k[i-1][j];
        }
        
    }
    return k[n][w];
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int w;
        cin>>w;
        int wt[n],val[n];
        for(int i=0;i<n;i++)
        cin>>val[i];
        for(int i=0;i<n;i++)
        cin>>wt[i];
        int m=knapsack(n,w,val,wt);
        cout<<m<<"\n";
    }
}
