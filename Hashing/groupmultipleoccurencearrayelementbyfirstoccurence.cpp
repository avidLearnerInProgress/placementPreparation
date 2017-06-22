#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> m;

bool mycompare(int a,int b){
    return m[a]<m[b];
}


void solve(int arr[],int n){
    
    
    for(int i=0;i<n;i++){
        if(m.find(arr[i])==m.end())
            m[arr[i]]=i;
            
    }
    sort(arr,arr+n,mycompare);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    
}

int main()
{
ios_base::sync_with_stdio(false);
  int arr[] = {10, 5, 3, 10, 10, 4, 1, 3};
int n = sizeof(arr)/sizeof(arr[0]);
solve(arr, n);

return 0;
}

