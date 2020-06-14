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
long long P[10001];
int numbers[10001];

int main(){
    int T;
    cin>>T;
    long long mod=1e9+7;
    P[0]=1;
    for(int i=1;i<=10000;++i){
        P[i]=P[i-1]*2%mod;
    }
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;
        for(int j=1;j<=N;++j){
            cin>>numbers[j];
        }
        long long result=0;
        for(int j=1;j<=N;++j){
            for(int k=j+1;k<=N;++k){
                result=(result+(numbers[k]-numbers[j])*P[k-j-1])%mod;
            }
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;   
    }  
}
