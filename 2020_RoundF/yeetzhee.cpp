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
int N,M,K;

struct dummy{
    vector<int> dict;

    dummy(const vector<int> &word){
        dict=word;
    }

    bool operator==(const dummy & d) const{
        return dict==d.dict;
    }
};

namespace std{
    template<>
    struct hash<dummy>{

        size_t operator()(const dummy & d) const{
            auto ic=hash<int>();
            size_t uniqueKey=0;
            for(int number:d.dict){
                uniqueKey=(uniqueKey<<1) ^ (ic(number));
            }
            return uniqueKey;
        }
    };
}

unordered_map<dummy, double> dp;

double helper(dummy state, dummy target, int steps){
    if(dp.find(state)!=dp.end()){return dp[state];}
    if(steps==0){return (double)0;}
    int prefixState=0;
    int prefixTarget=0;
    int retry=0;
    double expWithoutReroll=0;
    for(int i=0;i<N;++i){
        prefixState+=state.dict[i];
        prefixTarget+=target.dict[i];
        if(state.dict[i]==0){continue;} //nothing is here
        if(prefixState==prefixTarget){retry+=state.dict[i];continue;} //each of these needs to be re-rolled
        //a guaranteed solution if we keep rolling, considering the interval before i
        dummy newState=state;
        newState.dict[i]-=1;
        newState.dict[i+1]++;
        double kid=helper(newState,target,steps-1)+1;
        expWithoutReroll+=kid*(state.dict[i])/M;//probability is getting the state[i] types from all M types in this roll
    }
    double retryP=((double)retry)/M;
    //the equation: expWithoutReroll+retryP*(x+1)=x, where x is the overall exp steps, including roll and re-roll
    double x=(expWithoutReroll+retryP)/(1-retryP);
    dp[state]=x;
    return x;
}

int main(){
    int T;
    cin>>T;
    
    for(int tt=1;tt<T+1;++tt){  
        cin>>N>>M>>K;
        vector<int> target(N+1,0);
        vector<int> init(N+1,0);
        init[0]=M;
        int q;
        for(int i=0;i<K;++i){
            cin>>q;
            target[q]++;
        }
        target[0]=M-K; //we have M types; target is a mapping from group_size to number of types
        unordered_map<dummy,double> newMap;
        dp=newMap;
        double result=helper(dummy(init),dummy(target),N);
        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<result<<"\n";    
    }
}

