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

using namespace std;
const double eps=1e-8;
double numbers[100];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int M;
        cin>>M;
        for(int i=0;i<=M;++i){
            cin>>numbers[i];
        }
        numbers[0]=-numbers[0];
        double low=-1;
        double high=1;
 
        while(high-low>eps){
            double mid=low+(high-low)/2;
            double p=1;
            double answer=0;
            for(int i=M;i>=0;--i){
                answer+=numbers[i]*p;
                p*=(1+mid);
            }
            if(answer>0){low=mid;}
            else{high=mid;}
        }
        
        cout.precision(10);
        cout<<"Case #"<<tt<<": "<<fixed<<low<<endl;   
    }  
}
