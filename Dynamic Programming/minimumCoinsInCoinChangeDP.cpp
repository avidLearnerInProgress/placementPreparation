#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int table[sum+1];
     
        table[0] = 0;
     
        for (int i=1; i<=sum; i++)
            table[i] = INT_MAX;
     
        for (int i=1; i<=sum; i++)
        {
            for (int j=0; j<n; j++)
              if (a[j] <= i)
              {
                  int sub_res = table[i-a[j]];
                  if (sub_res != INT_MAX && sub_res + 1 < table[i])
                      table[i] = sub_res + 1;
              }
        }
        if(table[sum]==INT_MAX)
        cout<<"-1";
        else
       cout<< table[sum];
    cout<<'\n';
    }
    	return 0;
}
