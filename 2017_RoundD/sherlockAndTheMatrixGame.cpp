#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>

using namespace std;
int A[100001];
int B[100001];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,K,X1,Y1,C,D,E1,E2,F;
        cin>>N>>K>>X1>>Y1>>C>>D>>E1>>E2>>F;
        int R1=0;
        int S1=0;
        A[1]=X1;
        B[1]=Y1;
        for(int i=2;i<=N;++i){
            int X2=(C*X1+D*Y1+E1)%F;
            int Y2=(D*X1+C*Y1+E2)%F;
            int R2=(C*R1+D*S1+E1)%2;
            int S2=(D*R1+C*S1+E2)%2;
            A[i]=pow(-1,R2)*X2;
            B[i]=pow(-1,S2)*Y2;
            X1=X2;
            Y1=Y2;
            R1=R2;
            S1=S2;
        }
        
        priority_queue<int,vector<int>,greater<int>> minHeapA;
        priority_queue<int,vector<int>,greater<int>> minHeapB;
        priority_queue<int> maxHeapA;
        priority_queue<int> maxHeapB;
        vector<int> prevSumA={0};
        vector<int> prevSumB={0};

        int currentSumA=0;
        int currentSumB=0;
        int newSumA, newSumB;
        for(int i=1;i<=N;++i){
            currentSumA+=A[i];
            for(int j=0;j<prevSumA.size();++j){
                newSumA=currentSumA-prevSumA[j];
                if(minHeapA.size()<K){minHeapA.push(newSumA);}
                else if(newSumA>minHeapA.top()){
                    minHeapA.pop();
                    minHeapA.push(newSumA);
                }

                if(maxHeapA.size()<K){maxHeapA.push(newSumA);}
                else if(A[i]<maxHeapA.top()){
                    maxHeapA.pop();
                    maxHeapA.push(newSumA);
                }                
            }
            prevSumA.push_back(currentSumA);

            currentSumB+=B[i];
            for(int j=0;j<prevSumB.size();++j){
                newSumB=currentSumB-prevSumB[j];
                if(minHeapB.size()<K){minHeapB.push(newSumB);}
                else if(newSumB>minHeapB.top()){
                    minHeapB.pop();
                    minHeapB.push(newSumB);
                }

                if(maxHeapB.size()<K){maxHeapB.push(newSumB);}
                else if(newSumB<maxHeapB.top()){
                    maxHeapB.pop();
                    maxHeapB.push(newSumB);
                }
            }
            prevSumB.push_back(currentSumB);
            
        }

        vector<long long> smallA;
        vector<long long> bigA;
        vector<long long> smallB;
        vector<long long> bigB;
        while(!minHeapA.empty()){
            if(minHeapA.top()>=0){
                bigA.push_back((long long) minHeapA.top());
            }
            minHeapA.pop();
        }
        while(!minHeapB.empty()){
            if(minHeapB.top()>=0){
                bigB.push_back((long long) minHeapB.top());
            }
            minHeapB.pop();
        }
        while(!maxHeapA.empty()){
            if(maxHeapA.top()<0){
                smallA.push_back((long long) maxHeapA.top());
            }
            maxHeapA.pop();
        }
        while(!maxHeapB.empty()){
            if(maxHeapB.top()<0){
                smallB.push_back((long long) maxHeapB.top());
            }
            maxHeapB.pop();
        }

        long long low=-1e16;
        long long high=1e16; //might be a issue between int and long long conversion, deal later
        sort(smallB.begin(), smallB.end());
        sort(bigB.begin(), bigB.end());
        /*
        for(int i=0;i<smallA.size();i++){
            cout<<smallA[i]<<" ";
        }cout<<endl;
        for(int i=0;i<bigA.size();i++){
            cout<<bigA[i]<<" ";
        }cout<<endl;
        for(int i=0;i<smallB.size();i++){
            cout<<smallB[i]<<" ";
        }cout<<endl;
        for(int i=0;i<bigB.size();i++){
            cout<<bigB[i]<<" ";
        }cout<<endl;*/
        int t=0;
        while(low<high){ // boundary condition, deal with it later
            assert(t<100);
            long long mid=low+(high-low)/2+1;
            //cout<<"low is "<<low<<" high is "<<high<<" mid is "<<mid<<endl;
            int count=0;
            for(int i=0;i<smallA.size();++i){
                vector<long long>::iterator it=upper_bound(smallB.begin(),smallB.end(), (long long) floor((double)mid/smallA[i]));
  
                if(it!=smallB.begin()){
                    count=count+it-smallB.begin();
                }

                it=upper_bound(bigB.begin(), bigB.end(), (long long ) floor((double)mid/smallA[i]));
                if(it!=bigB.begin()){
                    count=count+it-bigB.begin();
                }
            }

            for(int i=0;i<bigA.size();++i){
                if(bigA[i]==0){ //might still have problem, rethink later
                    if(mid<=0){
                        count+=smallB.size();
                        count+=bigB.size();
                    }
                }
                else{
                    vector<long long>::iterator it=lower_bound(smallB.begin(), smallB.end(), (long long) ceil((double)mid/bigA[i]));
                    count=count+smallB.end()-it;

                    it=lower_bound(bigB.begin(),bigB.end(),(long long) ceil((double)mid/bigA[i]));
                    count=count+bigB.end()-it;
                }
            }

            if(count>=K){
                low=mid;
            }else{
                high=mid-1;
            }
            t++;
        }

        cout<<"Case #"<<tt<<": "<<high<<endl;   
    }  
}
