// 백준 2252

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<int> in_cnt(n+1,0);
    vector<vector<int>> vec(n+1,vector<int>());

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;

        vec[a].push_back(b);
        in_cnt[b]++;
    }

    vector<int> result;
    int node_cnt = n;
    while(node_cnt>0){
        for(int j = 1; j<n+1; j++){
            if(in_cnt[j]==0){
                node_cnt--;
                in_cnt[j] = -1;
                result.push_back(j);
                for(int k = 0; k<vec[j].size(); k++){
                    in_cnt[vec[j][k]]--;
                }
            }
        }
    }

    for(int p = 0; p<result.size(); p++){
        cout<<result[p]<<' ';
    }
}