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
string a,b;
int M,N;
int dp[2001][2001];

int helper(int x,int y){  // 1 for good, 2 for bad
    if(dp[x][y]!=0){return dp[x][y];}
    if(x>M || y>N){return 2;}
    if(x==M && y==N){dp[x][y]=1;return 1;}
    if(x==M){
        int k=y;
        while(k<N){
            if(b[k]!='*'){dp[x][y]=2; return 2;}
            k++;
        }
        dp[x][y]=1;return 1;
    }
    if(y==N){
        int k=x;
        while(k<M){
            if(a[k]!='*'){dp[x][y]=2; return 2;}
            k++;
        }
        dp[x][y]=1;return 1;
    }
    if(a[x]!='*' && b[y]!='*'){
        if(a[x]==b[y]){
            if(helper(x+1,y+1)==1){dp[x][y]=1;return 1;}
        }
        dp[x][y]=2;return 2;
    }
    if(a[x]=='*'){
        int count=0;
        int k=0;
        while(y+k<=N && count<=4){
            if(helper(x+1,y+k)==1){dp[x][y]=1;return 1;} //could have RE?
            if(y+k>=N){break;}
            if(b[y+k]!='*'){count++;}
            k++;
        }
    }
    if(b[y]=='*'){
        int count=0;
        int k=0;
        while(x+k<=M && count<=4){
            if(helper(x+k,y+1)==1){dp[x][y]=1;return 1;} //could have RE?
            if(x+k>=M){break;}
            if(a[x+k]!='*'){count++;}
            k++;
        }
    }
    dp[x][y]=2;return 2; //rethink later
}

int main(){
    int T;
    cin>>T;
    
    for(int tt=1;tt<T+1;++tt){
        cin>>a>>b;
        M=a.size();
        N=b.size();
        memset(dp,0,sizeof dp);
        if(helper(0,0)==1){
            /*for(int i=0;i<=8;i++){
                for(int j=0;j<=6;++j){cout<<dp[i][j]<<" ";}cout<<endl;
            }*/
            cout<<"Case #"<<tt<<": TRUE"<<"\n";}
        else{cout<<"Case #"<<tt<<": FALSE"<<"\n";}        
        
    }
}
