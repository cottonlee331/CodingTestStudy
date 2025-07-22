#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dr = {1,-1,0,0};
vector<int> dc = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    for(int i = 0; i<t; i++){
        int m, n,k; 
        cin>>m>>n>>k;
        vector<vector<int>> vec(n, vector<int>(m,0));
        vector<vector<bool>> visit(n, vector<bool>(m,false));
        for(int j = 0; j<k; j++){
            int a, b;
            cin>>a>>b;
            vec[b][a] = 1;
        }

        int ans = 0;
        for (int rr = 0; rr < n; rr++) {
                for (int cc = 0; cc < m; cc++) {
                    if (vec[rr][cc] == 1 && !visit[rr][cc]) {
                        stack<pair<int,int>> stk;
                        stk.push({rr,cc});
                        visit[rr][cc] = true;
                        while(!stk.empty()){
                            int row = stk.top().first;
                            int col = stk.top().second;
                            stk.pop();
                            for(int u = 0; u<4; u++){
                                int r = row+dr[u];
                                int c = col+dc[u];
                                if(0<=r && 0<=c && r<n && c<m && vec[r][c]==1 && !visit[r][c]){
                                    visit[r][c] = true;
                                    stk.push({r,c});
                                }
                            }
                        }
                        ans++;
                    }
                }
            }

        cout<<ans<<'\n';
    }
}