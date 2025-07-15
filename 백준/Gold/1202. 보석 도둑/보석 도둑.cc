#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vector<pair<ll,int>> gem(n);
    vector<int> knap(k);
    for(int i = 0; i<n; i++){
        int m;
        ll v;
        cin>>m>>v;
        gem[i].first = m;
        gem[i].second = v;
    }
    for(int j = 0; j<k; j++){
        int c;
        cin>>c;
        knap[j] = c;
    }
    sort(gem.begin(),gem.end());
    sort(knap.begin(),knap.end());

    ll ans = 0;
    int idx = 0;
    priority_queue<ll> pq;
    for(int a = 0; a<k; a++){
        while(idx<n && gem[idx].first<=knap[a]){
            pq.push(gem[idx].second);
            idx++;
        }
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }

    cout<<ans;
}