
#include <unordered_map>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct node{
    int val=0;
    int maxPrefix=0;
    node(){        
    }
};

void update(node* A, int place, int newVal){
    int diff=newVal-A[place].val;
    A[place].val+=diff;
    A[place].maxPrefix=max(0,A[place].val);
    place/=2;
    while(place>0){
        A[place].val+=diff;
        A[place].maxPrefix=max(A[(place<<1)].maxPrefix, A[(place<<1)].val+A[(place<<1)+1].maxPrefix);
        place/=2;
    }

}

int main(){
    int T;
    cin>>T;

    for (int tt=1;tt<T+1;++tt){
        int N,S;
        cin>>N>>S;
        unordered_map<int,vector<int>> pos;
        unordered_map<int,int> count;
        int L;
        for(int t=0;t<=17;t++){
            if((1<<t)>=N){
                L=t;
                break;
            }
        }
        int base=pow(2,L);
        node A[int(pow(2,L+1))];

        vector<int> types;
        for(int i=0;i<N;i++){
            int type;
            cin>>type;
            types.push_back(type);
            count[type]++;
            int num=1;
            if(count[type]==S+1){
                num=-S;
            }else if(count[type]>S+1){
                num=0;
            }
            
            A[base+i].val=num;
            A[i+base].maxPrefix=max(0,num);
            
            pos[type].push_back(i);
        }
        for(int i=base-1;i>0;i--){
            A[i].val=A[(i<<1)].val+A[(i<<1)+1].val;
            A[i].maxPrefix=max(A[(i<<1)].maxPrefix, A[(i<<1)].val+A[(i<<1)+1].maxPrefix);
        }
        /*for(int i=2*base-1;i>0;i--){
            cout<<A[i].val<<" "<<A[i].maxPrefix<<endl;
        }*/
        int result=A[1].maxPrefix;
        for(int j=0;j<N;j++){
            update(A,j+base,0);
            int t=types[j];
            int index=lower_bound(pos[t].begin(),pos[t].end(),j)-pos[t].begin();
            if(pos[t].size()-1>=index+S){
                update(A,base+pos[t][index+S],1);
            }
            if(pos[t].size()-1>index+S){
                update(A,base+pos[t][index+S+1],-S);
            }
            result=max(result,A[1].maxPrefix);
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;

    }
}

    
    
    

    