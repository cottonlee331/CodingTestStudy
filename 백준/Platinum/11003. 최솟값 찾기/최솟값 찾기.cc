// 백준 11003

#include <iostream>
#include<vector>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l;
    cin>>n>>l;

    deque<pair<int,int>> que;
    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        while(!que.empty()&&que.back().second>=tmp){
            que.pop_back();
        }
        que.push_back(make_pair(i,tmp));
        if(i-que.front().first+1>l){
            que.pop_front();
        }
        cout<<que.front().second<<' ';
    }

}