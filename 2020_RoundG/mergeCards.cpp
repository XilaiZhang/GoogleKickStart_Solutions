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

vector<vector<double>>dp;
long long N;

int main(){
    int T;
    cin>>T;
    double Ai;
    vector<double>empty;
    dp.push_back(empty);

    for(int i=1;i<=5000;++i){
        vector<double>v1(i);
        dp.push_back(v1);    
    }

    dp[1][0]=0;
    for(int i=2;i<=5000;++i){
        // . . . .
        // .<-. . B .
        //the combine step happens before B, contribution from previous round
        for(int j=1;j<=i-1;++j){
            dp[i][j] += dp[i-1][j-1]*(j)/(i-1);
        }

        // . . . . .
        // . . . B .<-.
        //the combine step happens after B, contribution from previous round
        for(int j=0;j<=i-2;++j){
            dp[i][j] += dp[i-1][j]*(i-j-1)/(i-1);
        }

        //contribution in current round
        for(int j=1;j<=i-2;++j){
            dp[i][j]+= ((double)2/(i-1));
        }

        dp[i][0]+= (double)1/(i-1);
        dp[i][i-1]+= (double)1/(i-1);
    }

    for(int tt=1;tt<T+1;++tt){  

        cin>>N;
        double result=0;
        for(int i=0;i<N;++i){
            cin>>Ai;
            result+= dp[N][i]*Ai;
        }

        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<result<<"\n";   
    }
}
