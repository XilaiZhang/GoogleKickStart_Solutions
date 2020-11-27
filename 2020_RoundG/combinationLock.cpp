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

long long W,N;

int bSearch(vector<long long>& numbers, int pivot){
    long long refVal = numbers[pivot];
    long long low = 0;
    long long high= pivot;
    
    while(low<high){
        long long mid= low+(high-low)/2; 
        long long upDiff= refVal-numbers[mid];
        long long downDiff= numbers[mid]+N-refVal;
        if(upDiff<downDiff){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;

}

int bSearchRight(vector<long long>& numbers, int pivot){
    long long refVal = numbers[pivot];
    long long low = pivot+1;
    long long high= W;
    
    while(low<high){
        long long mid= low+(high-low)/2; 
        long long downDiff= numbers[mid]-refVal;
        long long upDiff= refVal + N-numbers[mid];
        
        if(upDiff<downDiff){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;

}

int main(){
    int T;
    cin>>T;
    long long Xi;

    for(int tt=1;tt<T+1;++tt){  
        long long r=1e15;
        cin>>W>>N;
        vector<long long> numbers(W);
        for(int i=0;i<W;++i){
            cin>>Xi;
            numbers[i]= Xi;
        }

        sort(numbers.begin(),numbers.end());
        //for(int x:numbers){cout<<" "<<x;}cout<<endl;
        vector<long long> prefix={0};
        for(int i=0;i<W;++i){
            prefix.push_back(prefix[prefix.size()-1]+numbers[i]);
        }
        //for(int x:prefix){cout<<" "<<x;}cout<<endl;
        for(int pivot=0; pivot<W; ++pivot){
            //cout<<"pivot is "<<pivot<<endl;
            long long result=0;
            long long refVal = numbers[pivot];
            int index= bSearch(numbers,pivot);
            //cout<<"index is "<<index<<endl;
            if(index-1>=0){
                long long quantity= index;
                result+= (N-refVal)*index + prefix[index];
            }
            if(index<=pivot){
                long long quantity= pivot-index+1;
                result+= refVal*quantity - (prefix[pivot+1] - prefix[index]);
            }
            //cout<<"sum of left part is "<<result<<endl;

            index=bSearchRight(numbers,pivot);
            //cout<<"index2 is "<<index<<endl;
            if(index-1 >= pivot+1){
                long long quantity= index-pivot-1;
                result += prefix[index]- prefix[pivot+1] -quantity*refVal;
            }
            if(index<= W-1){
                long long quantity= W-index;
                result+= (N + refVal) *quantity - (prefix[W] - prefix[index]);
            }
            //cout<<"result is "<<result<<endl;
            r=min(r,result);
        }
        
        cout<<"Case #"<<tt<<": "<<r<<"\n";    
    }
}
