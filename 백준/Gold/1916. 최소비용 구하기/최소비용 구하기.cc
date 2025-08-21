#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>>graph(N+1);
    vector<int> dist(N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i = 0; i<M; i++){
        int st, ed, w;
        cin>>st>>ed>>w;
        graph[st].push_back({ed,w});
    }
    int start, end;
    cin>>start>>end;
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(dist[curr_node]<curr_dist){
            continue;
        }

        for(int j = 0; j<graph[curr_node].size(); j++){
            int next = graph[curr_node][j].first;
            int next_dist = curr_dist+graph[curr_node][j].second;
            if(next_dist<dist[next]){
                dist[next] = next_dist;
                pq.push({next_dist,next});
            }
        }
    }
    cout<<dist[end];
}