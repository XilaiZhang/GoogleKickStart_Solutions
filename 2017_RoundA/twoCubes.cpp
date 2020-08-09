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
int N;
int bound=1e8+5;

int main(){
    int T;
    cin>>T;
    vector<vector<int>> vertices={{0,0,0},{1,0,0},{1,1,0},{0,1,0},
    {0,1,1},{1,1,1},{1,0,1},{0,0,1}};
    int x1,x2,y1,y2,z1,z2;

    
    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        vector<int> X(N);
        vector<int> Y(N);
        vector<int> Z(N);
        vector<int> R(N);
        int minX=bound,minY=bound,minZ=bound;
        int maxX=-bound,maxY=-bound,maxZ=-bound;
        for(int i=0;i<N;++i){
            cin>>X[i]>>Y[i]>>Z[i]>>R[i];
            minX=min(X[i]-R[i],minX);
            minY=min(Y[i]-R[i],minY);
            minZ=min(Z[i]-R[i],minZ);
            maxX=max(X[i]+R[i],maxX);
            maxY=max(Y[i]+R[i],maxY);
            maxZ=max(Z[i]+R[i],maxZ);
        }
        int L=max(maxX-minX, max(maxY-minY,maxZ-minZ));
        
        int result=4*bound;
        for(auto vec:vertices){
            int low=0;
            int high=L;
            while(low<high){
                
                int mid=low+(high-low)/2;
                if(vec[0]==0){x1=minX;x2=minX+mid;}else{x1=maxX-mid;x2=maxX;}
                if(vec[1]==0){y1=minY;y2=minY+mid;}else{y1=maxY-mid;y2=maxY;}
                if(vec[2]==0){z1=minZ;z2=minZ+mid;}else{z1=maxZ-mid;z2=maxZ;}
                int a1=bound,b1=bound,c1=bound;
                int a2=-bound,b2=-bound,c2=-bound;
                for(int i=0;i<N;++i){
                    if(X[i]-R[i]>=x1 && X[i]+R[i]<=x2 && Y[i]-R[i]>=y1 && Y[i]+R[i]<=y2 && Z[i]-R[i]>=z1 && Z[i]+R[i]<=z2){continue;}
                    else{
                        a1=min(X[i]-R[i],a1);
                        b1=min(Y[i]-R[i],b1);
                        c1=min(Z[i]-R[i],c1);
                        a2=max(X[i]+R[i],a2);
                        b2=max(Y[i]+R[i],b2);
                        c2=max(Z[i]+R[i],c2);
                    }
                }
                int l=4*bound;
                if(a1==bound){l=-1;}
                else{l=max(a2-a1, max(b2-b1,c2-c1));}
                
                if(l<=mid){high=mid;}
                else{low=mid+1;}
            }
            
            result=min(result,low);
        }
        cout<<"Case #"<<tt<<": "<<result<<"\n";    
        
    }
}
