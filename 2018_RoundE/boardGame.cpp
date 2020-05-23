#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <cstring>

using namespace std;

int hu[15];
int N;
vector<vector<int>> huLong;
vector<vector<int>> laLong;
int numberTwo[3005];
int numberThree[3005];
int quantityThree[3005];
int twoDTree[3005][3005];
int sumToPos[5000001]; //sumTwoPos and sumThreePos are the same
int idToSix[756780];

void dfs(int startIndex, int oneCount, int twoCount, int threeCount, 
    int oneSum, int twoSum, int threeSum){
    //cout<<startIndex<<" "<<oneCount<<" "<<twoCount<<" "<<threeCount<<" "<<total.size()<<" stuck? "<<endl;
    if(startIndex==3*N){
        int id=huLong.size();
        huLong.push_back({oneSum,twoSum,threeSum,id});
        return;
    }
    if(oneCount<N){
        dfs(startIndex+1,oneCount+1,twoCount,threeCount,oneSum+hu[startIndex],twoSum,threeSum);
    }
    if(twoCount<N){
        dfs(startIndex+1,oneCount,twoCount+1,threeCount,oneSum,twoSum+hu[startIndex],threeSum);
    }
    if(threeCount<N){
        dfs(startIndex+1,oneCount,twoCount,threeCount+1,oneSum,twoSum,threeSum+hu[startIndex]);
    }

}

void dfs2(int startIndex, int oneCount, int twoCount, int threeCount, 
    int oneSum, int twoSum, int threeSum){
    //cout<<startIndex<<" "<<oneCount<<" "<<twoCount<<" "<<threeCount<<" "<<total.size()<<" stuck? "<<endl;
    if(startIndex==3*N){
        laLong.push_back({oneSum,twoSum,threeSum});
        return;
    }
    if(oneCount<N){
        dfs2(startIndex+1,oneCount+1,twoCount,threeCount,oneSum+hu[startIndex],twoSum,threeSum);
    }
    if(twoCount<N){
        dfs2(startIndex+1,oneCount,twoCount+1,threeCount,oneSum,twoSum+hu[startIndex],threeSum);
    }
    if(threeCount<N){
        dfs2(startIndex+1,oneCount,twoCount,threeCount+1,oneSum,twoSum,threeSum+hu[startIndex]);
    }

}
// diff is always 1 in this case
void update(int* tree, int place, int N){
    while(place<=N){
        tree[place]+=1;
        place=place+(place &(-place));
    }
}

int query(int* tree, int place){
    int answer=0;
    while(place>0){
        answer+=tree[place];
        place=place-(place & ( -place ));
    }
    return answer;
}

void twoDUpdate(int twoDTree[3005][3005], int row, int col, int m, int n){
    for(int i=row;i<=m;i=i+(i&(-i)) ){
        for(int j=col;j<=n;j=j+(j& (-j) ) ){
            twoDTree[i][j]+=1;
        }
    }
}

int twoDQuery(int twoDTree[3005][3005], int row, int col){
    int answer=0;
    for(int i=row;i>0;i=i-(i&(-i))){
        for(int j=col;j>0;j=j-(j&(-j))){
            answer+=twoDTree[i][j];
        }
    }
    return answer;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        memset(hu,0,sizeof hu);
        huLong.clear();
        laLong.clear();
        
        for(int i=0;i<3*N;++i){cin>>hu[i];} 
        dfs(0, 0,0,0,0,0,0);
        //let's put la also in the hu array
        memset(hu,0,sizeof hu);
        for(int i=0;i<3*N;++i){cin>>hu[i];}
        dfs2(0, 0,0,0,0,0,0);
        
        memset(sumToPos,0,sizeof sumToPos);
        
        memset(numberTwo,0,sizeof numberTwo);
        memset(numberThree,0,sizeof numberThree);
        memset(twoDTree,0, sizeof twoDTree);

        memset(idToSix,0,sizeof idToSix);
        sort(huLong.begin(),huLong.end(),
            [](const vector<int>&a,const vector<int>& b){
                return a[1]<b[1];
            });
        sort(laLong.begin(),laLong.end(),
            [](const vector<int>&a,const vector<int>& b){
                return a[1]<b[1];
            });
        int m=0;
        int prev=-1;
        for(int i=0;i<laLong.size();++i){
            if(laLong[i][1]!=prev){
                sumToPos[laLong[i][1]]=m+1;
                prev=laLong[i][1];
                ++m;
            }
        }
        int fill=0;
        int tmp=0;
        for(int i=0;i<5000001;i++){
            tmp=sumToPos[i];
            sumToPos[i]=fill;
            if(tmp!=0){
                fill=tmp;
            }
        }
        
        memset(quantityThree, 0, sizeof quantityThree); //previous 1000001 might not be enough
        int laPointer=0;
        for(int huIndex=0;huIndex<huLong.size();++huIndex){
            while(laPointer!=laLong.size() && huLong[huIndex][1]>laLong[laPointer][1]){
                update(quantityThree, sumToPos[laLong[laPointer][2]]+1, m);
                laPointer++;
            }
            int twoAndThree=query(quantityThree, sumToPos[huLong[huIndex][2]]);
            idToSix[huLong[huIndex][3]]=twoAndThree;
        }

        sort(huLong.begin(),huLong.end(),
            [](const vector<int>&a,const vector<int>& b){
                return a[0]<b[0];
            });
        sort(laLong.begin(),laLong.end(),
            [](const vector<int>&a,const vector<int>& b){
                return a[0]<b[0];
            });
        int maxWin=0;

        int laIndex=0;
        for(int huIndex=0; huIndex<huLong.size(); ++huIndex){
            while(laIndex!=laLong.size() && huLong[huIndex][0]>laLong[laIndex][0]){
                update(numberTwo, sumToPos[laLong[laIndex][1]]+1, m);
                update(numberThree, sumToPos[laLong[laIndex][2]]+1, m);
                twoDUpdate(twoDTree, sumToPos[laLong[laIndex][1]]+1, sumToPos[laLong[laIndex][2]]+1, m, m);
                laIndex++;
            }
            int p23=idToSix[huLong[huIndex][3]];
            
            int p12=query(numberTwo, sumToPos[huLong[huIndex][1]]);
            int p13=query(numberThree,sumToPos[huLong[huIndex][2]]);
            //cout<<p12<<" "<<p13<<" "<<p23<<endl;
            int p123=twoDQuery(twoDTree, sumToPos[huLong[huIndex][1]], sumToPos[huLong[huIndex][2]]);//rethink about index
            maxWin=max(maxWin,p12+p13+p23-2*p123);
        }

        double rate=double(maxWin)/laLong.size();
        
        cout<<"Case #"<<tt<<": "<<rate<<endl;;
    }
}
