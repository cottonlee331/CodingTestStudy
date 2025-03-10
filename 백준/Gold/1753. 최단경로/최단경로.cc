// 백준 1753

#include<iostream>
#include<vector>
#include<queue>

#define INF 3000001

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v, e, k;
    cin>>v>>e>>k;

    vector<vector<pair<int,int>>> vec(v+1,vector<pair<int,int>>());
    vector<int> dist(v+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(v+1,false);
    for(int i = 0; i<e; i++){
        int a, b, w;
        cin>>a>>b>>w;
        vec[a].push_back(make_pair(b,w));
    }

    dist[k] = 0;
    pq.push(make_pair(0,k));
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node] = true;
        for(int n = 0; n<vec[node].size(); n++){
            dist[vec[node][n].first] = min(dist[vec[node][n].first],dist[node]+vec[node][n].second);
            pq.push(make_pair(dist[vec[node][n].first],vec[node][n].first));
        }

        
    }

    for(int p = 1; p<v+1; p++){
        if(dist[p] == INF){
            cout<<"INF\n";
            continue;
        }
        cout<<dist[p]<<'\n';
    }
}