#include<bits/stdc++.h>
using namespace std;

struct QItem{
	string word;
	int len;
};


bool isAdjacent(string &a,string &b){
	
	int n=a.length();
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])count++;
		if(count>1)break;
	}
	return (count==1)?true:false;
}

int shortestChainLength(string &start,string &target,set<string> &D){
	
	queue<QItem> q;
	QItem item={start,1};
	q.push(item);
	
	while(!q.empty()){
		
		QItem current=q.front();
		q.pop();
		
		for(auto it=D.begin();it!=D.end();it++){
			
			string temp=*it;
			if(isAdjacent(temp,current.word)){
				item.word=temp;
				item.len=current.len+1;
				
				q.push(item);
				
				D.erase(temp);
				
				if(temp==target)return item.len;
				
			}
		}
	}
}


int main(){
	set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");
    string start = "toon";
    string target = "plea";
    cout << "Length of shortest chain is: "
         << shortestChainLength(start, target, D); 
    return 0; 
	
}
