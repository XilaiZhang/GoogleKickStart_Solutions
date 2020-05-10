#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;
        vector<long long>numbers;
        for(int i=0;i<N;++i){
            long long j;
            cin>>j;
            numbers.push_back(j);
        }
        sort(numbers.begin(),numbers.end());
        long long result=0;
        long long start=0;
        while(start<N && numbers[start]==0){
            start++;
        }
        
        if(start>=3){
            result+=(start*(start-1)*(start-2))/6;
        }
        if(start>=2 && N-start>=1){
            result+=start*(start-1)/2*(N-start);
        }
        for(int i=start;i<N;++i){
            int k=i+2;
            int it=-1;
            for(int j=i+1;j<N;++j){
                if(k==N){break;}
                k=max(k,j+1);
                if(numbers[j]==numbers[j-1] && it>k){
                    result=result+it-k;
                    //cout<<"i "<<i<<" j "<<j<<" "<<it-k<<endl;
                    continue;
                }
                long long product=numbers[i]*numbers[j];
                while(k<N && product>numbers[k]){
                    k++;
                }
                if(k<N && product==numbers[k]){
                    it=k;
                    while(it<N && product==numbers[it]){
                        result++;
                        it++;
                    }
                    //cout<<"i "<<i<<" j "<<j<<" "<<it-k<<endl;
                }
                
            }
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;;
    }
}
