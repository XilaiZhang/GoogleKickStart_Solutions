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
vector<int> numbers;
vector<vector<int>> seg;
vector<vector<int>> shift;
vector<int> intervals;

void init(){
    for(int i=0;i<N;++i){
        int maxVal=-1;
        int minVal=5001;
        int segments=0;
        for(int j=i;j<N;++j){
            maxVal=max(maxVal,numbers[j]);
            if(numbers[j]<minVal){
                minVal=numbers[j];
                segments=0;//we have to start again
            }
            
            if(maxVal-minVal==j-i){
                segments++;
                seg[i][j]=segments; //increment on previous valid segments
                shift[i][j]=minVal-1-i; //always record the shift
            }
        }
    }
}

int compute(){
    int K=intervals.size()-1; //no shift at all
    for(int i=0;i<intervals.size()-1;++i){
        int L=intervals[i]+1;
        int R=intervals[i+1];
        int p1=0;
        if(L>0){p1=seg[0][L-1];}
        int p3=0;
        if(R+1<=N-1){p3=seg[R+1][N-1];}
        
        //a shift
        for(int L2=L;L2<R;++L2){
            if(seg[L][L2]==0 || shift[L][L2]!=R-L2){continue;}
            for(int R1=L2+1;R1<=R;++R1){
                if(seg[R1][R]==0 || shift[R1][R]!=L-R1){continue;}
                int ans=1+1+p1+p3; //shifted segments can't be further divided
                if(R1>L2){ans+=seg[L2+1][R1-1];}
                K=max(K,ans);
            }
        }
    }
    return K;
}

int computer(){
    int K=intervals.size()-1; 
    for(int i=0;i<intervals.size()-1;++i){
        int L=intervals[i]+1;
        int R=intervals[i+1];
        int p1=0;
        if(L>0){p1=seg[0][L-1];}
        int p3=0;
        if(R+1<=N-1){p3=seg[R+1][N-1];}

        for(int L2=L;L2<R;++L2){
            if(seg[L][L2]==0 || shift[L][L2]<0 || shift[L][L2]>R-L2){continue;}
            for(int R1=L2+1;R1<=R;++R1){
                if(seg[R1][R]==0 || shift[R1][R]>0 || shift[R1][R]<L-R1){continue;}
                int lengthA=L2-L+1;
                int lengthR=R-R1+1;

                if(shift[L][L2]==R-L2){
                    if(shift[R1][R]==L-R1){ // swap just 2
                        int ans=1+1+p1+p3; 
                        if(R1>L2){ans+=seg[L2+1][R1-1];}
                        K=max(K,ans);
                    }
                    //L..L2 D B E R1...R
                    //B D R1..R E L...L2
                    //B is the expressed as [M1..M2], one of the 3 swapped segments
                    if(shift[R1][R]>L-L2-1){continue;}
                    int E=R-lengthA-(R+shift[R1][R]);
                    int M2=R-lengthR-E;
                    for(int M1=L2+1;M1<=M2;++M1){
                        if(shift[M1][M2]!=L-M1){continue;}
                        int ans=p1+p3+1+1+1;
                        if(E>0){ans+=seg[M2+1][R1-1];}
                        if(M1>L2+1){ans+=seg[L2+1][M1-1];}
                        K=max(K,ans);
                    }
                }
                //L..L2 D B E R1...R
                //R1...R D L1...L2 E B
                else if(shift[R1][R]==L-R1){
                    if(shift[L][L2]<lengthR){continue;}
                    int D=L+shift[L][L2]-(L+lengthR);
                    int M1=L2+D+1;
                    for(int M2=M1;M2<R1;M2++){
                        if(shift[M1][M2]!=R-M2){continue;}
                        int ans=p1+p3+1+1+1;
                        if(D>0){ans+=seg[L2+1][M1-1];}
                        if(M2<R1-1){ans+=seg[M2+1][R1-1];}
                        K=max(K,ans);
                    }
                }
                
            }
        }
    }
    return K;
}

int main(){
    int T;
    cin>>T;
    int P;
    
    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        cin>>P;
        vector<int>v1(N);
        numbers=v1;
        vector<vector<int>> v2(N,vector<int>(N,0));
        seg=v2;
        shift=v2;
        vector<int> emp={-1};
        intervals=emp;
        for(int i=0;i<N;++i){cin>>numbers[i];}
        init();
        for(int i=0;i<N;i++){
            if(seg[0][i]!=0 && shift[0][i]==0){intervals.push_back(i);}
        }
        int result=0;
        if(P==2){result=compute();}
        else{result=computer();}
        
        cout<<"Case #"<<tt<<": "<<result<<"\n";    
    }
}
