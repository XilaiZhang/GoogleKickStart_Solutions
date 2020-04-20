#include <iostream>
#include <stdio.h>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
    int trash;
    cin>>trash;
    for (int i=0;i<trash;i++){
        int W,H,L,U,R,D;
        cin>>W>>H>>L>>U>>R>>D;
        unordered_map<int,double> factorial;
        factorial[0]=0;
        double f=0;
        for(int j=1;j<max(U+R,L+D);j++){
            f+=log2(j);
            factorial[j]=f;
        }

        double result=0;

        int x=U-1;
        int y=R+1;
        while(x>0 && y<W){
            int steps=x-1+y-1;
            result+=pow(2,factorial[steps]-factorial[steps-x+1]-factorial[x-1]-steps);
            x--;
            y++;
        }
        if(y==W && x>0){
            for(int t=1;t<x+1;t++){
                int steps=t-1+W-2;
                result+=pow(2,factorial[steps]-factorial[steps-t+1]-factorial[t-1]-steps-1);
            }
        }

        x=D+1;
        y=L-1;

        while(x<H and y>0){
            int steps=x-1+y-1;
            result+=pow(2,factorial[steps]-factorial[steps-x+1]-factorial[x-1]-steps);
            x++;
            y--;
        }
        if(x==H and y>0){
            for(int t=1;t<y+1;t++){
                int steps=H-2+t-1;
                result+=pow(2,factorial[steps]-factorial[steps-t+1]-factorial[t-1]-steps-1);
            }
        }
        cout<<"Case #"<<i+1<<": "<<result<<endl;
    }
}