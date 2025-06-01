#include <iostream>
#include <vector>
#include <queue>

#define RED 'R'
#define BLUE 'B'
#define WALL '#'
#define GOAL 'O'
#define NONE '.'
#define INF 50

using namespace std;

vector<vector<char>> board;
vector<int> dr = {0,0,-1,1};
vector<int> dc = {-1,1,0,0};

pair<int,int> Move(int dir, pair<int,int> red, pair<int,int> blue){
    // 1: 정답, 0: 과정, -1: 파랑빠짐
    int rd = red.first*dr[dir]+red.second*dc[dir];
    int bl = blue.first*dr[dir]+blue.second*dc[dir];
    int coord = (red.first*10+red.second)*100+blue.first*10+blue.second;

    if(rd>bl){
        //빨강 먼저 이동
        bool is_redout = false;
        while(board[red.first+dr[dir]][red.second+dc[dir]]!=WALL){
            red.first+=dr[dir];
            red.second+=dc[dir];
            if(board[red.first][red.second]==GOAL){
                is_redout = true;
                red.first = -1;
                red.second = -1;
                break;
            }
        }
        while(board[blue.first+dr[dir]][blue.second+dc[dir]]!=WALL && !(red.first==blue.first+dr[dir]&&red.second==blue.second+dc[dir])){
            blue.first+=dr[dir];
            blue.second+=dc[dir];
            if(board[blue.first][blue.second]==GOAL){
                return {-1,coord};
            }
        }
        if(is_redout){
            return {1,coord};
        }
    }
    else{
        //파랑 먼저 이동
        while(board[blue.first+dr[dir]][blue.second+dc[dir]]!=WALL){
            blue.first+=dr[dir];
            blue.second+=dc[dir];
            if(board[blue.first][blue.second]==GOAL){
                return {-1,coord};
            }
        }
        while(board[red.first+dr[dir]][red.second+dc[dir]]!=WALL && !(blue.first==red.first+dr[dir]&&blue.second==red.second+dc[dir])){
            red.first+=dr[dir];
            red.second+=dc[dir];
            if(board[red.first][red.second]==GOAL){
                return {1,coord};
            }
        }
    }
    int new_coord = (red.first*10+red.second)*100+blue.first*10+blue.second;
    if(new_coord==coord){
        return {-1,coord};
    }
    return {0,new_coord};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    board.assign(n,vector<char>(m));

    pair<int,int> rb;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==RED){
                rb.first = i*10+j;
                board[i][j] = NONE;
            }
            else if(board[i][j]==BLUE){
                rb.second = i*10+j;
                board[i][j] = NONE;
            }
        }
    }

    queue<pair<int,int>> que;
    int min_dist = INF;
    que.push({0,rb.first*100+rb.second});

    while(!que.empty()){
        int dist = que.front().first;
        pair<int,int> red = {(que.front().second/100)/10,(que.front().second/100)%10};
        pair<int,int> blue = {(que.front().second%100)/10, (que.front().second%100)%10};

        que.pop();
        if(dist>=min_dist){
            break;
        }
        if(dist >= 10){
            break;
        }

        dist++;
        for(int k = 0; k<4; k++){
            //cout<<"dist: "<<dist<<"\tmin_dist: "<<min_dist<<"\tdir: "<<k<<"\tred: "<<red.first<<","<<red.second<<"\tblue: "<<blue.first<<","<<blue.second<<"\n";
            pair<int,int> move= Move(k,red,blue);
            if(move.first == 1){
                min_dist = min(min_dist,dist);
                break;
            }
            else if(move.first == 0){
                que.push({dist,move.second});
            }
        }
    }

    min_dist = min_dist==INF?-1:min_dist;
    cout<<min_dist;
}