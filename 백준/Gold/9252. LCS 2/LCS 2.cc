// 백준 9252

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    string x, y;
    cin>>x>>y;

    vector<vector<int>> dp(x.length(),vector<int>(y.length()));

    int result = 0;

    if(x[0]==y[0]){
        dp[0][0] = 1;
        result = 1;
    }
    else{
        dp[0][0] = 0;
    }

    for(int a = 1; a<x.length(); a++){
        dp[a][0] = dp[a-1][0];
        if(x[a]==y[0]){
            dp[a][0] = 1;
            result = 1;
        }
    }

    for(int b = 1; b<y.length(); b++){
        dp[0][b] = dp[0][b-1];
        if(y[b]==x[0]){
            dp[0][b] = 1;
            result = 1;
        }
    }

    for(int i = 1; i<x.length(); i++){
        for(int j = 1; j<y.length(); j++){
            if(x[i]==y[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            result = max(result,dp[i][j]);
        }
    }

    cout<<result<<'\n';
    char lcs[1001];
    lcs[result] = '\0';
    result--;
    int idx1 = x.length()-1;
    int idx2 = y.length()-1;
    while(result>=0){
        if(x[idx1]==y[idx2]){
            lcs[result] = x[idx1];
            result--;
            idx1--;
            idx2--;
        }
        else if(dp[idx1][idx2]==dp[idx1][idx2-1]){
            idx2--;
        }
        else if(dp[idx1][idx2]==dp[idx1-1][idx2]){
            idx1--;
        }
    }
    cout<<lcs;
}