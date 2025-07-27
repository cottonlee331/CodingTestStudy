#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000000000

using namespace std;

bool BitCheck(int num, int n){
    return (num&(1<<n));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(10,vector<ll>(1024,0)));
    vector<int> pw(10);
    pw[0] = 1;
    for(int i = 1; i<10; i++){
        pw[i] = pw[i-1]<<1;
        dp[1][i][pw[i]] = 1;
    }
    for(int j = 2; j<n+1; j++){ // 자릿수
        for(int k = 0; k<10; k++){   // 끝자리
            for(int p = 1; p<1024; p++){    // 비트마스킹
                if(!BitCheck(p,k)){
                    continue;
                }
                if(k==0){
                    dp[j][k][p] = (dp[j-1][k+1][p]+dp[j-1][k+1][p-pw[k]])%MOD;
                }
                else if(k==9){
                    dp[j][k][p] = (dp[j-1][k-1][p]+dp[j-1][k-1][p-pw[k]])%MOD;
                }
                else{
                    dp[j][k][p] = (dp[j-1][k+1][p]+dp[j-1][k+1][p-pw[k]]+dp[j-1][k-1][p]+dp[j-1][k-1][p-pw[k]])%MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(int q = 0; q<10; q++){
        ans += dp[n][q][1023];
        ans%=MOD;
    }
    cout<<ans;
}