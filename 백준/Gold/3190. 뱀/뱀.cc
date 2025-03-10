// 3190.cpp

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 우 하 좌 상
vector<int> dir_x = {1,0,-1,0};
vector<int> dir_y = {0,1,0,-1};
void printBoard(vector<vector<int>> &board){
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board.size();j++){
            if(board[i][j]==2){
                cout<<"* ";
            }
            else
                cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

bool isDead(vector<vector<int>> &board, deque<int> &snake_y, deque<int> &snake_x, int dy, int dx, int n){
    if(dy>=n || dx>=n || dy<0 || dx<0){
        return true;
    }
    
    if(board[dy][dx] == 2)
        return true;
    return false;
}

//L은 왼쪽, D는 오른쪽
int Dummy(int n, vector<pair<int,int>> &apple, vector<pair<int,char>> &move){
    int cnt = 0, move_cnt = 0, dir = 0;
    int dx, dy;
    int tail = 0;
    deque<int> snake_y = {0};
    deque<int> snake_x = {0};
    vector <vector<int>> board (n,vector<int>(n,0));
    board[0][0] = 2;
    for(int i = 0; i<apple.size(); i++){
        board[apple[i].first-1][apple[i].second-1] = 1;
    }

    while(true){
        cnt++;
        
        dy = snake_y.front()+dir_y[dir];
        dx = snake_x.front()+dir_x[dir];

        if(isDead(board,snake_y,snake_x,dy,dx,n)){
            return cnt;
        }

        snake_y.push_front(dy);
        snake_x.push_front(dx);
        

        if(move[move_cnt].first == cnt){
            if(move[move_cnt].second == 'D'){
                dir = (dir+1)%4;
            }
            else{
                dir = (dir-1+4)%4;
            }
            move_cnt++;
        }

        if(board[dy][dx] == 1){
            board[dy][dx] = 0;
            board[dy][dx] = 2;
            //printBoard(board);
            
            continue;
        }

        board[snake_y.back()][snake_x.back()] = 0;
        snake_y.pop_back();
        snake_x.pop_back();
        board[dy][dx] = 2;
        //printBoard(board);

    }


}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n, k, l;

    cin>>n>>k;
    
    vector<pair<int,int>> apple(k);
    
    for(int i = 0; i<k; i++){
        cin>>apple[i].first>>apple[i].second;
    }
    
    cin>>l;
    vector<pair<int,char>> move(l);
    for(int j = 0; j<l; j++){
        cin>>move[j].first>>move[j].second;
    }

    cout<<Dummy(n,apple,move);
}