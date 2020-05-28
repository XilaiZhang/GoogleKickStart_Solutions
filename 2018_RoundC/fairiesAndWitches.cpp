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
int N;

int dfs(int state,int startIndex,vector<int>& edges,vector<vector<int>>& grid,
    int maxSide, int sideSum){
    int answer=0;
    if(startIndex==N){return answer;}
    if(edges.size()>=3 && 2*maxSide<sideSum && state==0){return 1;}
    int j=startIndex;
    while(j<N){
        if((1<<j)&state){
            break;
        }    
        ++j;
    }
    if(j==N){return 0;}
    for(int k=j+1;k<N;++k){
        if(((1<<k)&state) && grid[j][k]!=0){
            int s=(state & (~(1<<k)));
            s=(s & (~(1<<j)));
            vector<int> es=edges;
            es.push_back(grid[j][k]);
            int mSide=max(maxSide,grid[j][k]);
            int sSum=sideSum+grid[j][k];
            answer+=dfs(s, j+1,es,grid,mSide,sSum);
        }
    }
    //cout<<"state is "<<state<<" and answer is "<<answer<<endl;
    return answer;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        vector<vector<int>>grid;
        for(int i=0;i<N;++i){
            vector<int> line(N);
            for(int j=0;j<N;++j){
                cin>>line[j];
            }
            grid.push_back(line);

        }
        int state[1<<N];
        memset(state,0,sizeof state);
        int result=0;
        for(int i=1;i<(1<<N);++i){
            int precheck=__builtin_popcount(i);
            if(precheck<3 || precheck%2==1){continue;}
            vector<int>sides;
            result+=dfs(i,0,sides,grid,0,0);
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;
      
    }  
}
