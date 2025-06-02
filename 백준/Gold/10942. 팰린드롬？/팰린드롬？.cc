#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> vec(n);
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        dp[i][i] = true;
        if(i!=0 && vec[i]==vec[i-1]){
            dp[i-1][i] = true;
        }
        for(int k = i-2; k>=0; k--){
            if(vec[k]==vec[i]&&dp[k+1][i-1]){
                dp[k][i] = true;
            }
        }

    }
    int m;
    cin>>m;
    for(int j = 0; j<m; j++){
        int a, b;
        cin>>a>>b;
        if(dp[a-1][b-1]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        cout<<'\n';
    }


}