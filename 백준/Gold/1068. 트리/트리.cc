// 백준1068

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, root;
    cin>>n;

    vector<vector<int>> tree(n,vector<int>());

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(tmp == -1){
            root = i;
        }
        else{
            tree[tmp].push_back(i);
        }
    }

    int del;
    cin>>del;

    int leaf = 0;
    stack<int> stk;
    stk.push(root);
    while(!stk.empty()){
        if(del == root){
            break;
        }
        int node = stk.top();
        stk.pop();
        int cnt = 0;
        for(int j = 0; j<tree[node].size(); j++){
            if(tree[node][j]==del){
                continue;
            }
            stk.push(tree[node][j]);
            cnt++;
        }
        if(cnt == 0){
            leaf++;
        }
    }

    cout<<leaf;

}