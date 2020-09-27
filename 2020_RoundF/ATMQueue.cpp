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
//vector<vector<int>>graph(301);

int main(){
    int T;
    cin>>T;
    int N,X;
    int q;
    for(int tt=1;tt<T+1;++tt){  
        cin>>N>>X;
        vector<pair<int,int>>numbers(N);
        for(int i=0;i<N;++i){cin>>q;numbers[i]=make_pair((q-1)/X+1,i+1);}
        sort(numbers.begin(),numbers.end());
        string result="";
        for(int i=0;i<N;++i){result+=" "+to_string(numbers[i].second);}

       
        
        cout<<"Case #"<<tt<<":"<<result<<"\n";    
    }
}

