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
int N;
double X[10001];
double Y[10001];
double W[10001];
const double eps=1e-7;

double weight(double x, double y){
    double answer=0;
    for(int i=1;i<=N;++i){
        answer+=max(fabs(x-X[i]),fabs(y-Y[i]))*W[i];
    }
    return answer;
}

double compute(double x){
    double low=-1000;
    double high=1000;
    while(high-low>eps){
        double p1=low+(high-low)/3;
        double p2=low+(high-low)*2/3;
        if(weight(x,p1)<weight(x,p2)){
            high=p2;
        }else{low=p1;}
    }
    return weight(x,low);
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        for(int j=1;j<=N;++j){
            cin>>X[j];
            cin>>Y[j];
            cin>>W[j];
        }
        double low=-1000;
        double high=1000;
        while(high-low>eps){
            double p1=low+(high-low)/3;
            double p2=low+(high-low)*2/3;
            if(compute(p1)<compute(p2)){
                high=p2;
            }else{low=p1;}
        }
        double result=compute(low);
        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<result<<endl;   
    }  
}
