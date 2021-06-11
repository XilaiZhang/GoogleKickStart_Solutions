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
vector<vector<long long>> graph;
int startBound[50002];
int endBound[50002];
long long segmentTree[400004];

int sequence = 0;
void dfs(int current, int parent){
    sequence ++;
    startBound[current] = sequence;
    for(int v: graph[current]){
        if(v!=parent){dfs(v, current);}
    }
    endBound[current] = sequence;
}

long long gcd(long long a, long long b){
    if(a==0){return b;}
    return gcd(b%a, a);
}

void update(long long val, int changeStart, int changeEnd, int nodeStart, int nodeEnd, int nodeNumber){
    if(changeStart<=nodeStart && changeEnd>=nodeEnd){
        segmentTree[nodeNumber] = gcd( segmentTree[nodeNumber], val);
        return;
    }
    int mid = nodeStart + (nodeEnd - nodeStart)/2;
    if(changeStart<=mid){
        update(val, changeStart, changeEnd, nodeStart, mid, nodeNumber*2);
    }
    if(changeEnd>mid){
        update(val, changeStart, changeEnd, mid+1, nodeEnd, nodeNumber*2+1);
    }
}

long long maxGCD = 0;
long long query(int queryEnd, int nodeStart, int nodeEnd, int nodeNumber){
    //cout<<"looking at nodeNumber "<<nodeNumber<<endl;
    maxGCD = gcd(maxGCD, segmentTree[nodeNumber]);
    if(nodeStart == nodeEnd){
        return maxGCD;
    }
    int mid = nodeStart + (nodeEnd - nodeStart)/2;
    if(queryEnd<=mid){
        return query(queryEnd, nodeStart, mid, nodeNumber*2);
    }
    if(queryEnd>mid){
         return query(queryEnd, mid+1, nodeEnd, nodeNumber*2+1);
    }
    return -1;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<=T;++tt){
        long long N,Q;
        cin>>N>>Q;
        long long X,Y,L;
        long long A;
        vector<vector<long long>> operations;
        graph = vector<vector<long long>>(N+1, vector<long long>());
        memset(segmentTree, 0, sizeof segmentTree);
        for(int i=1;i<=N-1;++i){
            cin>>X>>Y>>L>>A;
            
            operations.push_back({L,0,X,Y,A});
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }

        long long C, W;
        for(int i=0;i<Q;++i){
            cin>>C>>W;
            operations.push_back({W,1,C, i});
        }
        sort(operations.begin(), operations.end());
        sequence = 0;
        dfs(1,-1);

        // for(int i=1;i<=7;++i){
        //     cout<<"startBound "<<startBound[i]<<" "<<endBound[i]<<endl;
        // }

        vector<long long> result = vector<long long>(Q);
        for(vector<long long> op: operations){
            if(op[1]==0){
                //cout<<"doint update for "<<op[0]<<endl;
                int lowerKid = -1;
                if(startBound[op[2]]>startBound[op[3]]){
                    lowerKid = op[2];
                }else{lowerKid = op[3]; }
                update(op[4], startBound[lowerKid], endBound[lowerKid], 1, N, 1);
                // cout<<"after updating charge "<<op[4]<<", segStatus ";
                // for(int i=1;i<=16;++i){
                //     cout<<segmentTree[i]<<" ";
                // }cout<<endl;
            }else{
                //cout<<"doing query for "<<op[0]<<endl;
                maxGCD=0;
                long long r = query(startBound[op[2]], 1, N, 1);
                result[op[3]] = r;
                //cout<<"completed query for "<<op[0]<<endl;
            }
        }
        cout<<"Case #"<<tt<<":";
        for(int i=0;i<Q;++i){
            cout<<" "<<result[i];
        }
        cout<<"\n";
    }




}


