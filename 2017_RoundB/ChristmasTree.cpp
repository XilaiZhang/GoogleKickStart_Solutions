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
int h[100][100];
int dp[101][100][101];

int main(){
    int T;
    cin>>T;
    int N,M,K;
    string line;
    vector<int> lookup={0};
    int currentSum=0;
    for(int i=0;i<100;++i){
        currentSum+=2*i+1;
        lookup.push_back(currentSum);
    }

    
    for(int tt=1;tt<T+1;++tt){  
        cin>>N>>M>>K;
        memset(h,0,sizeof h);
        memset(dp,0,sizeof dp);
        vector<string> grid;
        for(int i=0;i<N;++i){
            cin>>line;
            grid.push_back(line);
        }

        int r=0;
        for(int i=N-1;i>=0;--i){
            for(int j=0;j<M;++j){
                if(grid[i][j]=='.'){h[i][j]=0;}
                else{
                    int nextH=101;
                    if(i<N-1){
                        if(j==0 || j==M-1){nextH=0;}
                        else{
                           for(int t=j-1;t<=j+1;++t){
                                nextH=min(nextH,h[i+1][t]);
                            } 
                        }
                    }
                    else{nextH=0;}
                    h[i][j]=nextH+1;
                    dp[i][j][1]=lookup[h[i][j]];
                    if(K==1){r=max(r,dp[i][j][1]);}
                }
            }
        }
        if(K==1){cout<<"Case #"<<tt<<": "<<r<<"\n";continue;}

        int result=0;
        for(int k=2;k<=K;++k){
            int ans=0;
            for(int i=N-1;i>=0;--i){
                for(int j=0;j<M;++j){
                    if(h[i][j]==0){continue;}
                    for(int l=1;l<=h[i][j];++l){
                        for(int t=max(0,j-l+1);t<=min(M-1,j+l-1);++t){
                            if(dp[i+l][t][k-1]!=0){dp[i][j][k]=max(dp[i][j][k],lookup[l]+dp[i+l][t][k-1]); } 
                        }
                    }
                    ans=max(ans,dp[i][j][k]);
                }
            }
            if(ans==0){break;}
            if(k==K){result=ans;}
        }

        cout<<"Case #"<<tt<<": "<<result<<"\n";    
    }
}
