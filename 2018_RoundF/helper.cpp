#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        long long L,N,K;
        cin>>L>>N>>K;
        long long result=0;
        vector<vector<string>> dict(N+1);
        vector<string>final;
        if(N>0){
           for(int off=0;off<L;++off){
                string k(1,char('a'+off));
                dict[1].push_back(k);
                final.push_back(k);
            }
        }
        
        if(N>1){
            for(int off=0;off<L;++off){
                string k(1,char('a'+off));
                k+=k;
                dict[2].push_back(k);
                final.push_back(k);
            }
        }
        
        for(long long i=3;i<N+1;++i){
            for(string x:dict[i-2]){
                for(string y:dict[2]){
                    string z=y[0]+x+y[1];
                    dict[i].push_back(z);
                    final.push_back(z);
                }
            }
        }
        sort(final.begin(),final.end());
        //for(string s:final){cout<<s<<" ";}cout<<endl;
        if(K<=final.size()){
            cout<<final[K-1]<<endl;
            result=final[K-1].size();}
        
        cout<<"Case #"<<tt<<": "<<result<<endl;;
    }
}
