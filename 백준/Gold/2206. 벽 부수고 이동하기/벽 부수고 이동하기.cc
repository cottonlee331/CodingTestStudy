#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dirx = {0,0,-1,1};
vector<int> diry = {-1,1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> vec(n,vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char tmp;
            cin>>tmp;
            vec[i][j] = tmp-'0';
        }
    }

    int dist = -1;
    queue<pair<int,int>> bfs;
    bfs.push({0,0});

    while(!bfs.empty()){
        int x = bfs.front().second/10000;
        int y = bfs.front().second%10000;
        int dst = bfs.front().first;
        int currbreak = vec[x][y]/10;
        bfs.pop();

        if(dist!=-1 && dist<dst){
            continue;
        }
        for(int k = 0; k<4; k++){
            if(x+dirx[k]>=0 && x+dirx[k]<n && y+diry[k]>=0 && y+diry[k]<m){
                if(vec[x+dirx[k]][y+diry[k]]==0){
                    bfs.push({dst+1,(x+dirx[k])*10000+(y+diry[k])});
                    if(currbreak==3){
                        vec[x+dirx[k]][y+diry[k]] = 30;
                    }
                    else{
                        vec[x+dirx[k]][y+diry[k]] = 20;
                    }
                }
                else if(vec[x+dirx[k]][y+diry[k]]%10==1 && currbreak!=3){
                    bfs.push({dst+1,(x+dirx[k])*10000+(y+diry[k])});
                    vec[x+dirx[k]][y+diry[k]] = 31;
                }
                else if(vec[x+dirx[k]][y+diry[k]]/10==3 && currbreak == 2){
                    bfs.push({dst+1,(x+dirx[k])*10000+(y+diry[k])});
                    vec[x+dirx[k]][y+diry[k]]/=10;
                    vec[x+dirx[k]][y+diry[k]]+=20;
                }
            }
        }

        if(x == n-1 && y == m-1){
            if(dist == -1){
                dist = dst;
            }
            else{
                dist = min(dist,dst);
            }
        }
    }

    if(dist == -1){
        cout<<dist;
    }
    else{
        cout<<dist+1;
    }
}