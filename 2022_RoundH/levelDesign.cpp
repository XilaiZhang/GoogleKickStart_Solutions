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
int graph[100005];
int seen[100005];
int cycle_size_to_count[100005];
int inf = 100005;

int dfs(int i){
    int cycle_size = 0;
    while(seen[i] == 0){
        seen[i] = 1;
        cycle_size ++;
        i = graph[i];
    }
    return cycle_size;
}

int main()
{
    int t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        cin>>N;
        int num;
        for(int i=0; i<N; ++i){
            cin >> num;
            graph[i] = num - 1;
        }
        memset(seen, 0 , sizeof seen);
        memset(cycle_size_to_count, 0 , sizeof cycle_size_to_count);
        for(int i=0; i<N; ++i){
            if(seen[i] == 0){
                int cycle_size = dfs(i);
                cycle_size_to_count[cycle_size] ++;
            }
        }
        vector<int> cycle_sizes;
        for(int i=0; i<= 100000; ++i){
            if(cycle_size_to_count[i] != 0){
                cycle_sizes.push_back(i);
            }
        }

        int unique_sizes = cycle_sizes.size();
        vector<vector<int>> dp  = vector<vector<int>> ( unique_sizes+1, vector<int>(N+1, inf));
        dp[0][0] = 0;
        for(int i = 1; i <= unique_sizes; ++i){
            int cycle_size = cycle_sizes[i-1];
            int total_count = cycle_size_to_count[cycle_size];
            dp[i][0] = 0;
            // the different modulo with respect to cycle size
            for(int modulo=0; modulo < cycle_size; ++ modulo){
                deque<int> min_index_prev_row;
                for ( int j = modulo; j <= N; j+= cycle_size){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);

                    int min_val = inf;
                    // compute minimum from front of deque
                    if(!min_index_prev_row.empty()){
                        min_val = dp[i-1][min_index_prev_row.front()] + int((j - min_index_prev_row.front()) / cycle_size);
                    }
                    dp[i][j] = min(dp[i][j], min_val);

                    // update deque
                    // remove obsolete index
                    while(!min_index_prev_row.empty() && min_index_prev_row.front() <= j - cycle_size * total_count){
                        min_index_prev_row.pop_front();
                    }

                    // pop from back any index that leads to a bigger result
                    while(!min_index_prev_row.empty()){
                        // the extra number of cycles needed if we choose a smaller total size j
                        int compensation = int((j - min_index_prev_row.back()) / cycle_size);
                        if (dp[i-1][j] > dp[i-1][min_index_prev_row.back()] + compensation){
                            break;
                        }
                        min_index_prev_row.pop_back();
                    }
                    min_index_prev_row.push_back(j);
                }
            }
        }

        vector<int> result(N + 1);
        int best_right = inf;
        for(int K = N; K > 0; --K) {
            result[K] = min(dp[unique_sizes][K], best_right + 1);
            best_right = min(best_right, result[K]);
        }

        string output_string = "";
        for(int K = 1; K <= N; ++K) {
            output_string +=  " " + to_string(result[K] - 1) ;
        }
        printf("Case #%d: %s\n",ca, output_string.c_str());
		// printf("Case #%d: %lld\n",ca, (ll)result);
	}
	return 0;
}	