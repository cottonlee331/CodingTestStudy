// 백준 14425

#include<iostream>
#include<set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    set<string> dic;

    for(int i = 0; i<n; i++){
        string tmp; 
        cin>>tmp;
        dic.insert(tmp);
    }

    int cnt = 0;
    for(int j = 0; j<m; j++){
        string tmp1;
        cin>>tmp1;
        if(dic.find(tmp1) != dic.end()){
            cnt++;
        }
    }
    cout<<cnt;
}