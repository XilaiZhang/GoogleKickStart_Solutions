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

typedef long long ll;
int N,K,X,D;

int update_meetings(multiset<int> & k_smallest_meetings, multiset<int> & other_meetings, int old_meeting_count, int new_meeting_count, int sum_of_k_smallest_meetings){
    int new_sum_k_smallest_meetings = sum_of_k_smallest_meetings;
    if (!k_smallest_meetings.empty() && (*(k_smallest_meetings.rbegin()) >= old_meeting_count)){
        k_smallest_meetings.erase (k_smallest_meetings.find(old_meeting_count));
        new_sum_k_smallest_meetings -= old_meeting_count;
    }
    else{
        other_meetings.erase (other_meetings.find(old_meeting_count));
    } 

    k_smallest_meetings.insert(new_meeting_count);
	new_sum_k_smallest_meetings += new_meeting_count;
	if (k_smallest_meetings.size() > K) {
        auto it = k_smallest_meetings.rbegin();
        new_sum_k_smallest_meetings -= *it;
        other_meetings.insert (*it);
        k_smallest_meetings.erase(next(it).base());
    }
	if (!k_smallest_meetings.empty() && !other_meetings.empty() && (*k_smallest_meetings.rbegin() > *other_meetings.begin())) {
        int biggest_from_small_heap = *k_smallest_meetings.rbegin();
        int smallest_from_big_heap = *other_meetings.begin();
        k_smallest_meetings.erase(next(k_smallest_meetings.rbegin()).base());
        other_meetings.erase(other_meetings.begin());
        k_smallest_meetings.insert (smallest_from_big_heap);
        other_meetings.insert (biggest_from_small_heap);
        new_sum_k_smallest_meetings = new_sum_k_smallest_meetings - biggest_from_small_heap + smallest_from_big_heap;
    }
    return new_sum_k_smallest_meetings;
}

int main()
{
    int t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        cin>>N>>K>>X>>D;
        int M;
        cin>>M;
        vector<vector<int>> begin_event(3*D, vector<int>());
        vector<vector<int>> end_event(3*D, vector<int>());
        for(int i=0;i<M;++i){
            int P, L, R;
            cin>>P>>L>>R;
            //       L    R
            // L-X---L    R------R+X     
            begin_event[max(L-X+1, 0)].push_back(P);
            end_event[R].push_back(P);
        }
        vector<int> tech_lead_meeting_count(N+1, 0);
        multiset<int> k_smallest_meetings;
        for(int i=0;i<K;++i){
            k_smallest_meetings.insert(0);
        }
        multiset<int> other_meetings;
        if(N>K){
            for(int i = 0;i<N-K;++i){
                other_meetings.insert(0);
            }
        }
        int sum_of_k_smallest_meetings = 0;
        long long result = INT_MAX;

        for(int start_time = 0; start_time <= D-X; ++start_time){
            for(int tech_lead_begin : begin_event[start_time]){
                int current_meeting_count = tech_lead_meeting_count[tech_lead_begin];
                sum_of_k_smallest_meetings = update_meetings(k_smallest_meetings, other_meetings, current_meeting_count, current_meeting_count+1, sum_of_k_smallest_meetings);
                tech_lead_meeting_count[tech_lead_begin] ++;
            }
            for(int tech_lead_end : end_event[start_time]){
                int current_meeting_count = tech_lead_meeting_count[tech_lead_end];
                sum_of_k_smallest_meetings = update_meetings(k_smallest_meetings, other_meetings, current_meeting_count, current_meeting_count-1, sum_of_k_smallest_meetings);
                tech_lead_meeting_count[tech_lead_end] --;
            }
            result = min(result, (ll)sum_of_k_smallest_meetings);
        }
		printf("Case #%d: %lld\n",ca, result);
	}
	return 0;
}	