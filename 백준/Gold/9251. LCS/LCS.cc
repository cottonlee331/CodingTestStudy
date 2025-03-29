#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str1,str2;
    cin>>str1>>str2;

    vector<vector<int>> dp(str2.size(),vector<int>(str1.size(),0));
    int ans = 0;

    if(str1[0]==str2[0]){
        dp[0][0] = 1;
        ans++;
    }

    for(int a = 1; a<str2.size(); a++){
        if(str2[a]==str1[0]){
            dp[a][0] = 1;
            ans = 1;
        }
        else{
            dp[a][0] = dp[a-1][0];
        }
    }

    for(int b = 0; b<str1.size(); b++){
        if(str1[b]==str2[0]){
            dp[0][b] = 1;
            ans = 1;
        }
        else{
            dp[0][b] = dp[0][b-1];
        }
    }

    for(int i = 1; i<str2.size(); i++){
        for(int j = 1; j<str1.size();j++){
            if(str2[i]==str1[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans;
}