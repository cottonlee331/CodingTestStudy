#include <iostream>
#include <vector>

#define INF 10

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> dp(n+1,INF);
    dp[0] = 0;
    for(int i = 0; i<n+1; i++){
        for(int j = 1; j*j<=i; j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n];
}