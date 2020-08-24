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
int N,M,S,R;
int U,V;
int C,type;
int K,target;

struct node{
    int city;
    int stone;
    long long distance;

    node(int c, int s, long long d){
        city=c;
        stone=s;
        distance=d;
    }
};

struct compareNode{
    bool operator()(const node& a, const node &b){return a.distance>b.distance;}
};
vector<vector<int>>graph(301);
long long dist[301][301];
vector<vector<vector<int>>> recipe(301);
priority_queue<node,vector<node>,compareNode> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){  
        cin>>N>>M>>S>>R;
        for(int i=0;i<=N;++i){graph[i].clear();}
        for(int i=0;i<M;++i){
            cin>>U>>V;
            graph[U].push_back(V);
            graph[V].push_back(U);
        }
        for(int i=0;i<=N;++i){
            for(int j=0;j<=S;++j){dist[i][j]=-1;}
        }
        q=priority_queue<node,vector<node>,compareNode>();
        
        for(int i=1;i<=N;++i){
            cin>>C;
            for(int j=0;j<C;++j){cin>>type; dist[i][type]=0; q.push(node(i,type, 0));}
        }
        
        for(int i=0;i<=300;++i){recipe[i].clear();}
        for(int i=0;i<R;++i){
            cin>>K;
            unordered_set<int> buddies;
            vector<int> raw={0};
            for(int j=0;j<K;++j){cin>>type;buddies.insert(type);raw.push_back(type);}
            cin>>target;
            raw[0]=target;
            for(int my:buddies){
                recipe[my].push_back(raw);
            }
        }
        
        while(!q.empty()){
            node n=q.top();
            q.pop();
            if(dist[n.city][n.stone]>=0 && n.distance>dist[n.city][n.stone]){continue;}
            //could be updating an entry multiple times
            //check for bigger than bound? 1e12. break here
            if(n.distance>bound){break;}
            for(int v:graph[n.city]){
                if(dist[v][n.stone]<0 || n.distance+1<dist[v][n.stone]){
                    dist[v][n.stone]=n.distance+1;
                    q.push(node(v,n.stone, n.distance+1));
                }
            }
            for(auto formula:recipe[n.stone]){
                int t=formula[0];
                bool flag=true;
                long long currentSum=0; //include (potentially multiple) n.stone
                for(int j=1;j<formula.size();++j){
                    if(dist[n.city][formula[j]]==-1){flag=false; break;} 
                    currentSum+=dist[n.city][formula[j]];
                }
                if(!flag){continue;}
                if(dist[n.city][t]==-1 || currentSum<dist[n.city][t]){
                    dist[n.city][t]=currentSum;
                    q.push(node(n.city, t, currentSum));
                }
            }
        }
        long long result=bound;
        for(int i=1;i<=N;++i){
            if(dist[i][1]!=-1){result=min(result,dist[i][1]);}
        }
        if(result>=bound){result=-1;}
        cout<<"Case #"<<tt<<": "<<result<<"\n";    
    }
}
