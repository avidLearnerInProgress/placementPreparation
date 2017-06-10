#include<bits/stdc++.h>
using namespace std;

int findset(int parent[],int i){
	
	if(parent[i]!=i)return findset(parent,parent[i]);
	
	return i;
}

void unionset(int parent[],int x,int y){
	
	int xp=findset(parent,x);
	int yp=findset(parent,y);
	parent[yp]=xp;
	
}

int main(){
	
	vector<pair<int,int>> edges;
	int parent[100005];
	int v;cin>>v;
	int x,y;
	int e;
	cin>>e;
	for(int i=0;i<v;i++){
		parent[i]=i;
	}
	for(int i=0;i<e;i++){
		cin>>x>>y;
		edges.push_back(make_pair(x,y));
	}
	int flag=0;
	for(int i=0;i<edges.size();i++){
		int x=findset(parent,edges[i].first);
		int y=findset(parent,edges[i].second);
		
		if(x==y){
			flag=1;
			break;
		}
		unionset(parent,x,y);
	}
	
	if(flag==1)cout<<"Contains cycle."<<endl;
	else cout<<"Doesnt Contain cycle.";

}



/*
Test case:

7 7
1 2
2 3
3 7
7 6
6 5
5 4
1 4

*/
