#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>());
    int mx = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            int tmp;
            cin>>tmp;
            dp[i].push_back(tmp);
            if(i == 0){
                mx = tmp;
                continue;
            }
            if(j==0){
                dp[i][j] +=dp[i-1][0];
            }
            else if(j==i){
                dp[i][j] +=dp[i-1][j-1];
            }
            else{
                dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
            }
            mx = max(dp[i][j],mx);
        }
    }
    cout<<mx;
}