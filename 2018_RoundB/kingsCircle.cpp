#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <list>

using namespace std;
const int bound=1e6+2;
int tree[bound];
int smallTree[bound];

void update(int * tree, int place, int diff, int N){
    while(place<=N){
        tree[place]+=diff;
        place=place+ (place & (-place));
    }
}

int query(int *tree, int place){
    int answer=0;
    while(place>0){
        answer+=tree[place];
        place=place- (place & (-place) );
    }
    return answer;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        long long result=0;
        long long badCount=0;
        long long N,V1,H1,A,B,C,D,E,F,M;
        cin>>N>>V1>>H1>>A>>B>>C>>D>>E>>F>>M;
        vector<pair<int,int>> positions;
        positions.push_back({(int)V1,(int)H1});
        for(int i=2;i<=N;++i){
            long long V2=(A*V1+B*H1+C)%M;
            long long H2=(D*V1+E*H1+F)%M;
            positions.push_back({(int)V2,(int)H2});
            V1=V2;
            H1=H2;
        }
        sort(positions.begin(),positions.end());
        
        memset(tree,0,sizeof tree);
        for(int i=0;i<N;++i){
            update(tree,positions[i].second+1,1,bound-1);
        }
        memset(smallTree,0,sizeof smallTree);
        int prev=-1;
        vector<pair<int,int>> same;
        int j=0;
        while(j<N){
            while(positions[j].first==prev){
                same.push_back(positions[j]);
                update(tree,positions[j].second+1,-1,bound-1);
                j++;
                continue;
            }
            for(int t=0;t<same.size();++t){
                int leftDown=query(smallTree, same[t].second);
                int leftUp=query(smallTree, bound)-query(smallTree,same[t].second+1);
                int rightDown=query(tree,same[t].second);
                int rightUp=query(tree, bound)-query(tree,same[t].second+1);
                badCount=badCount+(long long)leftUp*rightDown+(long long)leftDown*rightUp;
            }
            for(int t=0;t<same.size();++t){
                update(smallTree,same[t].second+1,1,bound-1);
            }
            same.clear();
            same.push_back(positions[j]);
            update(tree,positions[j].second+1,-1,bound-1);
            prev=positions[j].first;
            j++;
        }
        result=N*(N-1)*(N-2)/6-badCount;
        cout<<"Case #"<<tt<<": "<<result<<endl;     
    }  
}
