#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    for(int i = 0; i<T; i++){
        int n; 
        cin>>n;
        vector<int> nxt(n+1,0);
        for(int j = 1; j<n+1; j++){
            cin>>nxt[j];
        }
        int start = 1;
        vector<bool> visit(n+1,false);
        stack<int> stk;
        int count = 0;

        while(start<=n){
            stk.push(start);
            visit[start] = true;
            while(!stk.empty()){
                int curr = stk.top();
                if(visit[nxt[curr]]){
                    int sz = stk.size();
                    while(stk.top()!=nxt[curr]){
                        stk.pop();
                        if(stk.empty()){
                            count+=sz;
                            break;
                        }
                    }
                    if(!stk.empty()){
                        stk.pop();
                        count+=stk.size();
                        while(!stk.empty()){
                            stk.pop();
                        }
                    }
                }
                else{
                    stk.push(nxt[curr]);
                    visit[nxt[curr]] = true;
                }
            }
            while(start<=n){
                if(visit[start]){
                    start++;
                }
                else{
                    break;
                }
            }
        }
        cout<<count<<'\n';
    }
}