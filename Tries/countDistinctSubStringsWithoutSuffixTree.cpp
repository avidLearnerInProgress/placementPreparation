#include<bits/stdc++.h>
using namespace std;
/*You are required to complete this method */
int match(string a,string b){
    int len1=a.length();
    int len2=b.length();
    int len=len2;
    if(len1<len2)
        len=len1;
    int s=0,i;
    for(i=0;i<len;i++){
        if(a[i]==b[i]){
            s++;
        }else
            break;
    }
    return s;
}

int countDistinctSubstring(string mystring)
{    vector<string>vec;
    int i;
    int len=mystring.length();
    for(i=0;i<len;i++){
        string s=mystring.substr(i);
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    int sum=vec[0].length();
    for(i=1;i<vec.size();i++){
        sum+=vec[i].length()-match(vec[i],vec[i-1]);
    }
    return sum+1;
}

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


