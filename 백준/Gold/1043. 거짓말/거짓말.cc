// 백준 1043

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> vec;

int FindRoot(int idx){
    int root = idx;
    stack<int> stk;
    while(vec[root]!=root){
        stk.push(root);
        root = vec[root];
    }
    while(!stk.empty()){
        vec[stk.top()] = root;
        stk.pop();
    }
    return root;
}

void UnionGruop(int a, int b){
    int root_a = FindRoot(a);
    int root_b = FindRoot(b);
    if(root_a<root_b){
        vec[root_b] = root_a;
    }
    else{
        vec[root_a] = root_b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    cin>>n>>m>>t;
    
    for(int j = 0; j<n+1; j++){
        vec.push_back(j);
    }

    int cnt = 0;
    for(int i = 0; i<t; i++){
        int tmp;
        cin>>tmp;
        vec[tmp] = 0;
    }
    stack<int> party;
    for(int k = 0; k<m; k++){
        int tmp,curr_root;
        cin>>tmp>>curr_root;
        party.push(curr_root);
        curr_root = FindRoot(curr_root);
        for(int p = 1; p<tmp; p++){
            int tmp1;
            cin>>tmp1;
            UnionGruop(curr_root,tmp1);
            curr_root = FindRoot(curr_root);
        }
    }

    while(!party.empty()){
        if(FindRoot(party.top())!=0){
            cnt++;
        }
        party.pop();
    }
    cout<<cnt;
}