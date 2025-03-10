// 백준 14501

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> tvec(n+1);
    vector<int> pvec(n+1);
    vector<int> dp(n+1,0);
    
    for(int i = 1; i<=n; i++){
        int t;
        cin>>t>>pvec[i];
        //i+t-1일까지 
        tvec[i] = i+t-1;
    }
    for(int j = 1; j<=n; j++){
        if(tvec[j]>n){
            continue;
        }
        dp[tvec[j]] = max(dp[j-1]+pvec[j],dp[tvec[j]]);
        for(int k = tvec[j]+1; k<=n; k++){
            dp[k] = max(dp[k],dp[k-1]);
        }
        
    }
    cout<<dp[n];
}