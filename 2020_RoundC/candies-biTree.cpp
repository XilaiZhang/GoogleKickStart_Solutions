#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>

using namespace std;
void update(vector<long long>& tree, int place, long long diff,int N){
    while(place<=N){
        tree[place]+=diff;
        place=place+(place & (-place));
    }
}

long long query(vector<long long>& tree, int place){
    long long answer=0;
    while(place>0){
        answer+=tree[place];
        place=place-(place & (-place));
    }
    return answer;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        int Q;
        long long result=0;
        cin>>N>>Q;
        vector<long long>A(N);
        vector<long long>biTree(N+1,0);
        vector<long long>interTree(N+1,0);

        for(int i=0;i<N;++i){
            long long t;
            cin>>t;
            update(biTree,i+1,pow(-1,i)*t,N);
            update(interTree,i+1,pow(-1,i)*(i+1)*t,N);
            A[i]=t;
        }
        for(int i=0;i<Q;++i){
            char op;
            cin>>op;
            int l;
            long long r;
            cin>>l>>r;
            if(op=='U'){
                update(biTree,l,pow(-1,l-1)*(r-A[l-1]),N);
                update(interTree,l,pow(-1,l-1)*l*(r-A[l-1]),N);
                A[l-1]=r;
            }
            else{
                long long basePart=query(biTree,r)-query(biTree,l-1); 
                long long interPart=query(interTree,r)-query(interTree,l-1); 
                //cout<<"basePart is "<<basePart<<" and interPART is "<<interPart<<endl;
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
