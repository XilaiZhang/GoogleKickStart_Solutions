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

int constant = (int)(1e9+7);
int ten6 = (int)(1e6);
long long ten6inv;
int maxN = (int)(200001);
int bound;
int N, Q;
int parent[200001][18];
int level[200001];


int findBound (int maxN){
    int power = 0;
    while(maxN>0){
        maxN = (maxN >> 1);
        power ++;
    }
    return power;
}

long long inverse(int number){
    int power = constant - 2;
    long long multiplier = number;
    long long res = 1;
    while(power){
        if (power & 1){
            res = (res * multiplier) % constant;
        }   
        multiplier = (multiplier * multiplier) % constant;
        power /= 2;
    }
    return res;
}

struct prob {

    long long ancestorHappenMeHappen;
    long long ancestorNotHappenMeHappen;
    long long ancestorHappenMeNotHappen;
    long long ancestorNotHappenMeNotHappen;

    prob(){}
    prob(long long pi){
        ancestorHappenMeHappen = pi * ten6inv % constant;
        ancestorHappenMeNotHappen = ( ten6 - pi ) * ten6inv % constant; 
        // to store happen or not happen for the first node
    }
    prob(long long ai, long long bi){
        ancestorHappenMeHappen = ai * ten6inv % constant;
        ancestorNotHappenMeHappen = bi * ten6inv % constant;
        ancestorHappenMeNotHappen = ( ten6 - ai ) * ten6inv % constant;
        ancestorNotHappenMeNotHappen = ( ten6 - bi ) * ten6inv % constant;
    }
};

prob probParent[200001][18];

prob concat(prob & a, prob & b){
    prob res = prob();
    res.ancestorHappenMeHappen = (a.ancestorHappenMeHappen * b.ancestorHappenMeHappen % constant+
        a.ancestorNotHappenMeHappen * b.ancestorHappenMeNotHappen % constant) % constant;
    res.ancestorHappenMeNotHappen = (a.ancestorHappenMeNotHappen * b.ancestorHappenMeHappen % constant+ 
        a.ancestorNotHappenMeNotHappen * b.ancestorHappenMeNotHappen % constant) % constant;
    res.ancestorNotHappenMeHappen = (a.ancestorHappenMeHappen * b.ancestorNotHappenMeHappen % constant+
        a.ancestorNotHappenMeHappen * b.ancestorNotHappenMeNotHappen % constant) % constant;
    res.ancestorNotHappenMeNotHappen = (a.ancestorHappenMeNotHappen * b.ancestorNotHappenMeHappen % constant +
        a.ancestorNotHappenMeNotHappen * b.ancestorNotHappenMeNotHappen % constant) % constant;
    return res;
}

// https://www.geeksforgeeks.org/lca-in-a-tree-using-binary-lifting-technique/
int lca(int u, int v, int level[], int parent[][18])
{
    if (level[u] < level[v])
        swap(u, v);
 
    for (int i = bound - 1; i >= 0; i--)
        if ((level[u] - pow(2, i)) >= level[v])
            u = parent[u][i];

    if (u == v)
        return u;
 
    for (int i = bound - 1; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

prob concatUntil(int u, int v, prob probParent[][18], int level[], int parent[][18]){
    prob res = prob();
    res.ancestorHappenMeHappen = 1;
    res.ancestorNotHappenMeNotHappen = 1;
    res.ancestorHappenMeNotHappen = 0;
    res.ancestorNotHappenMeHappen = 0;

    for(int i = bound -1; i>=0; --i){
        if(level[u] - pow(2, i) >= level[v]){
            res = concat(res, probParent[u][i]);
            u = parent[u][i];
        }
    }

    return res;
}


int main(){
    int T;
    cin>>T;
    ten6inv = inverse(ten6);
    bound = findBound(maxN);

    for(int tt=1;tt<=T;++tt){
        cin>>N>>Q;
        long long pi;
        cin>>pi;
        prob probOne = prob(pi);

        parent[1][0] = 1;
        level[1] = 0;

        long long ai, bi;
        for(int i=2; i<=N; ++i){
            cin>>parent[i][0]>>ai>>bi;
            probParent[i][0] = prob(ai, bi);
        }

        for(int i=2;i<=N;++i){
            for(int j=1;j<bound; ++j){
                parent[i][j] = parent[ parent[i][j-1] ][j-1];
                probParent[i][j] = concat(probParent[i][j-1],  probParent[ parent[i][j-1] ][j-1]); 
            }
        }

        for(int i=2; i<=N; ++i){
            level[i] = level[parent[i][0]] + 1;
        }


        cout<<"Case #"<<tt<<":";
        int u, v;
        for(int i=0;i<Q; ++i){
            cin>>u>>v;
            int commonAncestor = lca(u, v, level, parent);
            prob probAncestor = concatUntil(commonAncestor, 1, probParent, level, parent);
            long long ancestorHappen = (probAncestor.ancestorHappenMeHappen * probOne.ancestorHappenMeHappen % constant+
                probAncestor.ancestorNotHappenMeHappen * probOne.ancestorHappenMeNotHappen % constant) % constant;
            long long ancestorNotHappen = (probAncestor.ancestorHappenMeNotHappen * probOne.ancestorHappenMeHappen  % constant+
                probAncestor.ancestorNotHappenMeNotHappen * probOne.ancestorHappenMeNotHappen  % constant) % constant;
            prob probUGivenAncestor = concatUntil(u, commonAncestor, probParent, level, parent);
            prob probVGivenAncestor = concatUntil(v, commonAncestor, probParent, level, parent);
            long long ans = (ancestorHappen * probUGivenAncestor.ancestorHappenMeHappen % constant 
                            * probVGivenAncestor.ancestorHappenMeHappen % constant +
                            ancestorNotHappen * probUGivenAncestor.ancestorNotHappenMeHappen % constant
                             * probVGivenAncestor.ancestorNotHappenMeHappen) % constant;
            cout<<" "<<ans;
        }

        cout<<"\n";
    }




}


