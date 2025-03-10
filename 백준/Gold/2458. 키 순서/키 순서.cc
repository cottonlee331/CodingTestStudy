// 2458.cpp

#include <iostream>
#include <vector>

using namespace std;
const int INF = 5e3;

void floydWarshall(int n, vector<vector<int>> &graph){
    for(int i = 1; i<=n; i++ ){ // 중간
        for(int j = 1; j<=n; j++){  // 출발
            for(int k = 1; k<=n; k++){  // 도착
                int cost = graph[j][i] + graph[i][k];
                graph[j][k] = min(graph[j][k],cost);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    // 모든 간선 길이 INF로 초기화
    vector<vector<int>> graph(n+1,vector<int>(n+1,INF));

    for(int i = 1; i<=n; i++){
        // 자신 - 자신 거리는 0
        graph[i][i] = 0;
    }

    int a, b;
    for(int j = 0; j<m; j++){
        cin>>a>>b;
        graph[a][b] = 1;

    }

    int cnt = 0;
    floydWarshall(n,graph);
    for(int k = 1; k<=n; k++ ){
        for(int l = 1; l<=n; l++){
            if(graph[k][l]==INF && graph[l][k] == INF){
                cnt++;
                break;
            }
        }
    }
    cout<<n-cnt;
}