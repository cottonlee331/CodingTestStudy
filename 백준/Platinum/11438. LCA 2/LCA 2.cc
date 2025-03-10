// 백준 11438

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n;
    int max_log = log2(n)+1;
    vector<int> depth(n+1,-1);
    vector<vector<int>> parent(n+1,vector<int>(max_log,0));

    vector<vector<int>> adj(n+1,vector<int>());

    for(int i = 0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        parent[i].push_back(0);
    }
    parent[n-1].push_back(0);
    parent[n].push_back(0);

    depth[1] = 1;
    parent[1][0] = 0; 

    stack<int> stk;
    stk.push(1);
    while(!stk.empty()){
        int curr = stk.top();
        stk.pop();
        for(int k = 0; k<adj[curr].size(); k++){
            int next = adj[curr][k];
            if(parent[next][0]!=0 || next == 1){
                continue;
            }
            parent[next][0] = curr;
            depth[next] = depth[curr]+1;
            stk.push(next);
            for (int j = 1; j<=max_log; j++){
                parent[next][j] = parent[parent[next][j-1]][j-1];
            }
        }
    }

    cin>>m;
    for(int j = 0; j<m; j++){
        int c, d;
        cin>>c>>d;
        if(depth[c]<depth[d]){
            swap(c,d);
        }
        if(depth[c]!=depth[d]){
            for(int k = max_log; k>=0; k--){
                if(depth[parent[c][k]]>=depth[d]){
                    c = parent[c][k];
                }
            }
        }
        int lca = c;
        if(c!=d){
            for(int i = max_log; i>=0; i--){
                if(parent[c][i] != parent[d][i]){
                    c = parent[c][i];
                    d = parent[d][i];
                }
                lca = parent[c][i];
            }
        }
        cout<<lca<<'\n';
    }
}