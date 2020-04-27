#include <vector>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

const int length=1e5+5;
int vals[length];
long long states[length][5];

int main(){
    int T;
    cin>>T;
    for (int tt=1;tt<=T;++tt){
        int N;
        cin>>N;
        //memset(states,0,sizeof(states)); //i dont think this is necessary
        vector<bool> seen(N+1,false);
        vector<vector<int>>neighbors(N+1);
        vector<vector<int>>children(N+1);
        for (int i=0;i<N;++i){
            cin>>vals[i];
        }
        for (int i=0;i<N-1;++i){
            int a,b;
            cin>>a>>b;
            neighbors[a].push_back(b);
            neighbors[b].push_back(a);
        }
        
        vector<vector<int>>q={{1}};
        int index=0;
        vector<int>tmp;
        while(index<q.size()){
            for(int i=0;i<q[index].size();i++){
                int num=q[index][i];
                seen[num]=true;
                for(int j=0;j<neighbors[num].size();j++){
                    int n=neighbors[num][j];
                    if(!seen[n]){
                        children[num].push_back(n);
                        tmp.push_back(n);
                    }
                }
            } 
            if(!tmp.empty()){
                q.push_back(tmp);
            }
            index++;
            vector<int> empty;
            tmp=empty;
        }
//1 for light light, 2 for light,dark, 3 for dark light, 4 for dark dark
        for(int i=q.size()-1;i>-1;i--){
            for(int number:q[i]){
                if(children[number].empty()){
                    states[number][1]=vals[number-1];
                    states[number][2]=vals[number-1];
                    states[number][3]=vals[number-1];
                    states[number][4]=0;
                }
                else{
                    long long sumA=0;
                    long long sumB=0;
                    long long allDark=0;
                    bool init=false;
                    long long oneLightAllDark=0;
                    for(int child: children[number]){
                        long long a=max(states[child][1],states[child][2]);
                        long long b=max(states[child][3],states[child][4]);
                        sumA+=a;
                        sumB+=b;
                        if (!init){
                            oneLightAllDark=states[child][3];
                            init=true;
                        }
                        else{
                            oneLightAllDark=max(allDark+states[child][3],oneLightAllDark+max(states[child][4],states[child][3]));
                        }
                        allDark+=states[child][4];
                    }
                        
                    states[number][1]=sumA+vals[number-1];
                    states[number][2]=sumB+vals[number-1];
                    states[number][3]=sumA+vals[number-1];
                    states[number][4]=max(allDark,vals[number-1]+oneLightAllDark);
                }
            }
        }
        /*
        for (int i=0;i<N+1;i++){

            for(int j=0;j<5;j++){
                cout<<states[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<"Case #"<<tt<<": "<<max(states[1][3],states[1][4])<<endl;
    }
}