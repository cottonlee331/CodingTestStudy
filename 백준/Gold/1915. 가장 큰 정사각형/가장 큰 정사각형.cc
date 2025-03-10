// 백준 1915

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int max_size = min(n,m);

    vector<vector<int>> vec(n,vector<int>(m,0));
    queue<pair<int,int>> dp;
    int result = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char tmp;
            cin>>tmp;
            vec[i][j] = tmp-'0';
            if(vec[i][j]==1){
                result = 1;
            }
        }
    }

    for(int a = 1; a<n; a++){
        for(int b = 1; b<m; b++){
            if(vec[a][b]==1){
                vec[a][b] = min(vec[a-1][b-1],min(vec[a-1][b],vec[a][b-1]))+1;
                result = max(result,vec[a][b]);
            }
        }
    }
    cout<<result*result;
}