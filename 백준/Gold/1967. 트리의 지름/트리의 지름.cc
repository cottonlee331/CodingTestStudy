#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin>>n;
    vector<vector<pair<int,int>>> vec(2,vector<pair<int,int>>());

    for(int i = 0; i<n-1; i++){
        int a, b, w;
        cin>>a>>b>>w;
        while(b>=vec.size()){
            vec.push_back(vector<pair<int,int>>());
        }
        vec[a].push_back({b,w});
        vec[b].push_back({a,w});
    }

    stack<pair<int,int>> stk;
    vector<bool> visited(vec.size(),false);
    stk.push({1,0});
    visited[1] = true;
    pair<int,int> leaf = stk.top();

    while(!stk.empty()){
        int idx = stk.top().first;
        int dist = stk.top().second;
        stk.pop();
        for(int j = 0; j<vec[idx].size(); j++){
            if(visited[vec[idx][j].first]){
                continue;
            }
            visited[vec[idx][j].first] = true;
            stk.push({vec[idx][j].first,dist+vec[idx][j].second});
            if(stk.top().second>leaf.second){
                leaf = stk.top();
            }
        }
    }

    visited.assign(vec.size(),false);
    leaf.second = 0;
    stk.push(leaf);
    visited[leaf.first] = true;

    while(!stk.empty()){
        int idx = stk.top().first;
        int dist = stk.top().second;
        stk.pop();
        for(int j = 0; j<vec[idx].size(); j++){
            if(visited[vec[idx][j].first]){
                continue;
            }
            visited[vec[idx][j].first] = true;
            stk.push({vec[idx][j].first,dist+vec[idx][j].second});
            if(stk.top().second>leaf.second){
                leaf = stk.top();
            }
        }
    }

    cout<<leaf.second;
}