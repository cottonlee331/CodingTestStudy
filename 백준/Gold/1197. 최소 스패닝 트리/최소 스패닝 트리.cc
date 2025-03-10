// 백준 1197

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<int> parent;

int FindRoot(int idx){
    int root = idx;
    stack<int> stk;
    while(parent[root]!=root){
        stk.push(parent[root]);
        root = parent[root];
    }
    while(!stk.empty()){
        parent[stk.top()] = root;
        stk.pop();
    }
    return root;
}

void UnionGraph(int a, int b){
    int a_root = FindRoot(a);
    int b_root = FindRoot(b);
    if(a_root<b_root){
        parent[b_root] = a_root;
    }
    else{
        parent[a_root] = b_root;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v, e;
    cin>>v>>e;

    int weight = 0;

    
    for(int j = 0; j<v+1; j++){
        parent.push_back(j);
    }

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> graph;

    for(int i = 0; i<e; i++){
        int a, b, c;
        cin>>a>>b>>c;
        graph.push(make_pair(c,make_pair(a,b)));
    }


    while(!graph.empty()){
        int x, y, w;
        w = graph.top().first;
        x = graph.top().second.first;
        y = graph.top().second.second;
        graph.pop();
        if(FindRoot(x)!=FindRoot(y)){
            UnionGraph(x,y);
            weight+=w;
        }
    }
    cout<<weight;
}