#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool solve(int K,vector<pair<int,int>>&intervals, int N, int Q){
    vector<int> available(Q,0);
    for(int i=0;i<Q;i++){
        int start=max(intervals[i].first,available[i]);
        int end=intervals[i].second;
        if(start>end){return false;}
        int booked=0;

        for(int j=i+1;j<Q;j++){
            int l=intervals[j].first;
            int r=intervals[j].second;
            if(l>end){break;}
            if(r<=end){
                if(l>start){
                    int increase=l-start;
                    if(booked+increase>=K){
                        start+=K-booked;
                        booked=K;
                        break;
                    }
                    else{
                        booked+=increase;
                        start=r+1;
                    }
                }
                
                start=max(start,r+1);
            }
        }
        if(booked<K){
            if(end>=start){
                int potential=booked+end-start+1;
                if(potential<K){return false;}
                start=start+K-booked;
            }
            else{return false;}
        }
        for(int j=i+1;j<Q;++j){
            int l=intervals[j].first;
            int r=intervals[j].second;
            if(l>=start){break;}
            if(r>end){
                available[j]=max(available[j],end+1);
            }
        }
    }
    return true;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        int N,Q;
        cin>>N>>Q;
        vector<pair<int,int>> intervals;
        
        for(int i=0;i<Q;++i){
            int l,r;
            cin>>l>>r;
            intervals.push_back({l,r});
        }
        sort(intervals.begin(),intervals.end());
        int low=0;
        int high=N;
        while (low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,intervals,N,Q)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<"Case #"<<tt<<": "<<low-1<<endl;
    }
}
