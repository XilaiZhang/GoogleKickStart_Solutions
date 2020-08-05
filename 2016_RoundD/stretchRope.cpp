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
long long bound=1e12;

struct comp{
    bool operator()(const pair<long long, int> & a, const pair<long long, int> & b){
        return a.first>b.first;
    }
};

int main(){
    int T;
    cin>>T;
    int N,M,L;
    int A,B,P;
    
    for(int tt=1;tt<T+1;++tt){
        cin>>N>>M>>L;
        vector<long long>dp(L+1,bound);
        dp[0]=0;
        cin>>A>>B>>P;
        for(int i=A;i<=min(L,B);++i){dp[i]=P;}
        for(int i=1;i<N;++i){
            cin>>A>>B>>P;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, comp> q;
            unordered_set<int> invalid;
            for(int j=L-A;j>=max(L-B,0);j--){
                if(dp[j]!=bound){q.push({dp[j],j});}    
            }
            while(!q.empty() && invalid.find(q.top().second)!=invalid.end()){
                q.pop();
            }
            if(!q.empty()){
                if(q.top().first+P<=M){
                    dp[L]=min(q.top().first+P,dp[L]);
                }
            }
            for(int j=L-1;j>=0;--j){
                if(j-B>=0 && dp[j-B]!=bound){
                    q.push({dp[j-B],j-B});
                }
                if(j+1-A>=0){invalid.insert(j+1-A);}
                while(!q.empty() && invalid.find(q.top().second)!=invalid.end()){q.pop();}
                if(!q.empty()){
                    if(q.top().first+P<=M){dp[j]=min(q.top().first+P,dp[j]);}
                }
            }
        }
        if(dp[L]>M){cout<<"Case #"<<tt<<": IMPOSSIBLE"<<"\n";}
        else{cout<<"Case #"<<tt<<": "<<dp[L]<<"\n";}
        
    }
}
