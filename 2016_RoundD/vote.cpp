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

int main(){
    int T;
    cin>>T;
    int N,M;
    
    for(int tt=1;tt<T+1;++tt){
        cin>>N>>M;
        vector<vector<double>> dp(N+M+1,vector<double>(N+1,0));
        dp[1][1]=(double)(N)/(N+M);
        for(int i=2;i<=N+M;++i){
            for(int j=i/2+1;j<=min(i,N);++j){ //j-1 issue
                dp[i][j]=dp[i-1][j-1]*(N-j+1)/(N+M-i+1);
                if(j!=i){dp[i][j]+=dp[i-1][j]*(M-i+1+j)/(N+M-i+1);}
            }
        }
       
        cout.precision(8);
        cout<<"Case #"<<tt<<": "<<fixed<<dp[N+M][N]<<endl;
    }
}
