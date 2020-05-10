#include <iostream>

using namespace std;
const int mod=1e9+7;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        long long N,M;
        cin>>N>>M;
        long long p[M+1];
        p[0]=1;
        for (int i=1;i<M+1;i++){
            p[i]=p[i-1]*2%mod;
        }
        long long mPart[M+1];
        mPart[0]=1;
        long long base=M;
        for(int k=1;k<M+1;++k){
            mPart[k]=mPart[k-1]*base%mod;
            //cout<<"mPart "<<k<<" is "<<mPart[k]<<endl;
            base--;
        }
        long long interval=1;
        for(int j=M+1;j<=2*N-M;j++){
            interval=interval*j%mod;
        }
        long long nPart[M+1];
        nPart[M]=interval;
        //cout<<"interval is "<<interval<<endl;
        long long it=M;
        long long right=2*N-M+1;
        for(int k=M-1;k>=0;k--){
            nPart[k]=nPart[k+1]*it%mod*right%mod;
            //cout<<"nPart "<<k<<" is "<<nPart[k]<<endl;
            it--;
            right++;
        }
        long long result=0;
        for(int k=0;k<=M;k++){
            if(k&1){
                result=(result-mPart[k]*nPart[k]%mod*p[k]%mod)%mod;
            }
            else{
                result=(result+mPart[k]*nPart[k]%mod*p[k]%mod)%mod;
            }
            //cout<<"result is "<<result<<"at round "<<k<<endl;
        }
        if(result<0){
            result+=mod;
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;
    }
}
