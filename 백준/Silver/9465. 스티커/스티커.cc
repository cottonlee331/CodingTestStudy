#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin>>t;
    
    for(int i = 0; i<t; i++){
        cin>>n;
        vector<vector<int>> vec(2,vector<int>(n));
        for(int j = 0; j<2*n; j++){
            cin>>vec[j/n][j%n];
        }
        
        vector<vector<int>> dp(2,vector<int>(n));
        dp[0][0] = vec[0][0];
        dp[1][0] = vec[1][0];
        int mx = max(vec[0][0],vec[1][0]);
        for(int k = 1; k<n; k++){
            dp[0][k] = dp[1][k-1];
            dp[1][k] = dp[0][k-1];
            if(k!=1){
                dp[0][k] = max(dp[0][k],max(dp[0][k-2],dp[1][k-2]));
                dp[1][k] = max(dp[1][k],max(dp[0][k-2],dp[1][k-2]));
            }
            dp[0][k]+=vec[0][k];
            dp[1][k]+=vec[1][k];
            mx = max(mx,max(dp[0][k],dp[1][k]));
        }
        cout<<mx<<'\n';
    }
}