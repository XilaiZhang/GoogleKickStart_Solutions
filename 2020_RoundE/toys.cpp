#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>

using namespace std;
int N;
int E[100001];
int R[100001];

struct cust{
    bool operator()(const pair<int,int> & a, const pair<int,int> & b){
        return a.first<b.first;
    }
};

int main(){
    int T;
    cin>>T;

    

    for(int tt=1;tt<T+1;++tt){  
        cin>>N;
        long long currentSum=0;
        for(int i=0;i<N;++i){
            cin>>E[i]>>R[i];
            currentSum+=E[i];
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, cust> RE;
        
        long long maxTime=currentSum;
        long long currentTime=currentSum;
        int removed=0;

        for(int i=0;i<N;++i){
            RE.push({E[i]+R[i],E[i]});
            currentTime+=E[i];
            while(!RE.empty() && RE.top().first>currentSum){
                currentTime-=2*RE.top().second;
                currentSum-=RE.top().second;
                RE.pop();
            }
            if(currentTime>maxTime){
                maxTime=currentTime;
                removed=i+1-RE.size();
            }
            else if(currentTime==maxTime){
                removed=min(removed,(int)(i+1-RE.size()));
            }
        }
        if(!RE.empty()){
            cout<<"Case #"<<tt<<": "<<N-RE.size()<<" INDEFINITELY"<<"\n";
        }
        else{
            cout<<"Case #"<<tt<<": "<<removed<<" "<<maxTime<<"\n"; 
        }
           
    }
}
