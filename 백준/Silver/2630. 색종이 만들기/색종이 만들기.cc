#include <iostream>
#include <vector>

using namespace std;

int ans[2] = {0,0};
vector<vector<int>> mp;

void Check(int r, int c, int sz){
    int color = mp[r][c];
    if(sz==1){
        ans[color]++;
        return;
    }
    
    for(int i = 0; i<sz; i++){
        for(int j = 0; j<sz; j++){
            if(mp[r+i][c+j]!=color){
                int nw_sz = sz/2;
                Check(r,c,nw_sz);
                Check(r,c+nw_sz,nw_sz);
                Check(r+nw_sz,c,nw_sz);
                Check(r+nw_sz,c+nw_sz,nw_sz);
                return;
            }
        }
    }
    ans[color]++;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    mp.assign(n,vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>mp[i][j];
        }
    }
    Check(0,0,n);
    cout<<ans[0]<<'\n'<<ans[1];
}