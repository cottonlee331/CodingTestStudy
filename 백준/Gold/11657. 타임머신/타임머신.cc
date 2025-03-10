// 백준 11657

#include<iostream>
#include<vector>

#define INF 70000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
    vector<long long> dist(n+1,INF);
    bool is_cycle = false;

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        adj[a].push_back(make_pair(b,c));
    }
    dist[1] = 0;
    for(int p = 1; p<n+1; p++){
        for(int j = 1; j<n+1; j++){
            for(int k = 0; k<adj[j].size(); k++){
                int node = adj[j][k].first;
                int weight = adj[j][k].second;
                if(dist[j]==INF){
                    continue;
                }
                if(dist[node]>dist[j]+weight){
                    if(p == n){
                        is_cycle = true;
                    }
                    dist[node] = dist[j]+weight;
                }
            }
        }
    }
    if(is_cycle){
        cout<<-1;
    }
    else{
        for(int q = 2; q<n+1; q++){
            if(dist[q]==INF){
                cout<<-1<<'\n';
                continue;
            }
            cout<<dist[q]<<'\n';
        }
    }
}