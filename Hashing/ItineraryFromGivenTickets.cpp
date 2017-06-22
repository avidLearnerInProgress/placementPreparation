#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)

int main()
 {
	//code
    map<string,string> mp;
    map<string,string> rmp;
    
    mp["Chennai"]="Banglore";
    mp["Bombay"]="Delhi";
    mp["Goa"]="Chennai";
    mp["Delhi"]="Goa";
    
    map<string,string>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        rmp[it->second]=it->first;
        
    }
    string start;
      for(it=mp.begin();it!=mp.end();it++){
          if(rmp.find(it->first)==mp.end());
          start=it->first;break;
      }
    
    if(start.empty())cout<<"Error"<<endl;
    it=mp.find(start);
    while (it != mp.end())
    {
        cout << it->first << "->" << it->second << endl;
        it = mp.find(it->second);
    }
    
    
	return 0;
}
