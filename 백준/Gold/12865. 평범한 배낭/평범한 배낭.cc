#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    vector<int> w(n,0);
    vector<int> v(n,0);

    for(int i = 0; i<n; i++){
        cin>>w[i]>>v[i];
    }

    vector<int> dp(k+1,0);
    int ans = 0;
    for(int j = 0; j<n; j++){
        for(int p = k-w[j]; p>=0; p--){
            dp[p+w[j]] = max(dp[p+w[j]],dp[p]+v[j]);
            ans = max(ans,dp[p+w[j]]);
        }
    }
    cout<<ans;
}