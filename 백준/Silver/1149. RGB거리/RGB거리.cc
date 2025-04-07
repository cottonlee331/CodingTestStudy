#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> rgb(n,vector<int>(3,0));
    vector<vector<int>> dp(n,vector<int>(3,0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin>>rgb[i][j];
        }
    }

    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];

    for(int a = 1; a<n; a++){
        dp[a][0] = min(dp[a-1][1],dp[a-1][2])+rgb[a][0];
        dp[a][1] = min(dp[a-1][0],dp[a-1][2])+rgb[a][1];
        dp[a][2] = min(dp[a-1][0],dp[a-1][1])+rgb[a][2];
    }
    
    int ans = min(dp[n-1][0],dp[n-1][1]);
    ans = min(ans,dp[n-1][2]);
    cout<<ans;
}