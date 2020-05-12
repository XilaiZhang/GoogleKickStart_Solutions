#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,Q;
        cin>>N>>Q;
        long long X1,X2,A1,B1,C1,M1;
        long long Y1,Y2,A2,B2,C2,M2;
        long long Z1,Z2,A3,B3,C3,M3;
        cin>>X1>>X2>>A1>>B1>>C1>>M1;
        cin>>Y1>>Y2>>A2>>B2>>C2>>M2;
        cin>>Z1>>Z2>>A3>>B3>>C3>>M3; 
        map <long long,int>events;
        long long l=min(X1,Y1)+1;
        long long r=max(X1,Y1)+1;
        events[r]+=1;
        events[l-1]-=1;
        long long K=Z1+1;
        vector<long long>queries;
        queries.push_back(K);
        l=min(X2,Y2)+1;
        r=max(X2,Y2)+1;
        if(N>1){
            events[r]+=1;
            events[l-1]-=1;
        }
        K=Z2+1;
        if(Q>1){
           queries.push_back(K);
        }
        for(int i=3;i<N+1;++i){
            long long Xi=(A1*X2+B1*X1+C1)%M1;
            long long Yi=(A2*Y2+B2*Y1+C2)%M2;
            l=min(Xi,Yi)+1;
            r=max(Xi,Yi)+1;
            events[r]+=1;
            events[l-1]-=1;
            X1=X2;
            Y1=Y2;
            X2=Xi;
            Y2=Yi;
        }
        for(int i=3;i<Q+1;++i){
            long long Zi=(A3*Z2+B3*Z1+C3)%M3;
            K=Zi+1;
            queries.push_back(K);
            Z1=Z2;
            Z2=Zi;
        }/*
        for(auto it:events){
            cout<<it.first<<" "<<it.second<<endl;;
        }*/

        vector<long long> numbers;
        vector<pair<long long,long long>> points;
        int quantity=0;
        long long prevPoint=0;
        long long currentSum=0;
        for(map<long long ,int>::reverse_iterator it=events.rbegin();it!=events.rend();++it){
            if(it->second==0){continue;}
            long long newQuantity=quantity+it->second;
            if(quantity!=0 && newQuantity!=quantity){
                currentSum+=quantity*(prevPoint-it->first);
            }
            if(newQuantity!=0 && newQuantity!=quantity){
                numbers.push_back(currentSum);
                points.push_back({it->first,newQuantity});
            }
            //cout<<"quantity newQuantity "<<quantity<<" "<<newQuantity<<endl;
            prevPoint=it->first;
            quantity=newQuantity;
        }
        numbers.push_back(currentSum);
        /*
        for(int x:numbers){
            cout<<"numbers "<<x<<endl;
        }
        for(auto it:points){
            cout<<it.first<<" "<<it.second<<endl;
        }*/
        long long result=0;
        for(int i=0;i<queries.size();++i){
            long long q=queries[i];
            vector<long long>::iterator check=lower_bound(numbers.begin(),numbers.end(),q);
            if(check==numbers.end()){
                //result+=" 0";
                continue;
            }
            long long pos=check-numbers.begin();
            pos--;
            long long remainder=q-numbers[pos];
            long long base=points[pos].first;
            base=base-(remainder-1)/(points[pos].second);
            result=result+(i+1)*base;
        }
        
        cout<<"Case #"<<tt<<": "<<result<<endl;;
    }
}
