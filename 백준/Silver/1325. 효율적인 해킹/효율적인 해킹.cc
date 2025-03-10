// 1325.cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> hack(vector<vector<int>> com){
    vector<int> result;
    vector<int> visit(com.size(),0);
    stack <int> stk;
    int max = 0, cnt = 0, top;

    // DFS로 탐색 후 Max랑 비교 후 저장
    for(int i = 1; i<com.size(); i++){

        cnt = 0;
        stk.push(i);
        visit[i]=1;
        while(!stk.empty()){
            top = stk.top();
            stk.pop();
            for(int j = 0; j<com[top].size();j++){
                if(!visit[com[top][j]]){
                    visit[com[top][j]] = 1;
                    stk.push(com[top][j]);
                    cnt++;
                }
            }
        }

        
        for(int k = 0; k < visit.size();k++){
            visit[k] = 0;
        }

        if(cnt<max){
            continue;
        }
        else if(cnt>max){
            result.clear();
            max = cnt;
        }

        result.push_back(i);

        
    }

    return result;
}

int main(){
    int n, m;
    int a, b;
    vector<int> result;
    cin>>n>>m;

    vector <vector<int>> com(n+1,vector<int>());
    for(int i = 0; i<m; i++){
        cin>> a >> b;
        com[b].push_back(a);
    }

    result = hack(com);
    sort(result.begin(),result.end());
    for(int j = 0; j<result.size(); j++){
        cout<<result[j]<<' ';
    }

}