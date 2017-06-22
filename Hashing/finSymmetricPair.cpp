#include<bits/stdc++.h>
using namespace std;

void findSymPairs(int a[][2],int m)
{
    int flag=0;
    map<int,pair<int,int>> mp;
    for(int i=0;i<m;i++)
      {
          
          /*
                step 1: a[2][0] i.e. 5 not found in map, hence a[2][1] is set. i.e. key 1 is set with (2,1)
                step 2: for: a[4][0] we have [1->(2,1)] and hence it is found in map.
                step 3: pp contains (2,1) now we check a[2][0]==a[4][1] which is equal i.e. 5
                thus we found symmetric pair ..
                a,b = c,d iff a==d && b==c
                
                
          */
          
          if(mp.find(a[i][0])!= mp.end())         
           {
             pair<int,int>pp = mp[a[i][0]];
             if(a[pp.first][0] == a[i][1])
              {
                mp.erase(a[i][1]);  
                cout<<"("<<a[i][0]<<", "<<a[i][1]<<")"<<endl;
                flag=1;
              }
           }
           else
           mp[a[i][1]]=make_pair(i,1);
      }
      if(!flag)
      cout<<"No Pairs Found";
}


int main()
{
        int m=5;
        int arr[m][2];
        arr[0][0] = 11; arr[0][1] = 20;
        arr[1][0] = 30; arr[1][1] = 40;
        arr[2][0] = 5;  arr[2][1] = 1;
        arr[3][0] = 40;  arr[3][1] = 30;
        arr[4][0] = 1;  arr[4][1] = 5;
        findSymPairs(arr,m);
}
