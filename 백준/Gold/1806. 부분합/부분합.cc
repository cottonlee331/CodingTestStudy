#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long s;
    cin>>n>>s;

    vector<long long> vec(n+1,0);

    for(int i = 1; i<=n; i++){
        long long tmp;
        cin>>tmp;
        vec[i] = vec[i-1]+tmp;
    }

    int lft = 0;
    int rgt = 1;
    int ans = n+1;
    long long sum = vec[rgt];
    while(lft<rgt && lft<n+1 && rgt<n+1){
        sum = vec[rgt]-vec[lft];
        if(sum>=s){
            if(ans>rgt-lft){
                ans = rgt-lft;
            }
            lft++;
        }
        else{
            rgt++;
        }
    }
    if(ans == n+1){
        cout<<0;
        return 0;
    }
    cout<<ans;
}