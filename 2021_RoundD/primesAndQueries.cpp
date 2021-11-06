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
int N, Q, P;
long long A[500005];


struct BIT{
    int n;
    vector<long long> tree;
    BIT(int n){
        this->n = n;
        tree = vector<long long>(n+1, 0);
    }
    void update(int pos, long long val){
        pos += 1;
        while(pos <= n){
            tree[pos] += val;
            pos += pos & (-pos);
        }
    }

    long long sum(int pos){
        long long res = 0;
        pos += 1;
        while(pos > 0){
            res += tree[pos];
            pos -= pos & (-pos);
        }
        return res;
    }
};

long long operationV (long long A, int P){
    long long result = 0;
    while ( A % P == 0){
        A /= P;
        result ++;
    }
    return result;
}

void generalAdd(long long A, BIT & divisibleTree, BIT &  minusTree, BIT & plusTree, 
BIT & undivisibleCount, int P, int pos){
    if(A < P){return ; } //V(0) = 0
    if(A % P == 0){
        divisibleTree.update(pos, operationV(A, P));
    }else{
        plusTree.update(pos, operationV(A + (A % P), P) - 1);
        minusTree.update(pos, operationV(A - (A % P), P));
        undivisibleCount.update(pos, 1);
    }
}

void generalDelete(long long A, BIT & divisibleTree, BIT &  minusTree, BIT & plusTree, 
BIT & undivisibleCount, int P, int pos){
    if(A < P){return ; } //V(0) = 0
    if(A % P == 0){
        divisibleTree.update(pos, -operationV(A, P));
    }else{
        plusTree.update(pos, -(operationV(A + (A % P), P) - 1));
        minusTree.update(pos, -operationV(A - (A % P), P));
        undivisibleCount.update(pos, -1);
    }
}

long long generalQuery(long long pos, long long S, BIT & divisibleTree, BIT &  minusTree, BIT & plusTree, 
BIT & undivisibleCount, int P){
    long long base = divisibleTree.sum(pos) * S + undivisibleCount.sum(pos) * operationV(S, P)
    + minusTree.sum(pos); 
    if(P==2 && (S%2==0)){
        base += plusTree.sum(pos);
    }
    return base;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<=T;++tt){
        cin>>N>>Q>>P;
        BIT divisibleTree = BIT(N);
        BIT minusTree = BIT(N);
        BIT plusTree = BIT(N);
        BIT undivisibleCount = BIT(N);

        for(int i=0;i<N;++i){
            cin>> A[i];
            generalAdd(A[i], divisibleTree, minusTree, plusTree, undivisibleCount, P, i);           
        }

        int type;
        long long pos, val;
        long long S, L, R;
        cout<<"Case #"<<tt<<":";
        for(int i=0;i<Q;++i){
            cin>>type;
            if(type == 1){
                cin>>pos>>val;
                pos --;
                generalDelete(A[pos], divisibleTree, minusTree, plusTree, undivisibleCount, P, pos);
                generalAdd(val, divisibleTree, minusTree, plusTree, undivisibleCount, P, pos);
                A[pos] = val;
            }else if(type==2){
                cin>>S>>L>>R;
                L--;
                R--;
                long long ans = generalQuery(R, S, divisibleTree, minusTree, plusTree, undivisibleCount, P)
                 - generalQuery(L-1, S, divisibleTree, minusTree, plusTree, undivisibleCount, P);
                cout<<" "<<ans;
            }
        }

        cout<<"\n";
    }




}


