#include<bits/stdc++.h>
using namespace std;
bool chk(vector<int>a,vector<int>b)
{
    if(a.size()!=b.size())
    return false;
    
    reverse(a.begin(),a.end());
    
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}
int main()
 {
	//code
        int t;
        cin>>t;
        while(t--)
        {  
            int vertices,edges,notmirror=0,a,b,c,d;
            
           
            cin>>vertices>>edges;
            
             vector<int> adj1[vertices+1],adj2[vertices+1];
             
             
            for(int i=1;i<=edges;i++)
            {
                cin>>a>>b;
                adj1[a].push_back(b);
            }
            for(int i=1;i<=edges;i++)
            {
                cin>>a>>b;
                adj2[a].push_back(b);
            }
            for(int i=1;i<=edges;i++)
            {
                vector<int> tr1=adj1[i];
                vector<int> tr2=adj2[i];
                if(!chk(tr1,tr2))
                {
                    notmirror=1;
                    break;
                }
            }
            cout<<!notmirror<<endl;
        }
	return 0;
}
