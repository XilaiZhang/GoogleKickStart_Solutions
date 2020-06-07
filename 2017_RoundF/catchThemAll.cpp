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

int minDist[101][101];
const double bound=1e-20;


int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,M,P;
        cin>>N>>M>>P;
        memset(minDist,0,sizeof minDist);

        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(i==j){
                    minDist[i][j]=0;
                }
                else{
                    minDist[i][j]=100000000;
                }
            }
        }

        for(int i=0;i<M;++i){
            int U,V,D;
            cin>>U>>V>>D;

            minDist[U][V]=D;
            minDist[V][U]=D;
        }
       
        for(int k=1;k<=N;++k){
            for(int i=1;i<=N;++i){
                for(int j=1;j<=N;++j){
                    minDist[i][j]=min(minDist[i][j],minDist[i][k]+minDist[k][j]);
                }
            }
        }

        vector<double> sums(N+1,0);
        
        for(int i=1;i<=N;++i){
            int currentSum=0;
            for(int j=1;j<=N;++j){
                if(j==i){continue;}
                currentSum+=minDist[i][j];
            }
            sums[i]=(double)currentSum/(N-1);
        }

        vector<double> p(N+1,0); //probablility of ending at position i after catching j pokemon
        
        p[1]=1; //probability of ending at 1 after catching 0 pokemon
        double result=0;
        cout.precision(10);

        if(N==2){result=(double)P*minDist[1][2];P=0;}
        while(P>0){
            
            vector<double> tmp(N+1,0);
            
            for(int j=1;j<=N;++j){
                result+=p[j]*sums[j];
                for(int k=1;k<=N;++k){
                    if(k!=j){
                        tmp[k]+=p[j]/(N-1);
                    } 
                }
            }
            
            double e=0;
            for(int j=1;j<=N;++j){
                e+=fabs(p[j]-tmp[j]);
                p[j]=tmp[j];
            }
            if(e<bound){
                for(int j=1;j<=N;++j){
                    result+= p[j]*sums[j]*(P-1);
                }
                break;
            }

            P--;
        }
        
        
        cout<<"Case #"<<tt<<": "<<fixed<<result<<endl;     
    }  
}
