// 백준 1328

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin>>n>>l>>r;

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(l+1,vector<int>(r+1,0)));

    dp[1][1][1] = 1;

    for(int i = 2; i<n+1; i++){
        for(int j = 1; j<l+1; j++){
            for(int k = 1; k<r+1; k++){
                if(j+k>i+1){
                    continue;
                }
                dp[i][j][k] = ((long long)dp[i-1][j][k]*(i-2) + (long long)dp[i-1][j-1][k] + (long long)dp[i-1][j][k-1])%1000000007;
            }
        }
    }
    cout<<dp[n][l][r];
}