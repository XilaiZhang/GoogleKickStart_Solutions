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

long long dp[26][26];


int main(){
    int T;
    cin>>T;
    int N,Q;

    for(int tt=1;tt<T+1;++tt){  

        cin>>N>>Q;
        long long result=0;
        string word;
        memset(dp, 0x3f, sizeof dp);
        for(int i=0;i<26;++i){dp[i][i]=0;}
        vector<string> line;

        for(int i=0;i<N;++i){
            cin>>word;
            line.push_back(word);
            int l=word.size();
            for(int j=0;j<l;++j){
                for(int k=j+1;k<l;++k){
                    int num1= word[j]-'A';
                    int num2= word[k]-'A';
                    //cout<<"num 1 is "<<num1<<" num2 is "<<num2<<endl;
                    if(num1!=num2){
                        dp[num1][num2]= 1;
                        dp[num2][num1]= 1;
                    }
                    
                }
            }
        }

        //bound is our number of vertices
        for(int k=0;k<26;++k){
            for(int i=0;i<26;++i){
                for(int j=0;j<26;++j){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }

        /*
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }*/

        int Xi, Yi;
        string r="Case #"+to_string(tt)+":";
        for(int i=0;i<Q;++i){
            cin>>Xi>>Yi;
            string x=line[Xi-1];
            string y=line[Yi-1];
            long long dist=1e6;
            for(int j=0;j<x.size();++j){
                for(int k=0;k<y.size();++k){
                    dist=min(dist, dp[x[j]-'A'][y[k]-'A']);
                }
            }
            if(dist==1e6){r+=" -1";}
            else{r+=" "+to_string(dist+2);}
        }

        cout<<r<<"\n";   
    }
}
