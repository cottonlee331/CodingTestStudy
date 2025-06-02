#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int n, k;
        cin>>n>>k;
        vector<int> cost(n+1);
        vector<int> dp(n+1);
        vector<int> parent(n+1);
        vector<vector<int>> child(n+1);
        for(int j = 1; j<=n; j++){
            cin>>cost[j];
            dp[j] = cost[j];
        }
        for(int l = 0; l<k; l++){
            int a, b;
            cin>>a>>b;
            parent[b]++;
            child[a].push_back(b);
        }
        queue<int> que;
        vector<int> sorted;
        for(int x = 1; x<=n; x++){
            if(parent[x]==0){
                que.push(x);
            }
        }
        while(!que.empty()){
            int curr = que.front();
            sorted.push_back(curr);
            que.pop();

            for(int z = 0; z<child[curr].size();z++){
                parent[child[curr][z]]--;
                if(parent[child[curr][z]]==0){
                    que.push(child[curr][z]);
                }
            }
        }
        for(int v = 0; v<sorted.size(); v++){
            int curr = sorted[v];
            for(int b = 0; b<child[curr].size(); b++){
                dp[child[curr][b]] = max(dp[curr]+cost[child[curr][b]],dp[child[curr][b]]);
            }
        }
        int w;
        cin>>w;
        cout<<dp[w]<<'\n';
    }
}