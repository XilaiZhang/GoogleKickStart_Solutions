
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

string dir_op[4];
ll dir_kd[4];
int offsets[4][2] = {{-1, 0}, {0,1}, {0,-1}, {1,0}};
ll customers[11][11];
ll customer_id[11][11];
ll dp[11][11][21][(1<<10)];

ll compute(ll coins, int direction){
    if(coins == (long long)INT_MIN){
        return INT_MIN;
    }
    string op = dir_op[direction];
    int Kd = dir_kd[direction];
    if(op == "+"){
        return coins + Kd;
    }
    else if(op == "-"){
        return coins - Kd;
    }else if(op == "*"){
        return coins * Kd;
    }else if(op == "/"){
        if(coins == INT_MIN){
            return coins;
        }
        return floor(coins/(double)Kd);
    }
    else{
        cout<<"invalid operand"<<endl;
    }
}



int main()
{
    int t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        ll N,P,M,Ar,Ac;
        string op;
        ll Kd;
        ll Xk, Yk, Ck;
	    cin>>N>>P>>M>>Ar>>Ac;
        Ar -- ;
        Ac -- ;
        for(int i=0; i<4; ++i){
            cin>>dir_op[i]>>dir_kd[i];
        }
        memset(customers, 0, sizeof(customers));
        for(int i=0; i<P; ++i){
            cin>>Xk>>Yk>>Ck;
            customers[Xk-1][Yk-1] = Ck;
            customer_id[Xk-1][Yk-1] = i;
        }
        
        for(int step=0; step <= M; ++step){
            for(int i = 0; i<N ; ++i){
                for(int j = 0; j<N ; ++j){
                    for(int subset = 0; subset < (1<<10) ; ++subset){
                        dp[i][j][step][subset] = INT_MIN;
                    }}}}
        dp[Ar][Ac][0][0] = 0;

        int all_set = (1<<P) - 1;
        for(int step=1; step <= M; ++step){
            for(int i = 0; i<N ; ++i){
                for(int j = 0; j<N ; ++j){
                    for(int subset = 0; subset < (1<<P) ; ++subset){
                        // stay at same place and do nothing
                        dp[i][j][step][subset] = dp[i][j][step-1][subset];

                        // stay at same place, but delivers a pizza 
                        if(customers[i][j] != 0){
                            Ck = customers[i][j];
                            int mask = (1<<(customer_id[i][j]));
                            if((mask & subset)!=0){
                                int prev_state = (subset ^ mask);
                                if (dp[i][j][step-1][prev_state] != INT_MIN){
                                    dp[i][j][step][subset] = max(dp[i][j][step][subset], dp[i][j][step-1][prev_state] + Ck);
                                }  
                            }
                        }
                        // come from a neighboring place
                        for(int direction=0; direction < 4; ++ direction){
                            int offset_i = offsets[direction][0];
                            int offset_j = offsets[direction][1];
                            int old_i = i - offset_i;
                            int old_j = j - offset_j;
                            if(old_i >=0 && old_i<N && old_j >=0 && old_j<N){
                                //come from a different place, but do not deliver a pizza
                                dp[i][j][step][subset] = max(dp[i][j][step][subset], compute(dp[old_i][old_j][step-1][subset], direction));
                                if(customers[i][j] != 0){
                                    Ck = customers[i][j];
                                    int mask = (1<<(customer_id[i][j]));
                                    if((mask & subset)!=0){
                                        int prev_state = (subset ^ mask);
                                        // come from a different place, and delivers a pizza
                                        if (dp[old_i][old_j][step-1][prev_state] != (long long)INT_MIN){
                                            dp[i][j][step][subset] = max(dp[i][j][step][subset], compute(dp[old_i][old_j][step-1][prev_state], direction) + Ck);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        ll result = INT_MIN;
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                result = max(result, dp[i][j][M][all_set]);
            }
        }

        if(result == INT_MIN){
            printf("Case #%d: IMPOSSIBLE\n",ca);
            continue;
        }
		printf("Case #%d: %lld\n",ca, result);
	}
	return 0;
}	