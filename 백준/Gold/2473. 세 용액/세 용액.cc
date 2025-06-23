#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define INF 3000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    vector<ll> liq(N);
    for(int i = 0; i<N; i++){
        cin>>liq[i];
    }

    sort(liq.begin(), liq.end());
    
    if(liq[0]>=0){
        cout<<liq[0]<<' '<<liq[1]<<' '<<liq[2];
        return 0;
    }
    else if(liq[N-1]<=0){
        cout<<liq[N-3]<<' '<<liq[N-2]<<' '<<liq[N-1];
        return 0;
    }

    int lft, rgt;
    lft = 0;
    rgt = N-1;

    ll sum = 0;
    ll min_sum = INF;
    vector<int> ans(3);

    for(int i = 0; i<N-2; i++){
        lft = i+1;
        rgt = N-1;
        while(lft<rgt){
            sum = liq[i]+liq[lft]+liq[rgt];
            if(abs(sum)<abs(min_sum)){
                min_sum = sum;
                ans[0] = liq[i];
                ans[1] = liq[lft];
                ans[2] = liq[rgt];
            }
            if(sum>0){
                rgt--;
            }
            else if(sum<0){
                lft++;
            }
            else{
                break;
            }
        }
    }
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2];
}