#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

int dp[MAX][MAX][3];

int func(int health,int armour,int last){

    if(health<=0||armour<=0)
        return 0;

    if(dp[health][armour][last]!=-1)
        return dp[health][armour][last];

    if(last==0)
        dp[health][armour][last]= 1+max(func(health-5,armour-10,1),func(health-20,armour+5,2));
    else if(last==1)
        dp[health][armour][last] = 1+max(func(health+3,armour+2,0),func(health-20,armour+5,2));
    else
        dp[health][armour][last]= 1+max(func(health+3,armour+2,0),func(health-5,armour-10,1));

    return dp[health][armour][last];


}

int main(){

    int w;
    cin>>w;
    while(w--){

        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                for(int k=0;k<3;k++)
                    dp[i][j][k]=-1;
            }
        }

        int health,armour;
        cin>>health>>armour;

        int ans = max(max(func(health+3,armour+2,0),func(health-5,armour-10,1)),(func(health-20,armour+5,2)));

        cout<<ans<<endl;
    }


}

