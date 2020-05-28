#include <iostream>

using namespace std;
const long long mod=1e9+7;

long long p(long long i, int K){
    long long answer=1;
    for(int j=K;j>0;j>>=1){
        if(j &1){
            answer=answer*i%mod; 
        }
        i=i*i%mod;
    }
    return answer;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        long long N,K,C,D,E1,E2,F;
        long long X1,Y1;
        cin>>N>>K>>X1>>Y1>>C>>D>>E1>>E2>>F;
        long long A[N+1];
        A[1]=(X1+Y1)%F;
        for(int i=2;i<N+1;++i){
            long long newX=(C*X1+D*Y1+E1)%F;
            long long newY=(D*X1+C*Y1+E2)%F;
            A[i]=(newX+newY)%F;
            X1=newX;
            Y1=newY;
        }
        long long base=K;
        long long result=A[1]%mod*K%mod*N%mod;
        for(long long i=2;i<N+1;++i){
            base=(base+i*(p(i,K)-1)%mod*p((i-1),mod-2)%mod)%mod;
            result=(result+(A[i]%mod*base%mod*(N-i+1))%mod)%mod;
        }
        result%=mod;
        cout<<"Case #"<<tt<<": "<<result<<endl;
    } 
}

