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

int main(){
    int T;
    cin>>T;
    long long N,L1,R1,A,B,C1,C2,M,X2,Y2;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>L1>>R1>>A>>B>>C1>>C2>>M;
        long long X1=L1;
        long long Y1=R1;
        map<int,vector<int>>events;
        events[L1].push_back(1);
        events[R1+1].push_back(-1);
        for(int i=2;i<=N;++i){
            long long X2=(A*X1+B*Y1+C1)%M;
            long long Y2=(A*Y1+B*X1+C2)%M;
            L1=min(X2,Y2);
            R1=max(X2,Y2);
            events[L1].push_back(i);
            events[R1+1].push_back(-i);
            X1=X2;
            Y1=Y2;
        }

        int count=0;
        int prev=-1;
        unordered_set<int> ids;
        long long total=0;
        vector<long long> coveredArea(N+1,0);
        
        for(auto x:events){
            if(prev>=0 && count>0){total+=x.first-prev;}
            if(count==1){coveredArea[*ids.begin()]+=x.first-prev;}

            for(int y:x.second){
                if(y<0){count--;ids.erase(-y);}
                else{count++;ids.insert(y);}
            }
            
            prev=x.first;
        }

        long long maxReduce=0;
        for(long long ans:coveredArea){
            maxReduce=max(maxReduce,ans);
        }
        long long result=total-maxReduce;
        cout<<"Case #"<<tt<<": "<<result<<endl;    
        
    }
}
