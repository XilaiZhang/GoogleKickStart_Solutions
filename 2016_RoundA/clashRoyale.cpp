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

bool cust(const pair<long long, long long> &a, const pair <long long, long long> &b){
    if(a.first==b.first){return a.second>b.second;}
    else{return a.first<b.first;}
}

bool standard(const pair<long long, long long> &a, const pair <long long, long long> &b){
    return a.first<b.first;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        long long M,N;
        cin>>M>>N;
        //cost, attack, N
        long long result=0;

        vector<vector<pair<long long, long long>>> left(N/2+1);
        vector<vector<pair<long long, long long>>> right(N/2+2);
        left[0].push_back({0,0});
        right[0].push_back({0,0});
        long long level, currentLevel;
        
        for(int i=1;i<=N/2;++i){
            cin>>level>>currentLevel;
            vector<long long> attack(level+1);
            for(int j=1;j<=level;++j){cin>>attack[j];}
            vector<long long> upgrade(level+1);
            for(int j=1;j<level;++j){cin>>upgrade[j];}
            long long currentCost=0;
            vector<pair<long long,long long>> myVals;
            for(int f=currentLevel;f<=level;++f){
                myVals.push_back({currentCost, attack[f]});
                currentCost+=upgrade[f];
            }
            
            vector<vector<pair<long long, long long>>> newCandidates(i+1);
            pair<long long, long long> p;
            for(auto x: myVals){
                for(int j=0;j<i;++j){
                    for(auto y: left[j]){
                        if(y.first+x.first>M){break;}
                            p=make_pair(x.first+y.first, x.second+y.second);
                            newCandidates[j+1].push_back(p);
                    }
                }
            }
            for(int j=0;j<=i;++j){
                for(auto x:newCandidates[j]){left[j].push_back(x);}
            }
            for(int j=0;j<=i;++j){
                sort(left[j].begin(),left[j].end(),cust);
                vector<pair<long long,long long>> np;
                np.push_back(left[j][0]);
                for(long long p2=1;p2<left[j].size();++p2){
                    if(left[j][p2].second<=np.back().second){continue;}
                    np.push_back(left[j][p2]);
                }
                left[j]=np;
            }
        }

        for(int i=N/2+1;i<=N;++i){
            cin>>level>>currentLevel;
            vector<long long> attack(level+1);
            for(int j=1;j<=level;++j){cin>>attack[j];}
            vector<long long> upgrade(level+1);
            for(int j=1;j<level;++j){cin>>upgrade[j];}
            long long currentCost=0;
            vector<pair<long long,long long>> myVals;
            for(int f=currentLevel;f<=level;++f){
                myVals.push_back({currentCost,attack[f]});
                currentCost+=upgrade[f];
            }

            vector<vector<pair<long long, long long>>> newCandidates(i-N/2+1);
            pair<long long, long long> p;
            for(auto x: myVals){
                for(int j=0;j<i-N/2;++j){
                    for(auto y: right[j]){
                        if(y.first+x.first>M){break;}
                            p=make_pair(x.first+y.first, x.second+y.second);
                            newCandidates[j+1].push_back(p);
                    }
                }
            }
            for(int j=0;j<=i-N/2;++j){
                for(auto x:newCandidates[j]){right[j].push_back(x);}
            }

            for(int j=0;j<=i-N/2;++j){
                sort(right[j].begin(),right[j].end(),cust);
                vector<pair<long long,long long>> np;
                np.push_back(right[j][0]);
                for(long long p2=1;p2<right[j].size();++p2){
                    if(right[j][p2].second<=np.back().second){continue;}
                    np.push_back(right[j][p2]);
                }
                right[j]=np;
            }
        }
                
        for(int i=0;i<=N/2;++i){
            int j=8-i;
            if(j>=right.size() || right[j].empty()){continue;}

            for(auto x: left[i]){
                auto p1=upper_bound(right[j].begin(),right[j].end(),make_pair(M-(x.first),-1),standard);
                long long r;
                if(p1==right[j].begin()){continue;}
                if(p1==right[j].end()){r=right[j].back().second;}
                else{p1--;r=(*p1).second;}
                
                result=max(result,x.second+r);
            }
        }
        
        cout<<"Case #"<<tt<<": "<<result<<endl;
        
    }
}
