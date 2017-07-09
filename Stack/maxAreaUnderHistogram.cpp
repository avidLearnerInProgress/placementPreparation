#include<bits/stdc++.h>
using namespace std;

int maxArea(int a[],int n){
    
    stack<int> s;
    int max_area=0;
    int area_with_top;
    int top;
    
    int i=0;
    while(i<n){
        
       
        
        if(s.empty() || a[s.top()]<=a[i])
            s.push(i++);
        else{
            top=s.top();
            s.pop();
            area_with_top=a[top]*(s.empty() ? i: i-s.top() -1);
            
            if(max_area<area_with_top)
                max_area=area_with_top;
                
        }
    }
    
    
    while(!s.empty()){
            top=s.top();
            s.pop();
            area_with_top=a[top]*(s.empty() ? i: i-s.top() -1);
            
            if(max_area<area_with_top)
                max_area=area_with_top;
                
    }
    return max_area;
}



int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int n;cin>>n;
            int arr[n];
            for(int i=0;i<n;i++)cin>>arr[i];
            
            int res=maxArea(arr,n);
            cout<<res<<endl;
        }
	return 0;
}
