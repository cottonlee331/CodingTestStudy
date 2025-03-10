// 백준 13398

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int> dp1(n);
    vector<int> dp2(n);

    cin>>dp1[0];
    dp2[0] = dp1[0];
    int result = dp1[0];
    for(int i = 1; i<n; i++){
        int tmp;
        cin>>tmp;
        dp1[i] = max(dp1[i-1]+tmp,tmp);
        dp2[i] = max(dp1[i-1],dp2[i-1]+tmp);
        result = max(result,max(dp1[i],dp2[i]));
    }

    cout<<result;
}