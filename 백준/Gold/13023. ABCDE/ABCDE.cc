// 백준 13023

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> frnd;
vector<bool> visited;

int cnt = 0;
int result = 0;

void DFS(int start){
    cnt++;
    if(cnt>=5 || result == 1){
        result = 1;
        return;
    }
    //cout<<start<<" ";
    visited[start] = true;
    for(int i = 0; i<frnd[start].size(); i++){
        if(!visited[frnd[start][i]]){
            DFS(frnd[start][i]);
        }
    }
    visited[start] = false;
    cnt--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    frnd.assign(n,vector<int>());
    visited.assign(n,false);

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        frnd[a].push_back(b);
        frnd[b].push_back(a);
    }

    for(int j = 0; j<n; j++){
        if(result == 1){
            break;
        }
        cnt = 0;
        visited.assign(n,false);
        //cout<<j<<" >> ";
        DFS(j);
        //cout<<endl;
    }
    cout<<result;
}
