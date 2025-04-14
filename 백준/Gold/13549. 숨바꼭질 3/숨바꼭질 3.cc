#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    if(k<=n){
        cout<<n-k;
        return 0;
    }

    queue<pair<int,int>> q;
    vector<bool> vec(MAX+1,false);
    q.push({0,n});
    vec[n] = true;

    int ans = 0;
    while(!q.empty()){
        int dst = q.front().first;
        int idx = q.front().second;
        q.pop();
        if(idx*2<=MAX && !vec[idx*2]){
            vec[idx*2] = true;
            q.push({dst,idx*2});
            if(idx*2==k){
                ans = dst;
                break;
            }
        }
        if(idx>0 && !vec[idx-1]){
            vec[idx-1] = true;
            q.push({dst+1,idx-1});
            if(idx-1==k){
                ans = dst+1;
                break;
            }
        }
        if(idx<MAX && !vec[idx+1]){
            vec[idx+1] = true;
            q.push({dst+1,idx+1});
            if(idx+1==k){
                ans = dst+1;
                break;
            }
        }
    }
    cout<<ans;
}