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
#include <sstream>

using namespace std;
double W;
double E;
double V[61][61][61]={};
char choice[61][61][61];

int main(){
    int T;
    int X;
    cin>>T;
    cin>>X;

    for(int tt=1;tt<=T;++tt){
        std::fill( &V[0][0][0] , &V[0][0][0]+sizeof(V)/sizeof(double), 0.0);
        cin>>W;
        cin>>E;
        double startVal = 1.0 * W/3 + 1.0*E /3;
        V[0][0][1] = startVal;
        choice[0][0][1]='P';
        V[0][1][0] = startVal;
        choice[0][1][0]='R';
        V[1][0][0] = startVal;
        choice[1][0][0]='S';
        string result = "";
        int maxR = -1;
        int maxS = -1;
        int maxP = -1;
        double maxRoundVal = 0;
        for(int i=2;i<=60;++i){
            for(int s=0;s<=i;++s){
                for(int r=0;r<=i-s;++r){
                    int p=i-s-r;
                    if(p>0){
                        double prev = V[s][r][p-1] + s*1.0/(i-1)*W + r*1.0/(i-1)*E;
                        if (prev > V[s][r][p]){
                            V[s][r][p] = prev;
                            choice[s][r][p] = 'P';
                        }
                    }
                    if(s>0){
                        double prev = V[s-1][r][p] + r*1.0/(i-1)*W + p*1.0/(i-1)*E;
                        if (prev > V[s][r][p]){
                            V[s][r][p] = prev;
                            choice[s][r][p] = 'S';
                        }
                    }
                    if(r>0){
                        double prev = V[s][r-1][p] + p*1.0/(i-1)*W + s*1.0/(i-1)*E;
                        if (prev > V[s][r][p]){
                            V[s][r][p] = prev;
                            choice[s][r][p] = 'R';
                        }
                    }
                    if(i == 60 && V[s][r][p] > maxRoundVal){
                        maxRoundVal = V[s][r][p];
                        maxR = r;
                        maxS = s;
                        maxP = p;
                    }
                }
            }
        }
        int count=60;
        while(count>0){
            char c =choice[maxS][maxR][maxP];
            result += c;
            if(c == 'P'){maxP -= 1;}
            else if(c=='S'){maxS -= 1;}
            else if(c=='R'){maxR -=1;}
            else{cout<<"what is happening"<<endl;}
            count-=1;
        }

        reverse(result.begin(), result.end());
        cout<<"Case #"<<tt<<": "<<result<<"\n";
    }




}


