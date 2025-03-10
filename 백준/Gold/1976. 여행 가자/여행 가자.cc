// 백준 1976

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

void UnionGroup(int a, int b){
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

    for(int a = 0; a<n+1; a++){
        vec.push_back(a);
    }

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<n+1; j++){
            int uni;
            cin>>uni;
            if(uni){
                UnionGroup(i,j);
            }
        }
    }

    int curr_root = -1;
    string result = "YES";
    for(int k = 0; k<m; k++){
        int tmp;
        cin>>tmp;
        if(curr_root == -1){
            curr_root = FindRoot(tmp);
            continue;
        }
        if(curr_root!=FindRoot(tmp)){
            result = "NO";
            break;
        }
    }
    cout<<result;
    
}