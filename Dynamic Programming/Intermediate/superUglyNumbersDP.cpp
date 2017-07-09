
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int k=9;
    vector<int> primes = {3, 5, 7, 11, 13};
    int n = primes.size();

    vector<int> ugly;
    vector<int> nextUgly(n,0);

    ugly.push_back(1);
    k--;

    while(k--){
        int min_ugly = INT_MAX;

        for(int i=0;i<nextUgly.size();i++){
            int temp = ugly[nextUgly[i]]*primes[i];
            if(temp<min_ugly) min_ugly = temp;
        }
        ugly.push_back(min_ugly);

        for(int i=0;i<nextUgly.size();i++){
            int temp = ugly[nextUgly[i]]*primes[i];
            if(temp == min_ugly) nextUgly[i]++;
        }
    }
    cout<<ugly.back()<<endl;
    return 0;
}

