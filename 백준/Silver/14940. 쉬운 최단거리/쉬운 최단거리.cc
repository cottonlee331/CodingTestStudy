#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> mp(n,vector<int>(m,0));
    queue<pair<int,int>> que;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>mp[i][j];
            if(mp[i][j]==2){
                que.push({i*10000+j,0});
            }
        }
    }

    vector<vector<int>> visited(n,vector<int>(m,INF));
    visited[que.front().first/10000][que.front().first%10000] = 0;

    while(!que.empty()){
        int r = que.front().first/10000;
        int c = que.front().first%10000;
        int dist = que.front().second;
        
        que.pop();
        if(r+1<n && mp[r+1][c] && visited[r+1][c]==INF){
            visited[r+1][c] = dist+1;
            que.push({(r+1)*10000+c,dist+1});
        }
        if(r-1>=0&& mp[r-1][c] && visited[r-1][c]==INF){
            visited[r-1][c] = dist+1;
            que.push({(r-1)*10000+c,dist+1});
        }
        if(c+1<m && mp[r][c+1] && visited[r][c+1]==INF){
            visited[r][c+1] = dist+1;
            que.push({r*10000+c+1,dist+1});
        }
        if(c-1>=0 && mp[r][c-1] && visited[r][c-1]==INF){
            visited[r][c-1] = dist+1;
            que.push({r*10000+c-1,dist+1});
        }
    }

    for(int a = 0; a<n; a++){
        for(int b = 0; b<m; b++){
            if(mp[a][b]==0){
                cout<<0<<' ';
            }
            else if(visited[a][b]==INF){
                cout<<-1<<' ';
            }
            else{
                cout<<visited[a][b]<<' ';
            }
        }
        cout<<'\n';
    }

}