#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>

using namespace std;
void update(long long * tree, int place, long long newVal){
    long long diff=newVal-tree[place];
    while(place>0){
        tree[place]+=diff;
        place=(place>>1);
    }
}

long long query(long long * tree, int left, int right){
    long long answer=0;
    while(left<=right){
        if(left==right){
            answer+=tree[left];
            break;
        }
        if(left&1){
            answer+=tree[left];
            left++;
        }
        if(!(right&1)){
            answer+=tree[right];
            right--;
        }
        left=left>>1;
        right=right>>1;
    }
    return answer;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,Q;
        long long result=0;
        cin>>N>>Q;

        int bound=0;
        if(N>1){bound=int(log2(N-1))+1;}
        
        long long baseTree[int(pow(2,bound+1))];
        long long interTree[int(pow(2,bound+1))];
        int base=pow(2,bound);

        for(int i=0;i<N;++i){
            long long t;
            cin>>t;
            baseTree[base+i]=pow(-1,i)*t;
            interTree[base+i]=pow(-1,i)*(i+1)*t;
        }

        for(int j=base-1;j>0;j--){
            baseTree[j]=baseTree[j<<1]+baseTree[(j<<1)+1];
            interTree[j]=interTree[j<<1]+interTree[(j<<1)+1];
        }
 
        for(int i=0;i<Q;++i){
            char op;
            cin>>op;
            int l;
            long long r;
            cin>>l>>r;
            if(op=='U'){
                update(baseTree,base+l-1,pow(-1,l-1)*r);
                update(interTree,base+l-1,pow(-1,l-1)*l*r);
            }
            else{
                long long basePart=query(baseTree,base+l-1,base+r-1); 
                long long interPart=query(interTree,base+l-1,base+r-1); 
                if(l%2==0){
                    interPart=-interPart;
                    result=result+interPart+(l-1)*basePart;
                }
                else{
                    result=result+interPart-(l-1)*basePart;
                }
                
            }
                
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;;
    }
}
