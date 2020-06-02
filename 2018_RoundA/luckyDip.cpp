#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <list>

using namespace std;
const int bound=2e4+2;

double sums[bound];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,K;
        cin>>N>>K;
        memset(sums,0,sizeof sums);
        vector<double> V(N);
        for(int i=0;i<N;++i){
            cin>>V[i];
        }
        sort(V.begin(),V.end());
        double currentSum=0;
        for(int i=N-1;i>=0;i--){
            currentSum+=V[i];
            sums[i]=currentSum;
        }
        double base=sums[0]/N;
        for(int i=1;i<=K;++i){
            int pos=lower_bound(V.begin(),V.end(),base)-V.begin(); //can't be end 
            base=(base*(pos)+sums[pos])/N;
        }
        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<base<<endl;     
    }  
}
