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

using namespace std;

long long H[100005];
long long X[100005];
long long Y[100005];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,K;
        cin>>N>>K;
        long long P1,P2,A1,B1,C1,M1;
        long long H1,H2,A2,B2,C2,M2;
        long long X1,X2,A3,B3,C3,M3;
        long long Y1,Y2,A4,B4,C4,M4;
        
        cin>>P1>>P2>>A1>>B1>>C1>>M1;
        cin>>H1>>H2>>A2>>B2>>C2>>M2;
        cin>>X1>>X2>>A3>>B3>>C3>>M3;
        cin>>Y1>>Y2>>A4>>B4>>C4>>M4;

        memset(X,0,sizeof X);
        memset(Y,0,sizeof Y);
        
        vector<pair<long long,long long>> towers;
        towers.push_back({P1,H1});
        towers.push_back({P2,H2});
        X[1]=X1;
        X[2]=X2;
        Y[1]=Y1;
        Y[2]=Y2;

        for(int i=3;i<=N;++i){
            long long P3=(A1*P2+B1*P1+C1)%M1+1;
            long long H3=(A2*H2+B2*H1+C2)%M2+1;
            towers.push_back({P3,H3});
            P1=P2;
            P2=P3;
            H1=H2;
            H2=H3;
        }
        
        for(int i=3;i<=K;++i){
            X[i]=(A3*X[i-1]+B3*X[i-2]+C3)%M3+1;
            Y[i]=(A4*Y[i-1]+B4*Y[i-2]+C4)%M4+1;
        }
        sort(towers.begin(),towers.end());
        vector<pair<long,long>> validTowers;
        int j=0;
        while(j<towers.size()){
            while(!validTowers.empty() && (towers[j].second-validTowers.back().second
                    )>=(towers[j].first-validTowers.back().first)){
                validTowers.pop_back();
            }
            if(validTowers.empty() || (towers[j].second> validTowers.back().second-(
                towers[j].first-validTowers.back().first))){
                validTowers.push_back(towers[j]);
            }
            j++;
        }
        
        long long result=0;
        for(int i=1;i<=K;++i){
            int pos1=-1;
            auto it=lower_bound(
                validTowers.begin(),validTowers.end(),make_pair(X[i],(long long)(-1)),
                [](const pair<long long, long long>& a, const pair<long long, long long > &b){
                    return a.first<b.first;
                });
            if(it==validTowers.end()){pos1=validTowers.size()-1;}
            else{pos1=distance(validTowers.begin(),it);}
            if(validTowers[pos1].second>=Y[i] && (
                validTowers[pos1].second-Y[i])>=abs(validTowers[pos1].first-X[i])){
                result++;
                continue;
            }
            if(pos1>0){
                pos1=pos1-1;
                if(validTowers[pos1].second>=Y[i] && (
                    validTowers[pos1].second-Y[i])>=abs(validTowers[pos1].first-X[i])){
                    result++;
                }
            }
           

        }
        cout<<"Case #"<<tt<<": "<<result<<endl;
      
    }  
}
