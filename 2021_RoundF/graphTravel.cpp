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
#include <sstream>

using namespace std;

vector<unordered_set<int>> graph;
int N;
long long result;
long long M,K;
long long L[17];
long long R[17];
long long A[17];
long long ways[1<<15];
long long score[1<<15];

void computeWays(long long state){

    unordered_set<int> neighbors;
    for(int i=0;i<N;++i){
        if((state & (1<<i))!=0){
            for ( int v: graph[i]){
                if((state & (1<<v))==0){
                    neighbors.insert(v);
                }
            }
        }
    }

    for(int neighbor:neighbors){
        if(L[neighbor]<= score[state] && R[neighbor] >= score[state]){
            ways[ (state | 1<<neighbor)] += ways[state];
        }
    }
    if(score[state] == K){
        result+= ways[state];
    }
}

void computeScore(){
    memset(score, 0, sizeof score);
    for(int i=0; i<(1<<N); ++i){
        for(int j=0; j<N; ++j){
            if((i & (1<<j)) != 0){
                score[i] = score[ (i ^ (1<<j))] + A[j];
                break;
            }
        }
    }
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<=T;++tt){
        cin>>N>>M>>K;
        memset(ways, 0, sizeof ways);
        result = 0;
        for(int i=0;i<N;++i){
            cin>>L[i];
            cin>>R[i];
            cin>>A[i];
        }
        computeScore();
        vector<unordered_set<int>> empty(N);
        graph = empty;
        int a, b;
        for(int j=0;j<M;++j){
            cin>>a;
            cin>>b;
            graph[a].insert(b);
            graph[b].insert(a);
        }

        for(int j=0;j<N;++j){
            ways[(1<<j)] = 1;
        }
        for(int p=0;p<(1<<N);++p){
            computeWays(p);
        }

        cout<<"Case #"<<tt<<": ";
        cout<<result;
        cout<<"\n";
    }




}


