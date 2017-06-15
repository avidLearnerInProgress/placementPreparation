//Solved on : http://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);



bool vis[1000][1000];
vector<string> v;


void backtrack(int i,int j,string path,int n,int m[MAX][MAX]){
    
    
    vis[i][j]=1;
    
    if(i==n-1 && j==n-1)
        v.push_back(path);
    
    
    if(i>0 && m[i-1][j] && !vis[i-1][j])
        backtrack(i-1,j,path+'U',n,m);
    
    if(i<n-1 && m[i+1][j] && !vis[i+1][j])
        backtrack(i+1,j,path+'D',n,m);
        
    if(j>0 && m[i][j-1] && !vis[i][j-1])
        backtrack(i,j-1,path+'L',n,m);
        
    if(j<n-1 && m[i][j+1] && !vis[i][j+1])   
        backtrack(i,j+1,path+'R',n,m);
        
    vis[i][j]=0;
}


vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here	
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            vis[i][j]=0;
    
    
    string e="";
    v.clear();
    backtrack(0,0,e,n,m);
    sort(v.begin(),v.end());
    return v;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}



/* Testcase:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
*/

