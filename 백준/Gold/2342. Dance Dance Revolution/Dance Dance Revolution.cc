// 백준 2342

#include<iostream>
#include<vector>

#define INF 4000000

using namespace std;

int CalcCost(int a, int b){
    if(a==b){
        // 같은자리 (a-b) == 0  |  1소모
        return 1;
    }
    else if(a == 0){
        // 중앙 -> 다른칸  |  2 소모
        return 2;
    }
    if(a<b){
        swap(a,b);
    }
    if((a-b)%2 == 1){
        // 1<->2 1<->4 2<->3 3<->4  |  (a-b)%2 == 1  |  3 소모
        return 3;
    }
    else{
        // 1<->3 2<->4  |  (a-b)%2 == 0  |  4 소모
        return 4;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> vec;
    
    int tmp;
    cin>>tmp;
    while(tmp!=0){
        vec.push_back(tmp);
        cin>>tmp;
    }

    vector<vector<vector<int>>> cost(vec.size()+1,vector<vector<int>>(5, vector<int>(5,INF)));
    cost[0][0][0] = 0;
    if(vec.size() == 0){
        
    }
    
    for(int i = 1; i<cost.size(); i++){
        for(int j = 0; j<5; j++){
            for(int k = 0; k<5; k++){
                if(cost[i-1][j][k] != INF){
                    cost[i][j][vec[i-1]] = min(cost[i][j][vec[i-1]],cost[i-1][j][k] + CalcCost(k,vec[i-1]));
                    cost[i][vec[i-1]][k] = min(cost[i][vec[i-1]][k],cost[i-1][j][k] + CalcCost(j,vec[i-1]));
                }
            }
        }
    }

    int result = INF;
    int n = vec.size();
    for(int a = 0; a<5; a++){
        for(int b = 0; b<5; b++){
            if(cost[n][a][b]<result && cost[n][a][b]!=INF){
                result = cost[n][a][b];
            }
        }
    }
    cout<<result;
}