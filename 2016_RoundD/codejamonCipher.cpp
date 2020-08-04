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
long long mod=1e9+7;

struct node{
    vector<int> dict;
    node(const vector<int> & some){
        dict=some;
    }

    bool operator==(const node & d) const{
        return dict==d.dict;
    }
};

namespace std{
    template<>
    struct hash<node>{
        size_t operator()(const node & d) const{
            auto ic=hash<int>();
            size_t uniqueKey=0;
            for(int x:d.dict){
                uniqueKey=(uniqueKey<<1) ^ (ic(x));
            }
            return uniqueKey;
        }
    };
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T;
    cin>>T;
    int V,S;
    string word;
    
    for(int tt=1;tt<T+1;++tt){
        cin>>V>>S;
        unordered_map<node,int> vocab;
        for(int i=0;i<V;++i){
            cin>>word;
            vector<int> a(26,0);
            for(char c:word){a[c-'a']++;}
            vocab[node(a)]++;
        }
        cout<<"Case #"<<tt<<":";
        int l;
        for(int j=0;j<S;++j){
            cin>>word;
            l=word.size();
            vector<long long>dp(l+1,0);
            dp[0]=1;
            for(int i=0;i<l;++i){
                vector<int> v1(26,0);
                for(int w=1;w<=min(20,l-i);++w){
                    v1[word[i+w-1]-'a']++;
                    node v2(v1);
                    if(vocab.find(v2)!=vocab.end()){dp[i+w]=(dp[i+w]+dp[i]*vocab[v2]%mod)%mod;}
                }
            }
            cout<<" "<<dp[l];
        }
        cout<<"\n";
    }
}
