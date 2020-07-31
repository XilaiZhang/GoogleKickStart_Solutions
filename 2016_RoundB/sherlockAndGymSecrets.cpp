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
long long A,B,N,K;
long long mod=1e9+7;

long long compute(long long base, long long exp){
    long long ans=1;
    while(exp>0){
        if(exp & 1) {ans=ans*base%K;}
        exp=(exp>>1);
        base=base*base%K;
    }
    return ans%K;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        
        cin>>A>>B>>N>>K;
        vector<long long> v1(K+1,0); //for the i th value, (i%K)^A=v1[i]
        vector<long long> c1(K,0); //for the j th value, there are c1[j] of numbers that mod K=j
        vector<long long> v2(K+1,0);
        vector<long long> c2(K,0);

        long long r;
        for(int i=1;i<=K;++i){
            r=compute(i,A);
            v1[i]=r;
            c1[r]=(c1[r]+N/K)%mod;
            if(N%K >= i){c1[r]++;}

            r=compute(i,B);
            v2[i]=r;
            c2[r]=(c2[r]+N/K)%mod;
            if(N%K >=i){c2[r]++;}
        }

        long long result=0;
        for(int i=0;i<K;++i){
            result=(result+c1[i]*c2[(K-i)%K]%mod)%mod;

        }
        long long repeat=0;
        for(int i=1;i<=K;++i){
            if((v1[i]+v2[i])%K==0){
                repeat=(repeat+N/K)%mod;
                if(N%K>=i){repeat++;}
            }
        } 

        long long f=((result%mod-repeat%mod)+mod)%mod;   
        
        cout<<"Case #"<<tt<<": "<<f<<endl;    
        
    }
}
