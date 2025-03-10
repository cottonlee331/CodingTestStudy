// 백준17298

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    stack<pair<int,int>> num;

    cin>>n;
    vector<int> nge(n,-1);
    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        while(!num.empty()&&tmp>num.top().second){
            nge[num.top().first] = tmp;
            num.pop();
        }
        num.push(make_pair(i,tmp));
    }

    for(int a = 0; a<n; a++){
        cout<<nge[a]<<' ';
    }
}