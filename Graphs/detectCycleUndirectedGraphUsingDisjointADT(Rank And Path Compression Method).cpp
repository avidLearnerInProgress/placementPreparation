#include<bits/stdc++.h>
using namespace std;


struct disjointset{
	int rank;
	int parent;
};

int findset(disjointset s[],int i){
	
	if(s[i].parent!=i)return findset(s,s[i].parent);
	
	return s[i].parent;
}

void unionset(disjointset s[],int x,int y){
	
	if(s[x].rank<s[y].rank)
		s[x].parent=s[y].parent;
	else if(s[x].rank>s[y].rank)
		s[y].parent=s[x].parent;
	
	else{
		s[y].parent=s[x].parent;
		s[x].rank++;
	}
	
}

int main(){
	
	vector<pair<int,int>> edges;
	int parent[100005];
	int v;cin>>v;
	int x,y;
	int e;
	cin>>e;
	disjointset s[v+1];
	
	for(int i=0;i<v;i++){
		s[i].parent=i;
		s[i].rank=0;
	}
	for(int i=0;i<e;i++){
		cin>>x>>y;
		edges.push_back(make_pair(x,y));
	}
	int flag=0;
	for(int i=0;i<edges.size();i++){
		int x=findset(s,edges[i].first);
		int y=findset(s,edges[i].second);
		
		if(x==y){
			flag=1;
			break;
		}
		unionset(s,x,y);
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
