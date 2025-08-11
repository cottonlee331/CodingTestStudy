#include<iostream>
#include<vector>
#include<cmath>

#define INF 160000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> W(n,vector<int>(n,0));
    vector<int> pw(n,0);
    vector<vector<int>> dp(n,vector<int>(pow(2,n),INF));
    for(int i = 0; i<n; i++){
        pw[i] = pow(2,i);
        for(int j = 0; j<n; j++){
            cin>>W[i][j];
            if(i!=j && W[i][j]==0){
                W[i][j] = INF;
            }

        }
    }

    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int c = 0; c<dp[0].size(); c++){
        for(int a = 0; a<n; a++){   // 경유지
            for(int b = 1; b<n; b++){   // 도착지
                if(pw[a]&c && pw[b]&c){
                    dp[b][c] = min(dp[b][c],dp[a][c-(1<<b)]+W[a][b]);
                }
            }
        }
    }
    
    for(int d = 0; d<dp[0].size(); d++){
            for(int e = 1; e<n;e++){
                if(1&d && d&pw[e]){
                    dp[0][d] = min(dp[0][d],dp[e][d]+W[e][0]);
                }
            }
    }
    cout<<dp[0][(1<<n)-1];
}