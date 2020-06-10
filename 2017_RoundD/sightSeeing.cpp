#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;
long long dp[2001][2001];
long long bound=1e9+1;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,Ts,Tf;
        cin>>N>>Ts>>Tf;
        long long Si,Fi,Di;
        cin>>Si>>Fi>>Di;
        for(int i=0;i<=2000;++i){
            for(int j=0;j<=2000;++j){
                dp[i][j]=bound;
            }
        }
        dp[1][0]=0;
        for(int i=2;i<=N;++i){
            for(int j=0;j<=i-1;++j){//j==0
                long long potential;
                if(j>0){
                    potential=dp[i-1][j-1]+Ts;
                    if(potential<=Si){dp[i][j]=min(dp[i][j],Si+Di);}
                    else{
                        dp[i][j]=min(dp[i][j], ((potential-Si-1)/Fi+1)*Fi+Si+Di );  //might become negative?
                    }
                }
                
                potential=dp[i-1][j]; //don't go sightseeing
                
                if(potential<=Si){dp[i][j]=min(dp[i][j],Si+Di);}
                else{
                    dp[i][j]=min(dp[i][j], ((potential-Si-1)/Fi+1)*Fi+Si+Di );  
                }
                
            } 
            if(i==N){break;}
            cin>>Si>>Fi>>Di;
            
        }
        int result=-1;
        for(int r=0;r<=N-1;++r){
            if(dp[N][r]<=Tf){result=r;}
        }
        if(result<0){cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl; }
        else{cout<<"Case #"<<tt<<": "<<result<<endl; }    
    }  
}
