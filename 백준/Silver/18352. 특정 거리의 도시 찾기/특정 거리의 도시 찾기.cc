// 백준 18352

#include<iostream>
#include<vector>
#include<queue>
#include<deque>

#define INF 300000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, x;
    cin>>n>>m>>k>>x;
    vector<vector<int>> vec(n+1);
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1,0);

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        vec[a].push_back(b);
    }


    int curr;
    int depth = 0;
    deque<int> dq;
    dq.push_back(x);
    visited[x] = true;
    while(depth!=k){
        if(dq.empty()){
            break;
        }
        curr = dq.front();
        dq.pop_front();
        if(dist[curr]!=depth){
            depth++;
        }
        while(!vec[curr].empty()){
            if(!visited[vec[curr].back()]){
                dq.push_back(vec[curr].back());
                visited[vec[curr].back()] = true;
                dist[vec[curr].back()] = depth+1;
            }
            vec[curr].pop_back();
        }
    }

    int cnt = -1;
    for(int d = 1; d<n+1; d++){
        if(dist[d]==k){
            cout<<d<<'\n';
            cnt++;
        }
    }
    if(cnt == -1){
        cout<<cnt;
    }
    
}