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

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int x[4];
        int y[4];
        int z[4];
        int Xmin=8000;
        int Xmax=-8000;
        for(int i=1;i<=3;++i){
            cin>>x[i];
            Xmin=min(Xmin,x[i]);
            Xmax=max(Xmax,x[i]);
            cin>>y[i];
            cin>>z[i];
        }
        double result=(double)(Xmax-Xmin)/6;
        
        cout.precision(10);
        cout<<"Case #"<<tt<<": "<<fixed<<result<<endl;     
    }  
}
