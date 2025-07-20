#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

#define INF pow(2,31)-1
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> time(n);
    
    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;
        time[i] = {e,s};
    }
    sort(time.begin(),time.end());

    int ans = 1;
    stack<pair<int,int>> stk;
    stk.push(time[0]);

    for(int j = 1; j<time.size(); j++){
        if(time[j].second>=stk.top().first){
            stk.push(time[j]);
            ans++;
        }
    }

    cout<<ans;
}