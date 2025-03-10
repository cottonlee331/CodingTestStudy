// 백준 11437
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n;
    vector<int> depth(n+1,-1);
    vector<int> parent(n+1,-1);

    vector<vector<int>> adj(n+1,vector<int>());

    depth[1] = 1;
    parent[1] = 0;

    for(int i = 0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<int> stk;
    stk.push(1);
    while(!stk.empty()){
        int curr = stk.top();
        stk.pop();
        for(int k = 0; k<adj[curr].size(); k++){
            if(parent[adj[curr][k]]!=-1){
                continue;
            }
            parent[adj[curr][k]] = curr;
            depth[adj[curr][k]] = depth[curr]+1;
            stk.push(adj[curr][k]);
        }
    }

    cin>>m;
    for(int j = 0; j<m; j++){
        int c, d; 
        cin>>c>>d;
        while(depth[d]<depth[c]){
            c = parent[c];
        }
        while(depth[c]<depth[d]){
            d = parent[d];
        }
        while(c!=d){
            c = parent[c];
            d = parent[d];
        }
        cout<<c<<'\n';
    }

}