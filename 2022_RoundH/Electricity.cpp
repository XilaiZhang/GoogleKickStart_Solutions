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

typedef long long ll;
long long N, E;
long long A[200005];
long long seen[200005];
long long dp[200005];

long long dfs(int u,vector<vector<int>> & graph ){
    if(seen[u] != 0 ){
        return dp[u];
    }
    seen[u] = 1;
    long long me = 0;
    for(int neighbor: graph[u]){
        if(A[neighbor] < A[u]){
            me += dfs(neighbor, graph);
        }
    }
    me += 1;
    dp[u] = me;
    return me;
}

int main()
{
    int t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>A[i];
        }
        vector<vector<int>> graph(N, vector<int>());
        memset(seen, 0, sizeof seen);
        int X, Y;
        for(int i=0;i<N-1;++i){
            cin>>X>>Y;
            X--;
            Y--;
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }

        for(int i=0; i<N;++i){
            dfs(i, graph);
        }
       
        long long result = 0;
        for(int i= 0; i<N;++i){
            result = max(result, dp[i]);
        }

		printf("Case #%d: %lld\n",ca, result);
	}
	return 0;
}	