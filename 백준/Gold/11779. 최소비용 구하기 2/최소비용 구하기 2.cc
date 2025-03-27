#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 2000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> bus(n+1,vector<pair<int,int>>());

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        bus[a].push_back({c,b});
    }
    int start, end;
    cin>>start>>end;
    vector<int> dist(n+1,INF);
    vector<int> pre(n+1,INF);
    vector<bool> visited(n+1,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int curr, w;
        curr = pq.top().second;
        w = pq.top().first;

        if(!visited[curr]){
            visited[curr] = true;
            for(int i = 0; i<bus[curr].size(); i++){
                int nxt = bus[curr][i].second;
                int dst = bus[curr][i].first;
                if(dist[nxt]>w+dst){
                    dist[nxt] = w+dst;
                    pre[nxt] = curr;
                    pq.push({dist[nxt],nxt});
                }
            }
        }
        pq.pop();
    }

    stack<int> stk;
    int cnt = 1;
    stk.push(end);

    while(stk.top()!=start){
        cnt++;
        stk.push(pre[stk.top()]);
    }
    cout<<dist[end]<<'\n'<<cnt<<'\n';

    while(!stk.empty()){
        cout<<stk.top()<<' ';
        stk.pop();
    }

}