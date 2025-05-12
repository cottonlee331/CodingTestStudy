#include <iostream>
#include <vector>

#define INF 250000000

using namespace std;
int n, m, w;

vector<vector<pair<int,int>>> graph;
vector<int> dist;
vector<bool> visited;

bool BellmanFord(int start){
    dist.assign(n+1,INF);
    dist[start] = 0;
    visited[start] = true;

    for(int i = 1; i<n+1; i++){
        for(int j = 0; j<graph.size(); j++){
            for(int k = 0; k<graph[j].size(); k++){
                int to = graph[j][k].first;
                int cost = graph[j][k].second;
                if(dist[j]==INF){
                    continue;
                }
                if(dist[to]>dist[j]+cost){
                    dist[to] = dist[j]+cost;
                    visited[to] = true;
                }
            }
        }
    }

     for(int j = 0; j<graph.size(); j++){
        for(int k = 0; k<graph[j].size(); k++){
            int to = graph[j][k].first;
            int cost = graph[j][k].second;
            if(dist[j]==INF){
                continue;
            }
            if(dist[to]>dist[j]+cost){
                return false;
            }
        }
    }
    return true;
}

void WormHole(){
    graph.clear();
    visited.clear();

    bool result = false;
    cin>>n>>m>>w;
    graph.assign(n+1,vector<pair<int,int>>());
    visited.assign(n+1,false);
    for(int i = 0; i<m; i++){
        int s, e, t;
        cin>>s>>e>>t;
        graph[s].push_back({e,t});
        graph[e].push_back({s,t});
    }
    for(int j = 0; j<w; j++){
        int s, e, t;
        cin>>s>>e>>t;
        graph[s].push_back({e,(-1)*t});
    }

    for(int k = 1; k<n+1; k++){
        if(visited[k]){
            continue;
        }
        result = BellmanFord(k);
        if(!result){
            break;
        }
    }

    if(!result){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;
    for(int a = 0; a<tc; a++){
        WormHole();
    }
}