#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e18
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<ll, ll>> vec(n);
    vector<vector<ll>> dp(n, vector<ll>(n, INF));

    for(int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    for(int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for(int len = 1; len < n; len++) {
        for(int i = 0; i + len < n; i++) {
            int j = i + len;
            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k+1][j] + vec[i].first * vec[k].second * vec[j].second);
            }
        }
    }

    cout << dp[0][n-1] << '\n';
}
