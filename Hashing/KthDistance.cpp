/*
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. Write a function that returns true if array contains duplicates within k distance.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll int
int main()
{
        int n,t,i,q,l,m,d,j,k;
        cin>>t;
        while(t--){
        cin>>k>>n;
        int  hash[1001];
        memset(hash,0,sizeof(hash));
        ll a[n];
        bool flag=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(hash[a[i]]!=0)
            {
                if(i-hash[a[i]]<=k)
                flag=1;
            }
            hash[a[i]]=i;
     
        }
    if(flag)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    }
}


