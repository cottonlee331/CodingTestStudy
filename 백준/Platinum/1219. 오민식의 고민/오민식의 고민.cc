// 백준 1219

#include<iostream>
#include<vector>
#include<queue>

#define INF -60000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, start, dest, m;
    cin>>n>>start>>dest>>m;

    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    vector<long long> dist(n,INF);
    vector<int> profit(n,0);
    bool is_cycle = false;


    for(int i = 0; i<m; i++){
        int a, b, fee;
        cin>>a>>b>>fee;
        adj[a].push_back(make_pair(b,fee));
    }
    for(int j = 0; j<n; j++){
        cin>>profit[j];
    }

    dist[start] = profit[start];

    for(int x = 0; x<n; x++){
        for(int y = 0; y<n; y++){
            for(int z = 0; z<adj[y].size(); z++){
                int node = adj[y][z].first;
                int prof = profit[node]-adj[y][z].second;
                if(dist[y]==INF){
                    continue;
                }
                if(dist[node]<dist[y]+prof){
                    dist[node] = dist[y]+prof;
                    if(x == n-1){
                        queue<int> que;
                        vector<bool> visited(n,false);
                        que.push(node);
                        visited[node] = true;
                        while(!que.empty()){
                            if(is_cycle){
                                break;
                            }
                            int nd = que.front();
                            que.pop();
                            for(int l = 0; l<adj[nd].size();l++){
                                if(adj[nd][l].first == dest){
                                    is_cycle = true;
                                    break;
                                }
                                if(!visited[adj[nd][l].first]){
                                    visited[adj[nd][l].first] = true;
                                    que.push(adj[nd][l].first);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(dist[dest]==INF){
        cout<<"gg";
    }
    else if(is_cycle){
        cout<<"Gee";
    }
    else{
        cout<<dist[dest];
    }



}