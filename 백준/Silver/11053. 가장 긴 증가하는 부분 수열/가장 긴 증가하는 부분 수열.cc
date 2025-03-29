#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int> vec(n,0);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    vector<int> dp(n,1);
    int ans = 1;
    for(int j = 1; j<n; j++){
        for(int k = 0; k<j; k++){
            if(vec[k]<vec[j]){
                dp[j] = max(dp[j],dp[k]+1);
                ans = max(ans,dp[j]);
            }
        }
    }
    cout<<ans;
}