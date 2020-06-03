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
#include <list>

using namespace std;

struct dummy{
    char first;
    char last;
    vector<int> dict;

    dummy(const string &word){
        vector<int> a (26,0);
        dict=a;
        for(int j=0;j<word.size();j++){
            dict[word[j]-'a']++;
        }
        first=word[0];
        last=word[word.size()-1];
    }

    bool operator==(const dummy & d) const{
        return (first==d.first && last==d.last
            && dict==d.dict);
    }
};

namespace std{
    template<>
    struct hash<dummy>{

        size_t operator()(const dummy & d) const{
            auto ch=hash<char>();
            auto ic=hash<int>();
            size_t uniqueKey=ch(d.first);
            uniqueKey=(uniqueKey<<1) ^ (ch(d.last));
            for(int number:d.dict){
                uniqueKey=(uniqueKey<<1) ^ (ic(number));
            }
            return uniqueKey;
        }
    };
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int L;
        cin>>L;
        unordered_map<dummy,int>lookup;
        unordered_set<int>validLength;
        for(int i=0;i<L;++i){
            string word;
            cin>>word;
            dummy dd=dummy(word);
            lookup[dd]++;
            validLength.insert(word.size());
        }

       
        char S1,S2;
        cin>>S1>>S2;
        int N;
        long long A,B,C,D;
        cin>>N>>A>>B>>C>>D;
        string line="";
        line+=S1;
        line+=S2;
        int X1=S1;
        int X2=S2;
        for(int i=3;i<=N;++i){
            int X3=(A*X2+B*X1+C)%D;
            char S3='a'+(X3 % 26);
            line+=S3;
            X1=X2;
            X2=X3;
        }

        int result=0;
        for(int l:validLength){
            if(l>line.size()){continue;}
            dummy q(line.substr(0,l));
            q.first=line[0];
            q.last=line[l-1];
            
            unordered_map<dummy,int>::iterator it=lookup.find(q);
            if(it!=lookup.end()){
                result+=(it->second);
                lookup.erase(q);
            }
            int left=0;
            int right=l-1;
            for(int start=1;start<=line.size()-l;++start){
                q.dict[line[left]-'a']--;
                left++;
                right++;
                q.dict[line[right]-'a']++;
                
                q.first=line[left];
                q.last=line[right];
               
                it=lookup.find(q);
                if(it!=lookup.end()){
                    result+=(it->second);
                    lookup.erase(q);
                }
            }
        }

        cout<<"Case #"<<tt<<": "<<result<<endl;     
    }  
}
