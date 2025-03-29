#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<bool> visited;
vector<int> serial;
int m;

void Backtracking(int cnt){
    if(cnt>=m){
        for(int j = 0; j<m; j++){
            cout<<serial[j]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 0; i<vec.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            serial.push_back(vec[i]);
            Backtracking(cnt+1);
            serial.pop_back();
            visited[i] = false;
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>m;
    vec.assign(n,0);
    visited.assign(n,false);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    Backtracking(0);
}