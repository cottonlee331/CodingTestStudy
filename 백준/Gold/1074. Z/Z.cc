#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<int,int> z_map;

    z_map.insert({0,0});
    z_map.insert({1,1});
    z_map.insert({10,2});
    z_map.insert({11,3});

    int n, r, c;
    cin>>n>>r>>c;

    int ans = 0;
    while(n>0){
        n--;
        int m = pow(2,n);
        int rr = r/m;
        r %= m;
        int cc = c/m;
        c %= m;
        ans*=4;
        ans+=z_map[rr*10+cc];
    }
    cout<<ans;
}
