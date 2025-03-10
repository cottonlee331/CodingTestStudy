// 백준 1389

#include<iostream>
#include<vector>

#define INF 600000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
    for(int i = 0; i<n+1; i++){
        dist[i][i] = 0;
    }
    for(int j = 0; j<m; j++){
        int a, b;
        cin>>a>>b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int x = 1; x<n+1; x++){
        for(int y = 1; y<n+1; y++){
            for(int z = 1; z<n+1; z++){
                dist[y][z] = min(dist[y][z],dist[y][x]+dist[x][z]);
            }
        }
    }

    int result = -1;
    int num = INF;
    for(int k = 1; k<n+1; k++){
        int bacon = 0;
        for(int l = 1; l<n+1; l++){
            bacon+=dist[k][l];
        }
        if(bacon<num){
            num = bacon;
            result = k;
        }
    }
    cout<<result;
}