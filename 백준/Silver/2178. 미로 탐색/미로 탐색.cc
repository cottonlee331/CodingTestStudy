#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> mp(n,vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char tmp;
            cin>>tmp;
            mp[i][j]=tmp-'0';
        }
    }

    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> que;
    int min;

    que.push({0,1});
    visited[0][0] = true;

    while(!que.empty()){
        int r = que.front().first/1000;
        int c = que.front().first%1000;
        int dist = que.front().second;

        que.pop();
        if(r==n-1 && c==m-1){
            min = dist;
            break;
        }
        if(r+1<n && mp[r+1][c] && !visited[r+1][c]){
            visited[r+1][c] = true;
            que.push({(r+1)*1000+c,dist+1});
        }
        if(r-1>=0&& mp[r-1][c] && !visited[r-1][c]){
            visited[r-1][c] = true;
            que.push({(r-1)*1000+c,dist+1});
        }
        if(c+1<m && mp[r][c+1] && !visited[r][c+1]){
            visited[r][c+1] = true;
            que.push({r*1000+c+1,dist+1});
        }
        if(c-1>=0 && mp[r][c-1] && !visited[r][c-1]){
            visited[r][c-1] = true;
            que.push({r*1000+c-1,dist+1});
        }
    }
    cout<<min;

}