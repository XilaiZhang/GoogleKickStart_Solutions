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

using namespace std;
vector<int> numbers(10000);
vector<int> seq(10000);

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>numbers[i];
            seq[i]=numbers[i];
        }
        sort(seq.begin(),seq.begin()+N);
        int left=0;
        int right=N-1;

        string result="NO";
        int E=N;
        while(E>1){
            int pivot=floor((E-1)/2);
            //cout<<"pivot is "<<pivot<<" val at pivot is "<<numbers[pivot]<<endl;
            //cout<<"small is "<<seq[left]<<" large is "<<seq[right]<<endl;
            if(numbers[pivot]==seq[left]){
                left++;
                E--;
                for(int j=pivot;j<E;++j){
                    numbers[j]=numbers[j+1];
                }
            }else if(numbers[pivot]==seq[right]){
                right--;
                E--;
                for(int j=pivot;j<E;++j){
                    numbers[j]=numbers[j+1];
                }
            }
            else{
                break;
            } 
        }
        if(E==1){result="YES";}
        cout<<"Case #"<<tt<<": "<<result<<endl;     
    }  
}
