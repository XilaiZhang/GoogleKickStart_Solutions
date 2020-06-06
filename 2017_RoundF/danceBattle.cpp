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

typedef pair<int,int> pi;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int E,N;
        cin>>E>>N;
        int H=0;
        priority_queue<pi,vector<pi>,greater<pi>> small;
        priority_queue<pair<int,int>>big;
        unordered_set<int> invalid;
        for(int i=0;i<N;++i){
            int Si;
            cin>>Si;
            small.push(make_pair(Si,i));
            big.push({Si,i});
        }
        while(true){
            while(!small.empty() && invalid.find(small.top().second)!=invalid.end()){
                small.pop();
            }
            while(!small.empty() && E>small.top().first){
                E-=small.top().first;
                invalid.insert(small.top().second);
                small.pop();
                H++;
                N--;
            }
            while(!big.empty() && invalid.find(big.top().second)!=invalid.end()){
                big.pop();
            }
            if(H>0 && N>1){
                E+=big.top().first;
                H--;
                invalid.insert(big.top().second);
                big.pop();
                N--;
            }
            else{break;}
        }

        cout<<"Case #"<<tt<<": "<<H<<endl;     
    }  
}
