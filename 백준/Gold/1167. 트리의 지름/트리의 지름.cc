// 백준 1167

#include<iostream>
#include<vector>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> visited;

int max_len = 0;
int len = 0;
int node;

void DFS(int start){
    visited[start] = true;
    if(len>max_len){
        max_len = len;
        node = start;
    }
    for(int i = 0; i<adj[start].size();i++){
        if(!visited[adj[start][i].first]){
            len+=adj[start][i].second;
            DFS(adj[start][i].first);
            len-=adj[start][i].second;
        }
    }
    visited[start] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v;
    cin>>v;

    adj.assign(v+1,vector<pair<int,int>>());
    visited.assign(v+1,false);

    for(int i = 1; i<=v; i++){
        int a, tmp;
        cin>>a>>tmp;
        while(tmp!=-1){
            int leng;
            cin>>leng;
            adj[a].push_back(make_pair(tmp,leng));
            //adj[tmp].push_back(make_pair(a,len));
            cin>>tmp;
        }
    }
    DFS(1);
    visited.assign(v+1,false);
    DFS(node);
    cout<<max_len;
}