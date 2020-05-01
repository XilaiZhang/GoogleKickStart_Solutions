#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
const int length=1e5+5;
int result[length];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,G,M;
        cin>>N>>G>>M;
        unordered_map<int,int> groupC;
        unordered_map<int,int> groupA;
        vector<vector<int>> C(length);
        vector<vector<int>> A(length);
        for(int g=0;g<G;g++){
            int pos;
            char clock;
            cin>>pos>>clock;
            if(clock=='C'){
                C[pos].push_back(g);
            }
            else{
                A[pos].push_back(g);
            }
        }
        int nextC=-1;
        for(int i=N;i>0;i--){
            C[i].push_back(nextC);
            if(C[i].size()>1){
                nextC=i;
            }
        }
        int nextA=-1;
        for(int i=1;i<N+1;i++){
            A[i].push_back(nextA);
            if(A[i].size()>1){
                nextA=i;
            }
        }

        for(int p=1;p<N+1;p++){
            int closeC=p-M%N;
            if(closeC<1){
                closeC+=N;
            }
            int closeA=p+M%N;
            if(closeA>N){
                closeA-=N;
            }
            int stepC=0;
            if(C[closeC].size()==1){
                if(C[closeC].back()==-1){
                    stepC+=N+1-closeC;
                    if(C[1].size()>1){
                        closeC=1;
                    }
                    else{
                        if(C[1].back()==-1){
                            stepC=M+1;
                        }    
                        else{
                            stepC+=C[1].back()-1;
                            closeC=C[1].back();
                        }
                    }
                }
                else{
                    stepC+=C[closeC].back()-closeC;
                    closeC=C[closeC].back(); 
                }
            }
            int stepA=0;
            if(A[closeA].size()==1){
                if(A[closeA].back()==-1){
                    stepA+=closeA;
                    if(A[N].size()>1){
                        closeA=N;
                    }
                    else{
                        if(A[N].back()==-1){
                            stepA=M+1;
                        }    
                        else{
                            stepA+=N-A[N].back();
                            closeA=A[N].back();
                        }
                    }
                }
                else{
                    stepA+=closeA-A[closeA].back();
                    closeA=A[closeA].back(); 
                }
            }
            
            if(stepC<=M && stepC<=stepA){
                groupC[closeC]++;
            }
            
            if(stepA<=M && stepA<=stepC){
                groupA[closeA]++;
            }
        }
        vector<int> result(G);
        for(auto it:groupC){
            int t=it.first;
            C[t].pop_back();
            for(int ele:C[t]){
                result[ele]+=groupC[t];
            }
        }
        for(auto it:groupA){
            int t=it.first;
            A[t].pop_back();
            for(int ele:A[t]){
                result[ele]+=groupA[t];
            }
        }
        string re="";
        for(int r=0;r<G;r++){
            re+=" "+to_string(result[r]);
        }

        cout<<"Case #"<<tt<<":"<<re<<endl;
    }

}
