#include <iostream>
#include <vector>
#include <stack>

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

void Union (int a , int b){
    int root_a = FindRoot(a);
    int root_b = FindRoot(b);
    if(root_a < root_b){
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
    vec.assign(n,0);
    for(int i = 0; i<n; i++){
        vec[i] = i;
    }
    int ans = 0;
    for(int j = 0; j<m; j++){
        int a, b;
        cin>> a>> b;
        if(ans != 0){
            continue;
        }
        a = FindRoot(a);
        b = FindRoot(b);
        if(a == b){
            ans = j+1;
        }
        else{
            Union(a,b);
        }
    }
    cout<<ans;
}