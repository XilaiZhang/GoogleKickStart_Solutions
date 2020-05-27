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

int h[101][101][101];
int v[101][101][101];

struct node{
    vector<node *> children;
    int endCount;
    node(){
        vector<node*> kids(26,nullptr);
        children=kids;
        endCount=0;
    }
};

int gcd(int a, int b){
    if(b==0){return a;}
    return gcd(b,a % b);
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int R,C,W;
        cin>>R>>C>>W;
        vector<string> grid;
        for(int i=0;i<R;++i){
            string line;
            cin>>line;
            grid.push_back(line);
        }
        node dummy=node();
        for(int i=0;i<W;++i){
            string word;
            cin>>word;
            node * it=&dummy;
            for(char c:word){
                if((it->children[c-'A'])==nullptr){
                    it->children[c-'A']=new node();
                }
                it=it->children[c-'A'];
            }
            (it->endCount)=(it->endCount)+word.size();
            it=&dummy;
            for(int j=word.size()-1;j>=0;j--){
                char r=word[j];
                if((it->children[r-'A'])==nullptr){
                    it->children[r-'A']=new node();
                }
                it=it->children[r-'A'];
            }
            (it->endCount)=(it->endCount)+word.size();
        }
        
        memset(h,0,sizeof h);
        memset(v,0,sizeof v);
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                node * it=&dummy;
                int count=0;
                for(int k=0;k<=j;++k){
                    char t=grid[i][j-k];
                    if(it->children[t-'A']==nullptr){
                        for(int z=k;z<=j;++z){
                            h[i][j][z]=count;
                        }
                        break;
                    }
                    else{
                        it=it->children[t-'A'];
                        count+=(it->endCount);
                        h[i][j][k]=count;
                    }
                }
            }
        }
        for(int j=0;j<C;++j){
            for(int i=0;i<R;++i){
                node * it=&dummy;
                int count=0;
                for(int k=0;k<=i;++k){
                    char t=grid[i-k][j];
                    if(it->children[t-'A']==nullptr){
                        for(int z=k;z<=i;++z){
                            v[i][j][z]=count;
                        }
                        break;
                    }
                    else{
                        it=it->children[t-'A'];
                        count+=(it->endCount);
                        v[i][j][k]=count;   
                    }
                }
            }
        }
       
        double funVal=-1;
        int numerator=-1;
        int denominator=1;
        int funValCount=0;
        for(int s=0;s<R;++s){
            for(int t=0;t<C;++t){
                int dp[101][101];
                memset(dp,0,sizeof dp);
                dp[s][t]=h[s][t][0]+v[s][t][0];
                double potential=((double)dp[s][t])/2;
                if(potential>funVal){
                    funVal=potential;
                    funValCount=1;
                    if(dp[s][t]==0){numerator=0;denominator=1;}
                    else{
                        int g=gcd(dp[s][t],2);
                        numerator=dp[s][t]/g;
                        denominator=2/g;
                    }
                }else if(potential==funVal){
                    funValCount++;
                }
                for(int y=t+1;y<C;++y){
                    dp[s][y]=dp[s][y-1]+h[s][y][y-t]+v[s][y][0]; 
                    double potential=((double)dp[s][y])/((double)(1+y-t+1));
                    if(potential>funVal){
                        funVal=potential;
                        funValCount=1;
                        if(dp[s][y]==0){numerator=0;denominator=1;}
                        else{
                            int g=gcd(dp[s][y],1+y-t+1);
                            numerator=dp[s][y]/g;
                            denominator=(1+y-t+1)/g;
                        }
                    }else if(potential==funVal){
                        funValCount++;
                    }
                }
                for(int x=s+1;x<R;++x){
                    dp[x][t]=dp[x-1][t]+h[x][t][0]+v[x][t][x-s];
                    double potential=((double)dp[x][t])/((double)(1+x-s+1));
                    if(potential>funVal){
                        funVal=potential;
                        funValCount=1;
                        if(dp[x][t]==0){numerator=0;denominator=1;}
                        else{
                            int g=gcd(dp[x][t],1+x-s+1);
                            numerator=dp[x][t]/g;
                            denominator=(1+x-s+1)/g;
                        }
                    }else if(potential==funVal){
                        funValCount++;
                    }
                }
                for(int x=s+1;x<R;++x){
                    for(int y=t+1;y<C;++y){
                        dp[x][y]=dp[x-1][y]+dp[x][y-1]-dp[x-1][y-1]+h[x][y][y-t]+v[x][y][x-s];
                        double potential=((double)dp[x][y])/((double)(x-s+1+y-t+1));
                        if(potential>funVal){
                            funVal=potential;
                            funValCount=1;
                            if(dp[x][y]==0){numerator=0;denominator=1;}
                            else{
                                int g=gcd(dp[x][y],x-s+1+y-t+1);
                                numerator=dp[x][y]/g;
                                denominator=(x-s+1+y-t+1)/g;
                            }
                        }else if(potential==funVal){
                            funValCount++;
                        }
                    }
                }
            }
        }
        if(numerator==0){denominator=1;}
        cout<<"Case #"<<tt<<": "<<numerator<<"/"<<denominator<<" "<<funValCount<<endl;
      
    }  
}
