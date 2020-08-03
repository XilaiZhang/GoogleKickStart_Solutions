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
int N;
int A,D;
int maxA,maxD;

bool compute(){
    cin>>N;
    unordered_map<int,pair<int,int>> lookup;
    for(int i=0;i<N;++i){
        cin>>A>>D;
        lookup[i]=make_pair(A,D);
    }
    while(!lookup.empty()){
        maxA=0;
        maxD=0;
        for(auto x:lookup){
            maxA=max(maxA,x.second.first);
            maxD=max(maxD,x.second.second);
        }
        vector<int> bad;
        for(auto x:lookup){
            if(x.second.first==maxA && x.second.second==maxD){
                return true;
            }
            if(x.second.first==maxA){bad.push_back(x.first);}
            if(x.second.second==maxD){bad.push_back(x.first);}
        }
        for(int y:bad){lookup.erase(y);}
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    
    for(int tt=1;tt<T+1;++tt){
        if(compute()){cout<<"Case #"<<tt<<": YES"<<endl; }
        else{cout<<"Case #"<<tt<<": NO"<<endl; }
        
    }
}
