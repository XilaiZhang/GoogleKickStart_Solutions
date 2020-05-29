#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <list>

using namespace std;

long long dp[101][(1<<16)];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,K;
        long long P;
        cin>>N>>K>>P;
        vector<vector<int>>query(N+1);
        vector<vector<int>> expectSum(N+1);
        for(int i=0;i<K;++i){
            int A,B,C;
            cin>>A>>B>>C;
            query[B].push_back(A);
            expectSum[B].push_back(C);
        }

        memset(dp,0,sizeof dp);

        for(int state=0;state<(1<<min(N,16));++state){
            
            bool flag=true;
            for(int q=0;q<query[N].size();++q){
                int shift=N-query[N][q]+1;
                int ones=__builtin_popcount(state)-__builtin_popcount(state>>shift);
                if(ones!=expectSum[N][q]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                dp[N][state]++;
            }
        }

        for(int i=N-1;i>=1;--i){
            for(int state=0;state<(1<<min(i,16));state++){
                
                int postState=(state & (~(1<<15)))<<1;
                if(dp[i+1][postState]==0 && dp[i+1][postState+1]==0){continue;}

                bool flag=true;
                for(int q=0;q<query[i].size();++q){
                    int shift=i-query[i][q]+1;
                    int ones=__builtin_popcount(state)-__builtin_popcount(state>>shift);
                    if(ones!=expectSum[i][q]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    dp[i][state]+=dp[i+1][postState]+dp[i+1][postState+1];
                    dp[i][state]=min(dp[i][state],(long long)1e18);
                }
 
            }

        }

        string result="";
        int prefix=0;

        for(int i=1;i<=N;++i){
            for (int digit=0;digit<=1;++digit){
                int newVal=((prefix<<1) | digit);
                newVal= (newVal & (~(1<<16)));
                if(dp[i][newVal]>=P){
                    if(i>=17){
                        if(prefix & (1<<15)) {result+="1";}
                        else{result+="0";}
                    }
                    if(i==N){
                        for(int w=min(N-1,15);w>=0;--w){
                            if(newVal & (1<<w)){result+="1";}
                            else{result+="0";}
                        }
                    }
                    prefix=newVal;
                    break;
                }else{
                    P=P-dp[i][newVal];
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;
      
    }  
}
