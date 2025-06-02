#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> dp0(41);
    vector<int> dp1(41);
    dp0[0] = 1;
    dp0[1] = 0;
    dp1[0] = 0;
    dp1[1] = 1;
    for(int i = 2; i<41; i++){
        dp0[i] = dp0[i-1]+dp0[i-2];
        dp1[i] = dp1[i-1]+dp1[i-2];
    }

    int t;
    cin>>t;
    for(int j = 0; j<t; j++){
        int a;
        cin>>a;
        cout<<dp0[a]<<' '<<dp1[a]<<'\n';
    }
}