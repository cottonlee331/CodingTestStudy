#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10000000

using namespace std;

vector<int> dirx = {-1,1,0,0};
vector<int> diry = {0,0,-1,1};

int dijikstra(int n, vector<vector<int>> &vec){
    vector<vector<int>> dist(n,vector<int>(n,INF));
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nodes;

    dist[0][0] = vec[0][0];
    nodes.push(make_pair(dist[0][0],0));

    while(!nodes.empty()){
        int x = nodes.top().second/1000;
        int y = nodes.top().second%1000;
        if(visited[x][y]){
            nodes.pop();
            continue;
        }
        int dst = nodes.top().first;
        nodes.pop();
        visited[x][y] = true;
        for(int i = 0; i<dirx.size(); i++){
            if(x+dirx[i]<0 || x+dirx[i]>=n || y+diry[i]<0 || y+diry[i]>=n){
                continue;
            }
            else if(visited[x+dirx[i]][y+diry[i]]){
                continue;
            }
            dist[x+dirx[i]][y+diry[i]] = min(dist[x+dirx[i]][y+diry[i]],dst+vec[x+dirx[i]][y+diry[i]]);
            nodes.push(make_pair(dist[x+dirx[i]][y+diry[i]],(x+dirx[i])*1000+(y+diry[i])));
        }
    }

    return dist[n-1][n-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0;
    while(true){
        cnt++;
        int n = 0;
        cin>>n;
        if(n==0){
            break;
        }
        vector<vector<int>> vec(n,vector<int>(n,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>vec[i][j];
            }
        }
        cout<<"Problem "<<cnt<<": "<<dijikstra(n,vec)<<'\n';
    }

}