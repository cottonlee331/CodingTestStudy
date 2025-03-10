//14500.cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int max_sum = 0;
int max_val = 0;

vector<vector<int>> vec;
vector<vector<bool>> visited;

vector<int> dir_y = {-1,1,0,0};
vector<int> dir_x = {0,0,-1,1};


void backtracking(int cnt, int sum, int row, int col){
    sum+=vec[row][col];
    if(sum+max_val*(4-cnt)<max_sum){
        return;
    }
    if(cnt== 4){
        if(sum>max_sum){
            max_sum = sum;
        }
        return;
    }

    for (int i =1; i<4; i++){

        if(0<=row+dir_y[i] && row+dir_y[i]<vec.size() && 0<=col+dir_x[i] && col+dir_x[i]<vec[0].size() && !visited[row+dir_y[i]][col+dir_x[i]]){
            visited[row+dir_y[i]][col+dir_x[i]] = true;
            backtracking(cnt+1,sum,row+dir_y[i],col+dir_x[i]);
            visited[row+dir_y[i]][col+dir_x[i]] = false;
        }
    }
}

void shapeNotDFS(int row, int col){
    int sum = vec[row][col], cnt = 0;
    vector<int> num;
    for(int i = 0; i<4; i++){
        if(0<=row+dir_y[i] && row+dir_y[i]<vec.size() && 0<=col+dir_x[i] && col+dir_x[i]<vec[0].size()){
            num.push_back(vec[row+dir_y[i]][col+dir_x[i]]);
            sum+=num[cnt];
            cnt++;
        }
    }
    if(cnt<3){
        return;
    }
    if(cnt>3){
        sort(num.begin(),num.end());
        sum-=num[0];
    }
    if(sum>max_sum){
        max_sum = sum;
    }
}



void tetro(){
    for(int i =0; i<vec.size();i++){
        for( int j = 0; j<vec[0].size(); j++){
            shapeNotDFS(i,j);
            visited[i][j] = true;
            backtracking(1,0,i,j);
            visited[i][j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vec = vector <vector<int>> (n,vector<int>(m));
    visited = vector <vector<bool>> (n,vector<bool>(m,false));

    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
            max_val = max(vec[i][j],max_val);
        }
    }

    tetro();
    cout<<max_sum;
}