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
int dp[301][301][301]; //to 301 later

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        string s;
        cin>>s;
        int N=s.size();
        for(int i=0;i<=300;++i){
            for(int j=0;j<=300;++j){
                for(int k=0;k<=300;++k){
                    dp[i][j][k]=3000;
                }
            }
        }
        unordered_set <string> seen;

        //initialization
        dp[1][0][0]=1;
        dp[1][1][1]=2;
        for(int i=1;i<N;++i){
            for(int start=0;start<=i-1;start++){
                seen.insert(s.substr(start,i-start));
            }
            vector<string>candidates;
            for(int l=1;l<=N-i;++l){
                string potential=s.substr(i,l);
                if(seen.find(potential)!=seen.end()){
                    candidates.push_back(potential);
                }else{break;}
            }
            
            for(int t=0;t<candidates.size();++t){
                dp[i+t+1][i+1][i+t+1]=min(dp[i][0][0]+2,dp[i+t+1][i+1][i+t+1]);
            }
            dp[i+1][0][0]=dp[i][0][0]+1;
            for(int j=0;j<=i-1;++j){
                for(int k=j;k<=i-1;++k){ //return the result
                    string state=s.substr(j,k-j+1);
                    for(int t=0;t<candidates.size();++t){
                        if(state==candidates[t]){
                            dp[i+candidates[t].size()][j+1][k+1]=min(dp[i][j+1][k+1]+1,dp[i+candidates[t].size()][j+1][k+1]); //check indices
                        }
                        else{
                            dp[i+candidates[t].size()][i+1][i+1+t]=min(dp[i][j+1][k+1]+2,dp[i+candidates[t].size()][i+1][i+1+t]);
                        }
                        
                    }
                    dp[i+1][j+1][k+1]=min(dp[i][j+1][k+1]+1,dp[i+1][j+1][k+1]);
                }
            }
        }
        int result=dp[N][0][0];
        for(int j=1;j<=N;++j){
            for(int k=1;k<=N;++k){
                result=min(result,dp[N][j][k]);
            }
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;     
    }  
}
