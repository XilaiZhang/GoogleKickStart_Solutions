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

using namespace std;

int main(){
    int dp[10001];
    for(int i=0;i<=10000;++i){dp[i]=10002;}
    dp[0]=0;
    for(int i=1;i<=10000;++i){
        double y=sqrt(i);
        if ((y-floor(y))==0){
            dp[i]=1;
            continue;
        }
        for(int j=1;j<=100;++j){
            if(j*j>i){
                break;
            }
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;

        cout<<"Case #"<<tt<<": "<<dp[N]<<endl;     
    }  
}
