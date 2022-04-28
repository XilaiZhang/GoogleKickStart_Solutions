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
int R,C;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string dir[4] = {"S","E","N","W"};

int main(){
    int T;
    cin>>T;
    
    for(int tt=1;tt<T+1;++tt){  
        cin>>R>>C;
        int placeCount = 0;
        vector<string> grid;
        cin.ignore();
        for(int i=0;i<R;++i){
            string line;
            for(int j=0;j<C;++j){
                char single;
                cin>>single;
                if(single == '*'){
                    placeCount ++;
                }
                line += single;
            }
            grid.push_back(line);
        }
        
        vector<vector<int>> ans = vector<vector<int>>(2*R, vector<int>(2*C, -1));
        vector<vector<int>> seen = vector<vector<int>>(R, vector<int>(C, -1));
        vector<vector<int>> stack;
        stack.push_back({0,0,-1});
        while (!stack.empty()){
            vector<int> current = stack.back();
            stack.pop_back();

            int bigX = current[0];
            int bigY = current[1];
            int ancestorDirection = current[2];  

            if(bigX >= R || bigX<0 || bigY >= C || bigY < 0 || (grid[bigX][bigY] == '#') || seen[bigX][bigY]!=-1){
                continue;
            }
            placeCount -- ;

            seen[bigX][bigY] = 1;
            int p1x, p1y,p2x, p2y;
            p1x = 2*bigX;
            p1y = 2*bigY;
            p2x = 2*bigX+1;
            p2y = 2*bigY+1;
            ans[p1x][p1y] = 0;
            ans[p2x][p1y] = 1;
            ans[p2x][p2y] = 2;
            ans[p1x][p2y] = 3;

            if (!(bigX ==0 && bigY == 0)){
                int a1x, a1y,a2x, a2y;
                int ancestorX = bigX +dx[ancestorDirection];
                int ancestorY = bigY + dy[ancestorDirection];
                a1x = 2*ancestorX;
                a1y = 2*ancestorY;
                a2x = 2*ancestorX+1;
                a2y = 2*ancestorY+1;

                if(ancestorDirection == 0){
                    ans[a1x][a2y] = 2;
                    ans[p2x][p1y] = 0;
                }

                else if(ancestorDirection == 1){
                    ans[a1x][a1y] = 3;
                    ans[p2x][p2y] = 1;
                }

                else if(ancestorDirection == 2){
                    ans[a2x][a1y] = 0;
                    ans[p1x][p2y] = 2;
                }

                else if(ancestorDirection == 3){
                    ans[a2x][a2y] = 1;
                    ans[p1x][p1y] = 3;
                }

            }

            for(int i=0;i<4;++i){
                int newX, newY;
                newX = bigX + dx[i];
                newY = bigY +dy[i];
                stack.push_back({newX, newY, (i+2)%4});
            }

        }
        if(placeCount > 0){
          cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<"\n";  
          continue;
        }

        string res = "S";
        int cx = 1;
        int cy = 0;
        while(!(cx == 0 && cy==0)){
            res+= dir[ans[cx][cy]];
            int cxNew = cx + dx[ans[cx][cy]];
            int cyNew = cy + dy[ans[cx][cy]];
            cx = cxNew;
            cy = cyNew;
        }

        cout<<"Case #"<<tt<<": "<<res<<"\n";    
    }
}

