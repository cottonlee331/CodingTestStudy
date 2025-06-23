#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin>>N>>M;
    vector<int> vec(N+1,0);
    vector<vector<int>> child(N+1);
    for(int i = 0; i<M; i++){
        int num;
        cin>>num;
        int prev = -1;
        for(int j = 0; j<num; j++){
            int node;
            cin>>node;
            if(prev!=-1){
                child[prev].push_back(node);
                vec[node]++;
            }
            prev = node;
        }
    }

    queue<int> que;
    for(int k = 1; k<vec.size(); k++){
        if(vec[k]==0){
            que.push(k);
        }
    }

    if(que.empty()){
        cout<<0;
        return 0;
    }

    vector<int> ans;
    while(!que.empty()){
        int nd = que.front();
        ans.push_back(nd);
        que.pop();
        for(int a = 0; a<child[nd].size(); a++){
            int idx = child[nd][a];
            vec[idx]--;
            if(vec[idx]==0){
                que.push(idx);
            }   
        }
    }

    if(ans.size()<N){
        cout<<0;
        return 0;
    }

    for(int b = 0; b<ans.size(); b++){
        cout<<ans[b]<<'\n';
    }

}