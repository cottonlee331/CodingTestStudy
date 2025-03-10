// 백준 1854

//2%

#include<iostream>
#include<vector>
#include<queue>

#define INF 3000000001
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>> vec(n+1,vector<pair<int,int>>());
    vector<priority_queue<ll>> dist(n+1);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
    }

    dist[1].push(0);
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        int node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        for(int p = 0; p<vec[node].size(); p++){
            int new_dist = cost+vec[node][p].second;
            int to_node = vec[node][p].first;

            if(dist[to_node].size()==k){
                if(dist[to_node].top()>new_dist){
                    dist[to_node].pop();
                    dist[to_node].push(new_dist);
                    pq.push(make_pair(new_dist,to_node));
                }
            }
            else{
                dist[to_node].push(new_dist);
                pq.push(make_pair(new_dist,to_node));
            }
        }
    }
    for(int j = 1; j<n+1; j++){
        if(dist[j].size()<k){
            cout<<"-1\n";
        }
        else{
            cout<<dist[j].top()<<'\n';
        }
    }
}