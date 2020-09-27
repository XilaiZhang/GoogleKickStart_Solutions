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

int result;
long long forbid;
int S;

bool isSquare(long double x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
}

vector<int> computeN(int m){
    vector<int> result;
    int pivot=(S-1)*(S-1);
    if(m==0){return {2};}
    if(isSquare(m)){
        if(m==pivot){return {m+1};}
        else{
            result.push_back(m+1);
            int a1=sqrt(m)+2;
            result.push_back(a1*(a1-2)+2);
            return result;
        }
    }
    if(isSquare(m+1)){
        if(m+1==S*S){return {m-1};}
        else{
            result.push_back(m-1);
            int a1=sqrt(m+1)+1;
            result.push_back(a1*a1-2);
            return result; 
        }
    }
    int q=sqrt(m);
    int b=m-q*q;
    if(m>=(S-1)*(S-1) && b%2==0){
        result.push_back(m+1);
        result.push_back(m-1);
        return result;
    }
    
    if(b%2==1){
        result.push_back(m+1);
        result.push_back(m-1);
        result.push_back((q-1)*(q-1)+b-1);
        return result;
    }
    else{
        result.push_back(m+1);
        result.push_back(m-1);
        result.push_back((q+1)*(q+1)+b+1);
    }
    return result;
}


 int dfs(int person, long long state, int sa, int sb, int countA, int countB){
    int minScore=128;
    int maxScore=-128;
    if(person==1){
        for(int v:computeN(sb)){
            if((state & (1LL<<v))==0 && ((forbid&(1LL<<v))==0) ){
                minScore=min(minScore,dfs(1-person,state|(1LL<<v),sa,v,countA,countB+1));
            }
        }
    }
    else{
        for(int v:computeN(sa)){
            if((state & (1LL <<v))==0 && ((forbid&(1LL<<v))==0)){
                maxScore=max(maxScore,dfs(1-person,state|(1LL<<v),v,sb,countA+1,countB));
            }
        }
    }

    
        if(person==0){
            if(maxScore==-128 ){
                int p=1;
                for(int v:computeN(sb)){
                    if((state & (1LL<<v))==0 && ((forbid&(1LL<<v))==0)){
                        minScore=min(minScore, dfs(p,state|(1LL<<v),sa,v,countA,countB+1));
                    }
                }
                if(minScore==128){return countA-countB;}
                else{return minScore;}
            }
            else{return maxScore;}
        }
        if(person==1){
            if(minScore==128){
                int p=0;
                for(int v:computeN(sa)){
                    if((state & (1LL<<v))==0 && ((forbid&(1LL<<v))==0)){
                        maxScore=max(maxScore, dfs(p,state|(1LL<<v),v,sb,countA+1,countB));
                    }
                }
                if(maxScore==-128){return countA-countB;}
                else{return maxScore;}
            }
            else{return minScore;}
        }
    cout<<"you can never reach this part, lol"<<endl;
    return 0;

 }

int main(){
    int T;
    cin>>T;
    int ra,pa,rb,pb,C;
    int a,b;
   

    for(int tt=1;tt<T+1;++tt){  
        cin>>S>>ra>>pa>>rb>>pb>>C;
        forbid=0;
        result=128;
        for(int i=0;i<C;++i){
            cin>>a>>b;
            if(a==1){forbid|=1;}
            else{forbid|=(1LL<<(a*(a-2)+b));}
        }

        int scoreA=1;
        int scoreB=1;
        long long state=0;
        int sa=6;
        int sb=6;
        if(ra==1){state|=1;sa=0;}
        else{state|=(1LL<<(ra*(ra-2)+pa));sa=ra*(ra-2)+pa;}

        if(rb==1){state|=1;sb=0;}
        else{state|=(1LL<<(rb*(rb-2)+pb));sb=rb*(rb-2)+pb;}
        result=dfs(0,state,sa,sb,1,1);
        
        cout<<"Case #"<<tt<<": "<<result<<"\n";    
    }
}
