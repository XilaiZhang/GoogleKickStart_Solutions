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
#include <list>

using namespace std;
int small[40][40][40][40];
long long dp[40][40][40][40];

long long helper(int i,int j, int s, int t){
    if(dp[i][j][s][t]!=0){
        return dp[i][j][s][t];
    }
    if(i==s && j==t){
        return 0;
    }
    long long maxCoins=0; 
    for(int h=i;h<s;++h){
        maxCoins=max(maxCoins, small[i][j][s][t]+helper(i,j,h,t)+helper(h+1,j,s,t));
    }
    for(int v=j;v<t;++v){
        maxCoins=max(maxCoins, small[i][j][s][t]+helper(i,j,s,v)+helper(i,v+1,s,t));
    }
    dp[i][j][s][t]=maxCoins;
    return maxCoins;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,M;
        cin>>N>>M;
        int grid[N][M];
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
               cin>>grid[i][j]; 
            }
        }
        memset(small,0,sizeof small);
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){

                int line[M-j];
                for(int k=0;k<M-j;++k){
                    line[k]=100001;
                }
                for(int s=i;s<N;++s){
                    
                    int minVal=grid[s][j];
                    for(int t=j;t<M;++t){
                        minVal=min(minVal,grid[s][t]);
                        line[t-j]=min(line[t-j],minVal);
                        
                        small[i][j][s][t]=line[t-j];
                    }
                }
            }
        }
        memset(dp,0,sizeof dp);
        long long result=helper(0,0,N-1,M-1);

        cout<<"Case #"<<tt<<": "<<result<<endl;     
    }  
}
