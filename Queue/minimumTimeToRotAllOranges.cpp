#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)


struct ele{
    int x,y;
};

int R,C;

bool isValid(int i,int j){
    return (i>=0 && j>=0 && i<R && j<C);
}

bool isDelimiter(ele t){
    return t.x==-1 && t.y==-1;
}

bool findAll(int mat[101][101]){
    F(0,R,i){
        F(0,C,j){
            if(mat[i][j]==1)
            return true;
        }
    }
    return false;
}


int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            cin>>R>>C;
            int mat[101][101];
            F(0,R,i){
                F(0,C,j){
                    cin>>mat[i][j];
                }
            }
            queue<ele> q;
            int ans=0;
        
            ele temp;
            F(0,R,i)
                F(0,C,j)
                    if(mat[i][j]==2){
                        temp.x=i;
                        temp.y=j;
                        q.push(temp);
                    }
            
            temp.x=-1;
            temp.y=-1;
            q.push(temp);
            
            while(!q.empty()){
                bool flag=false;
                
                while(!isDelimiter(q.front())){
                    temp=q.front();
                    //right adj
                    if(isValid(temp.x+1,temp.y) && mat[temp.x+1][temp.y]==1){
                        if(!flag){ans++;flag=true;}
                        mat[temp.x+1][temp.y]=2;
                        temp.x++;
                        q.push(temp);
                        temp.x--;
                    }
                    //left adj
                    if(isValid(temp.x-1,temp.y) && mat[temp.x-1][temp.y]==1){
                        if(!flag){ans++;flag=true;}
                        mat[temp.x-1][temp.y]=2;
                        temp.x--;
                        q.push(temp);
                        temp.x++;
                    }
                    //top adj
                    if(isValid(temp.x,temp.y+1) && mat[temp.x][temp.y+1]==1){
                        if(!flag){ans++;flag=true;}
                        mat[temp.x][temp.y+1]=2;
                        temp.y++;
                        q.push(temp);
                        temp.y--;
                    }
                    //bottom adj
                    if(isValid(temp.x,temp.y-1) && mat[temp.x][temp.y-1]==1){
                        if(!flag){ans++;flag=true;}
                        mat[temp.x][temp.y-1]=2;
                        temp.y--;
                        q.push(temp);
                    }
                    q.pop();
                }
                q.pop();
                if(!q.empty()){
                    ele p;
                    p.x=-1;
                    p.y=-1;
                    q.push(p);
                }
                
            }
                        
            if(findAll(mat))cout<<-1<<endl;
            else cout<<ans<<endl;
        }
	return 0;
}
