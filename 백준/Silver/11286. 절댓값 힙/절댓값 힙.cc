// 백준 11286

#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pque;
    // x != 0: add
    // x == 0: pop
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        if(x==0){
            if(pque.empty()){
                cout<<0<<"\n";
            }
            else{
                cout<<pque.top().second<<'\n';
                pque.pop();
            }
        }
        else{
            int y;
            if(x<0){
                y = -x;
            }
            else{
                y = x;
            }
            pque.push(make_pair(y,x));
        }
    }
}