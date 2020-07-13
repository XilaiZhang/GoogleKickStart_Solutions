#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>

using namespace std;
int N,A,B;
vector<vector<int>> children;
vector<int> visited;
vector<int> timesA;
vector<int> timesB;

void init(){
    vector<vector<int>>v1(N+1);
    children=v1;
    vector<int> v2;
    visited=v2;
    vector<int> v3(N+1,0);
    timesA=v3;
    timesB=v3;
}


void dfs(int p){
    visited.push_back(p);
    for(int x:children[p]){
        dfs(x);
    }
    visited.pop_back();

    timesA[p]++;
    timesB[p]++;
    int m=visited.size();
    if(m-A>=0){
        timesA[visited[m-A]]+=timesA[p];
    }
    if(m-B>=0){
        timesB[visited[m-B]]+=timesB[p];
    }
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>A>>B;
        init();

        int p;
        for(int i=2;i<=N;++i){
            cin>>p;
            children[p].push_back(i);
        }

        dfs(1);
        //cout<<"timesA "<<endl;for(int x:timesA){cout<<" "<<x;}cout<<endl;
        //cout<<"timesB "<<endl;for(int x:timesB){cout<<" "<<x;}cout<<endl;

        double result=0;
        for(int i=1;i<=N;++i){
                double pa=(double)timesA[i]/N;
                double pb=(double)timesB[i]/N;
                result+=pa+pb-pa*pb;
        }

        cout.precision(8);
        cout<<"Case #"<<tt<<": "<<fixed<<result<<endl;

    }
}
