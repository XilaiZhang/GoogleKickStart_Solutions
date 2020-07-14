#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>

using namespace std;

int N,Q;
const int col=32-__builtin_clz(200001);
int myDict[200001][col];
vector<int> numbers;

void build(){
    for(int j=1;j<32-__builtin_clz(N+1);++j){
        int bound=N+1-(1<<j)+1;
        for(int i=0;i<bound;++i){
            int n1=myDict[i][j-1];
            int n2=myDict[i+(1<<(j-1))][j-1];
            myDict[i][j]=max(n1,n2);
        }
    }
}

int query(int start, int end){
    int x=32-__builtin_clz(end-start+1)-1;
    return max(myDict[start][x],myDict[end-(1<<x)+1][x]);
}

int bSearch(int S, int K){
    int low=max(1,S-K+1);
    int high=min(S,N-K+1);
    while(low<high){
        int mid=(low+high)/2;
        int r=mid+K-1;
        if(mid<S && query(mid,S-1)>query(S,r)){low=mid+1;}
        else if(r>S && query(S,r-1)>query(mid-1,S-1)){high=mid;}
        else{return mid;low=mid;}
    }
    return low;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>Q;
        vector<int> emp(N+1);
        numbers=emp;
        for(int i=1;i<=N-1;++i){cin>>myDict[i][0];}
        myDict[0][0]=100001;
        myDict[N][0]=100001;

        build();
        
        int answer;
        cout<<"Case #"<<tt<<":";
        for(int i=1;i<=Q;++i){
        
            int S,K;
            cin>>S>>K;
            if(K==1){cout<<" "<<S; continue;}
            int l1=bSearch(S,K);
            int l2=bSearch(S,K-1);
            if(l1==l2){answer=l1+K-1;}
            else {answer=l1;}
            
            cout<<" "<<answer;
        }
        cout<<endl;

    }
}
