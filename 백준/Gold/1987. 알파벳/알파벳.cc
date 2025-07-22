#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> dr = {1,-1,0,0};
vector<int> dc = {0,0,1,-1};

vector<vector<char>> ch;
vector<bool> visit(26,false);

int ans = 0;

void Backtracking(int row, int col, int n){
    ans = max(ans,n);
    visit[ch[row][col]-'A'] = true;
    for(int i = 0; i<4; i++){
        int r = row+dr[i];
        int c = col+dc[i];
        if(0<=r && 0<=c && r<ch.size() && c<ch[0].size() && !visit[ch[r][c]-'A']){
            Backtracking(r,c,n+1);
        }
    }
    visit[ch[row][col]-'A'] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin>>r>>c;

    ch.assign(r,vector<char>(c));
    
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin>>ch[i][j];
        }
    }
    Backtracking(0,0,1);
    cout<<ans;
}