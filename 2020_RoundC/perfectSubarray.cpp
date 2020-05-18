#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;
int seen[20000001];
const int base=10000000;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;
        long long result=0;
        memset(seen,0,sizeof seen);
        seen[base]=1;
        long long currentSum=base;
        for(int i=0;i<N;++i){
            int A;
            cin>>A;
            currentSum+=A;
            for(int s=0;;++s){
                int st=s*s;
                if(currentSum-st<0){break;}
                result+=seen[currentSum-st];
            }
            seen[currentSum]++;
        }
        
       
        cout<<"Case #"<<tt<<": "<<result<<endl;;
    }
}
