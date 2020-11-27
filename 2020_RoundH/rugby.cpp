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
    int N;
    long long Xi, Yi;

    for(int tt=1;tt<T+1;++tt){  

        cin>>N;
        long long result=0;
        vector<long long>Y;
        vector<long long>X;

        for(int i=0;i<N;++i){
            cin>>Xi>>Yi;
            Y.push_back(Yi);
            X.push_back(Xi);
        }
        sort(Y.begin(),Y.end());
        long long Ym= (Y[(N-1)/2]+Y[N/2])/2;

        sort(X.begin(),X.end());
        vector<long long> computeX;
        for(int i=0;i<N;++i){
            computeX.push_back(X[i]-i);
        }
        sort(computeX.begin(),computeX.end());
        long long Xm= (computeX[(N-1)/2]+computeX[N/2])/2;
        //cout<<"Xm is "<<Xm<<" Ym is "<<Ym<<endl;
        for(int i=0;i<N;++i){
            result+=abs(X[i]-(Xm+i))+abs(Y[i]-Ym);
        }

        cout<<"Case #"<<tt<<": "<<result<<"\n";   
    }
}
