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
#include <sstream>

using namespace std;

int N, M;

long long computeNearest(map<long long, long long>& intervals, long long S){
    map<long long, long long>::iterator it = intervals.upper_bound(S);
    long long res;
    long long x = it->first;
    long long y = it->second;
    if(it == intervals.begin()){
        res = x;
        intervals.erase(it);
        if( x < y ){
            intervals[x+1] = y;
        }
        return res;
    }


    map<long long, long long>::iterator prev = it;
    prev --;
    long long l = prev->first;
    long long r = prev->second;
    if(it == intervals.end() && S > r){
        res = r;
        intervals.erase(prev);
        if(r > l){
            intervals[l] = r-1;
        }
        return res;
    }
    if(S >= l && S <= r){
        res = S;
        intervals.erase(prev);
        if( l < S){
            intervals[l] = S-1;
        }
        if(r > S){
            intervals[S+1] = r;
        }
        return res;
    }
    else if (r < S){
        if(S-r <= x-S){
            res = r;
            intervals.erase(prev);
            if(r > l){
                intervals[l] = r-1;
            }
            return res;
        }else{
            res = x;
            intervals.erase(it);
            if(y > x){
                intervals[x+1] = y;
            }
            return res;
        }
    }
    return res;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<=T;++tt){
        cin>>N>>M;
        long long A, B, S;
        map<long long, long long> intervals;
        for(int i=0;i<N;++i){
            cin>>A>>B;
            intervals[A] = B;
        }
        cout<<"Case #"<<tt<<":";
        for(int i=0;i<M; ++i){
            cin>>S;
            long long ans = computeNearest(intervals, S);
            cout<<" "<<ans;
        }

        cout<<"\n";
    }




}


