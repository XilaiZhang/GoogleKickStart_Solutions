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
    long long N,M;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>M;
        vector<long long> fact(N+1);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=N;++i){fact[i]=fact[i-1]*i%M;}

        vector<long long>prime(N+1);
        prime[0]=0;
        prime[1]=1;
        for(int i=2;i<=N;++i){
            prime[i]=fact[i];
            for(int j=1;j<i;++j){
                prime[i]=(prime[i]-prime[j]*fact[i-j]%M+M)%M;
            }
        }
        
        vector<long long> dpSum(N+1,0);
        dpSum[0]=0;
        dpSum[1]=1;
        for(int i=2;i<=N;++i){
            for(int j=0;j<i;++j){
                dpSum[i]=(dpSum[i]+(dpSum[j]+fact[j])%M*prime[i-j] %M ) %M;
            }
        }

        vector<long long> dpSquare(N+1,0);
        dpSquare[0]=0;
        dpSquare[1]=1;
        for(int i=2;i<=N;++i){
            for(int j=0;j<i;++j){
                dpSquare[i]=(dpSquare[i]+(dpSquare[j]+2*dpSum[j]%M+fact[j])%M*prime[i-j]%M ) %M;
            }
        }

        cout<<"Case #"<<tt<<": "<<dpSquare[N]%M<<endl; //in case M==1   
        
    }
}
