// 백준 1033

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int GCD(int a, int b){
    int gcd, tmp;
    int n = max(a,b);
    int m = min(a,b);
    while(true){
        if(n*m == 0){
            gcd = n+m;
            break;
        }
        tmp = n%m;
        n = m;
        m = tmp;
    }
    return gcd;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, tmp;
    cin>>n;

    vector<int> vec(n,1);
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++){
        int a, b, p, q;
        cin>>a>>b>>p>>q;
        int gcd = GCD(p,q);
        p = vec[b]*p/gcd;
        q = vec[a]*q/gcd;
        vector<bool> visited(n,false);
        queue<int> que;
        int curr;

        que.push(a);
        visited[a] = true;

        while(!que.empty()){
            curr = que.front();
            que.pop();
            vec[curr]*=p;
            for(int j = 0; j<adj[curr].size(); j++){
                if(!visited[adj[curr][j]]){
                    visited[adj[curr][j]] = true;
                    que.push(adj[curr][j]);
                }
            }
        }
        visited.assign(n,false);
        que.push(b);
        visited[b] = true;
        while(!que.empty()){
            curr = que.front();
            que.pop();
            vec[curr]*=q;
            for(int j = 0; j<adj[curr].size(); j++){
                if(!visited[adj[curr][j]]){
                    visited[adj[curr][j]] = true;
                    que.push(adj[curr][j]);
                }
            }
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int gcd = vec[0]; 
    for(int u = 1; u<n; u++){
        gcd = GCD(vec[u],gcd);
    }

    for(int k = 0; k<n; k++){
        cout<<vec[k]/gcd<<' ';
    }
}