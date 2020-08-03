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

int main(){
    int T;
    cin>>T;
    int R,C,K;
    int Ri,Ci;

    for(int tt=1;tt<T+1;++tt){
        cin>>R>>C>>K;
        vector<vector<int>> grid(R,vector<int>(C,0));
        for(int i=0;i<K;++i){
            cin>>Ri>>Ci;
            grid[Ri][Ci]=1;
        }
        vector<vector<int>> maxL(R,vector<int>(C,0));
        long long result=0;
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                if(grid[i][j]==1){maxL[i][j]=0;continue;}
                if(i==0 || j==0){maxL[i][j]=1;result++;continue;}
                int l=min(maxL[i-1][j],min(maxL[i][j-1],maxL[i-1][j-1]));
                maxL[i][j]=l+1;
                result+=l+1;
            }
        }

        cout<<"Case #"<<tt<<": "<<result<<endl; 
    }
}
