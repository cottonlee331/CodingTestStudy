#include <iostream>
#include <vector>
#define INF 500000
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n; 
    cin>>c>>n;
    
    int ans = INF;
    vector<pair<int,int>> city(n);
    vector<int> dp(100001,INF);
    dp[0] = 0;

    for(int i = 0; i<n; i++){
        int cost, idx;
        cin>>cost>>idx;
        city[i].first = idx;
        city[i].second = cost;

        dp[idx] = min(cost,dp[idx]);
    }

    for(int j = 1; j<100001; j++){
        for(int k = 0; k<city.size(); k++){
            if(j>city[k].first){
                dp[j] = min(dp[j],dp[j-city[k].first]+city[k].second);
            }
        }
        if(j>=c){
            ans = min(ans,dp[j]);
        }
    }

    cout<<ans;
}