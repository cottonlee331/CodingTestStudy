#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> que;
    for(int i = 0; i<n; i++){
        vec[i] = i;
    }
    for(int j = 0; j<m; j++){
        int a, b, d;
        cin>>a>>b>>d;
        que.push({d,{a-1,b-1}});
    }
    
    int sum = 0;
    while(!que.empty()){
        int dst = que.top().first;
        int x = que.top().second.first;
        int y = que.top().second.second;
        que.pop();

        if(FindRoot(x)==FindRoot(y)){
            continue;
        }
        sum+=dst;
        Union(x,y);
    }
    cout<<sum;
}