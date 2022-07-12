
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

const ll maxn = 1e5+1;
vector<vector<ll>> graph;
vector<vector<ll>> big_graph;

ll low[maxn];
ll disc[maxn];
bool in_stack[maxn];
vector<ll> stack;
vector<ll> cluster;

ll ti, scc_num;

// https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
void scc(ll u){
    disc[u] = ti;
    low[u] = ti;
    ti ++;
    in_stack[u] = true;
    stack.push_back(u);

    for(ll v: graph[u]){
        if(disc[v] == -1){
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stack[v]){
            low[u] = min(low[u], disc[v]); 
        }
    }

    ll v = -1; 
    if(low[u] == disc[u]){
        scc_num ++;
        while(v != u){
            v = stack.back();
            stack.pop_back();
            in_stack[v] = false;
            cluster[v] = scc_num;
        }
    }
}


int main()
{
    ll t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        ll N,M,K;
	    cin>>N>>M>>K;
        for(int i=0; i<=N; ++i){
            low[i] = -1;
            disc[i] = -1;
            in_stack[i] = false;
        }
        while(!stack.empty()){stack.pop_back();}
        graph = vector<vector<ll>>(N+1, vector<ll>());
        for(int i=0; i<M; ++i){
            ll u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }

        cluster = vector<ll>(N+1, -1);
        ti = 0;
        scc_num = 0;
        for(int u=1; u<=N; ++u){
            if(disc[u] == -1){
                scc(u);
            }
        }

        vector<set<ll>> big_graph = vector<set<ll>>(scc_num+1, set<ll>()); 
        vector<ll> cluster_size = vector<ll> (scc_num + 1, 0);
        vector<ll> degree = vector<ll> (scc_num + 1, 0);
        vector<set<ll>> witness = vector<set<ll>> (scc_num + 1, set<ll>());

        for(int i=1; i<= N; ++i){
            cluster_size[ cluster[i] ] += 1;
            witness[cluster[i]].insert(i); 
            // deduplicate number of witness of the following topology
            //        /  \
            //        \  /
            for(ll j : graph[i]){
                if(cluster[j] != cluster[i]){
                    // deduplicate in coming edge degrees
                    if(big_graph[cluster[i]].find(cluster[j]) == big_graph[cluster[i]].end()){
                        degree[cluster[j]] += 1;
                    }
                    big_graph[cluster[i]].insert(cluster[j]);
                }
            }
        }

        queue<ll> q;

        for(int x=1; x <= scc_num; ++x){
            if(degree[x] == 0){
                q.push(x);
            }
        }

        while(!q.empty()){
            ll u= q.front();
            q.pop();

            for(ll v: big_graph[u]){
                degree[v] -= 1;
                for(ll reachable: witness[u]){
                    if (witness[v].size() > K){
                        break;
                    }
                    witness[v].insert(reachable);
                }

                if(degree[v] == 0){
                    q.push(v);
                }
            }
        }

        ll result = 0;
        for(int i = 1; i<= scc_num; ++i){
            if(witness[i].size() > K){
                result += cluster_size[i];
            }
        }

		printf("Case #%d: %lld\n",ca, result);
	}
	return 0;
}	