#include<bits/stdc++.h>
using namespace std;

#define no_max_station 4

int carAssembly(int a[][no_max_station], int t[][no_max_station],int *e,int *x){
    
    int line1[no_max_station],line2[no_max_station];
    
    line1[0]=e[0]+a[0][0];
    line2[0]=e[1]+a[1][0];
    
    for(int i=1;i<no_max_station;i++){
        line1[i]=min(line1[i-1]+a[0][i],line2[i-1]+a[0][i]+t[1][i]);
        line2[i]=min(line2[i-1]+a[1][i],line1[i-1]+a[1][i]+t[0][i]);
    }
    return min(line1[no_max_station-1]+x[0],line2[no_max_station-1]+x[1]);
}

int main(){
    int a[][no_max_station]={{4, 5, 3, 2},{2, 10, 1, 4}};
    int t[][no_max_station]={{0, 7, 4, 5},{0, 9, 2, 8}};
    int e[] = {10, 12}; 
    int x[] = {18, 7};
    cout<<carAssembly(a,t,e,x)<<endl;
}
