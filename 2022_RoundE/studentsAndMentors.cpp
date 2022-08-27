
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

int main()
{
    int t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        int N;
        cin>>N;
        vector<int> students(N);
        for(int i=0;i<N;++i){
            cin>>students[i];
        }
        string result = "";
        vector<int> sorted_students = students;
        sort(sorted_students.begin(), sorted_students.begin()+N);
        for(int s:students){
            int pos = upper_bound(sorted_students.begin(), sorted_students.begin()+N, 2*s) - sorted_students.begin();
            if(pos == 0){
                result += " -1";
            }else{
                if(sorted_students[pos - 1] == s){
                    if(pos == 1){
                        result += " -1";
                    }else{
                        result += " "+to_string(sorted_students[pos-2]);
                    }
                }else{
                    result += " "+to_string(sorted_students[pos-1]);
                }
            }
        }
        

		printf("Case #%d: %s\n",ca, result.c_str());
	}
	return 0;
}	