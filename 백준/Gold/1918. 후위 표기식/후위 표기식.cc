#include <iostream>
#include <stack>
#include <map>

using namespace std;

// +-*/()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char,int> op;
    op.insert({'+',1});
    op.insert({'-',1});
    op.insert({'*',2});
    op.insert({'/',2});

    string str;
    cin>>str;

    stack<char> stk;

    for(int i = 0; i<str.size(); i++){
        if(str[i]=='('){
            stk.push(str[i]);
            continue;
        }
        else if(str[i]==')'){
            while(stk.top()!='('){
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
            continue;
        }
        else if(op.find(str[i])!=op.end()){
            if(stk.empty()){
                stk.push(str[i]);
            }
            
            else if(op[stk.top()]>=op[str[i]]){
                while(!stk.empty() && stk.top()!='('&& op[stk.top()]>=op[str[i]]){
                    cout<<stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
            else{
                stk.push(str[i]);
            }
            continue;
        }
        cout<<str[i];
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }


}