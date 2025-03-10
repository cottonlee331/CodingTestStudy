// 백준 11404

#include<iostream>
#include<vector>

#define INF 50000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<long long>> dist(n+1,vector<long long>(n+1,INF));
    for(int i = 0; i<m; i++){
        int a, b, cost;
        cin>>a>>b>>cost;
        dist[a][b] = min(dist[a][b],(long long)cost);
    }
    for(int j = 0; j<n+1; j++){
        dist[j][j] = 0;
    }

    for(int x = 1; x<n+1; x++){
        for(int y = 1; y<n+1; y++){
            for(int z = 1; z<n+1; z++){
                dist[y][z] = min(dist[y][z],dist[y][x]+dist[x][z]);
            }
        }
    }

    for(int p = 1; p<n+1; p++){
        for(int q = 1; q<n+1; q++){
            if(dist[p][q]==INF){
                cout<<0<<' ';
                continue;
            }
            cout<<dist[p][q]<<' ';
        }
        cout<<'\n';
    }

}