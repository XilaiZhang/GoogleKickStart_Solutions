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
const int P=5e5+5;
long long dp[P];
long long numbers[P];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,O;
        long long D;
        cin>>N>>O;
        cin>>D;
        memset(dp,0,sizeof dp);
        memset(numbers,0,sizeof numbers);
        long long result=LLONG_MIN;
        long long currentSum=0;
        long long X1,X2,A,B,C,M,L;
        cin>>X1>>X2>>A>>B>>C>>M>>L;
        numbers[0]=X1+L;
        numbers[1]=X2+L;
        for(int i=3;i<=N;++i){
            long long X3=(A*X2+B*X1+C)%M;
            numbers[i-1]=X3+L;
            X1=X2;
            X2=X3;
        }
        
        for(int i=0;i<N;++i){
            currentSum+=numbers[i];
            dp[i+1]=currentSum;
        }
        int left=0;
        int right=0;
        int oddCount=0;
        map<long long,long long> sums;
        while(right<N){
            long long prevSum=dp[right];
            sums[prevSum]++;

            if(abs(numbers[right])%2==1){
                oddCount++;
                while(oddCount>O && left<=right){
                    if(abs(numbers[left])%2==1){
                        oddCount--;
                    }
                    long long badSum=dp[left];
                    sums[badSum]--;
                    if(sums[badSum]==0){
                        sums.erase(badSum);
                    }
                    left++;
                }
                if(left>right){
                    right=left;
                    continue;
                }
            }
            
            long long mySum=dp[right+1];
            map<long long,long long>::iterator it=sums.lower_bound(mySum-D);
            if(it!=sums.end()){
                long long coolAnswer=mySum-(it->first);
                result=max(result,coolAnswer);
            }
            
            right+=1;
        }
        if(result==LLONG_MIN){
            cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<"Case #"<<tt<<": "<<result<<endl;
        }
    }  
}
