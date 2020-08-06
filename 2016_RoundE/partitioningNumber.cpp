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
    int N,D;
    
    for(int tt=1;tt<T+1;++tt){
        cin>>N>>D;
        long long result=0;
        for(int l=1;l<=N/D;l++){
            if(N%l==0 && (N/l)%D==0){result++;}

            for(int A=max(D,(N-1)/l+1-2);A<=N/l;A++){
                if(A==0 || A%D!=0){continue;}
                int remainder=N-A*l;
                if(remainder%2==0){
                    int n3=remainder/2;
                    if(n3>0 && n3<l){result++;}
                }
            }

            for(int A=max(D,(N-1)/l+1-1);A<=N/l;A++){
                if(A==0 || A%D!=0){continue;}
                int remainder=N-A*l;
                if(remainder>0 && remainder<l){result++;}
            }

            if(l>=3){
                for(int A=(N-1)/l+1-2;A<=N/l;++A){
                    if(A==0 || A%D!=0){continue;}
                    int remainder=N-A*(l-2)-(A+1+A+2);
                    int n1=max(1,l-2-remainder);
                    int n2=l-2-(remainder+1)/2;
                    if(n2>=n1){result+=n2-n1+1;}
                }
            }
            
            
        }
        cout<<"Case #"<<tt<<": "<<result<<"\n";
        
    }
}
