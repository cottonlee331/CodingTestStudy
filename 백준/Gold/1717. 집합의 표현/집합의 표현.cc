// 백준 1717

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> vec;

int FindRoot(int idx){
    int root = idx;
    stack<int> stk;
    while(vec[root]!=root){
        stk.push(vec[root]);
        root = vec[root];
    }
    while(!stk.empty()){
        vec[stk.top()] = root;
        stk.pop();
    }
    return root;
}

void Union(int a, int b){
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

    int n, m;
    cin>>n>>m;

    for(int j = 0; j<n+1; j++){
        vec.push_back(j);
    }

    for(int i = 0; i<m; i++){
        int op, a, b;
        cin>>op>>a>>b;

        if(op == 0){
            Union(a,b);
        }
        else{
            int root_a = FindRoot(a);
            int root_b = FindRoot(b);
            if(root_a==root_b){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }
}