#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;
vector<vector<int>> grid(101,vector<int>(101));

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,M,E,SR,SC,TR,TC;
        cin>>N>>M>>E>>SR>>SC>>TR>>TC;
        TR--;
        TC--;
        SR--;
        SC--;
        
        vector<pair<int,int>>traps;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cin>>grid[i][j];
                if(grid[i][j]<0 && grid[i][j]>-100000){
                    traps.push_back({i,j});
                }
                  
            }
        }
        int t=traps.size();
        
        vector<bool>state((1<<t),false);
        int result=-1;
        state[0]=true;

        for(int i=0;i<(1<<t);++i){
            if(!state[i]){continue;}
            vector<int> neighbor;
            int e=E;
            bool flag=false;
            bool seen[101][101]={{false}};
            vector<pair<int,int>> tmp;
            tmp.push_back({SR,SC});
            for(int j=0;j<t;++j){ 
                if(i&(1<<j)){
                    int p=traps[j].first;
                    int q=traps[j].second;
                    seen[p][q]=true;
                    e=e+grid[p][q];
                    tmp.push_back({p+1,q});
                    tmp.push_back({p-1,q});
                    tmp.push_back({p,q+1});
                    tmp.push_back({p,q-1});
                }
            }
            while(!tmp.empty()){
                pair<int,int> point=tmp.back();
                tmp.pop_back();
                int x=point.first;
                int y=point.second;
                if(x<0 || x>=N || y<0 || y>=M || grid[x][y]==-100000 || seen[x][y] ){
                    continue;
                }
                seen[x][y]=true;
                if(grid[x][y]<0){
                    for(int h=0;h<t;++h){
                        if(traps[h].first==x && traps[h].second==y){
                            neighbor.push_back(h);
                            break;
                        }
                    }
                    continue;
                }
                if(grid[x][y]>0){
                    e+=grid[x][y];
                }
                if(x==TR && y==TC){flag=true;}
                tmp.push_back({x+1,y});
                tmp.push_back({x-1,y});
                tmp.push_back({x,y+1});
                tmp.push_back({x,y-1});
            }

            if(flag){
                result=max(result,e);
            }

            for(int j: neighbor){
                int p=traps[j].first;
                int q=traps[j].second;
                if(e+grid[p][q]>=0){ //grid[p][q] is a negative value
                    state[(i|(1<<j))]=true;
                }
            }

        }
        cout<<"Case #"<<tt<<": "<<result<<endl;;
    }
}
