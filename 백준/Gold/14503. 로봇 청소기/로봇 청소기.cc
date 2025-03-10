//14503.cpp

#include <iostream>
#include <vector>

using namespace std;

// 방향: 북0 | 동1 | 남2 | 서3
// +는 시계방향 -는 반시계방향
vector<int> dir_x = {0,1,0,-1};
vector<int> dir_y = {-1,0,1,0};

void printRoom(vector <vector<int>> &room,int r, int c){
    for(int i = 0; i<room.size(); i++){
        for (int j = 0; j<room[0].size(); j++){
            if(i==r && j==c){
                cout<<'@'<<' ';
                continue;
            }
            cout<<room[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"-----print end------\n";
}

int cleanRoom(int init_r, int init_c, int init_d, vector <vector<int>> room){
    
    int cnt = 0;
    int r = init_r, c = init_c, d = init_d;
    bool around_empty = false;

    while(true){
        around_empty = false;
        if(!room[r][c]){
            room[r][c]=2;
            cnt++;
        }
        for(int i = 1; i<=4; i++){
            d = (d-1+4)%4;
            if(0<=r+dir_y[d] && r+dir_y[d]<room.size()
            && 0<=c+dir_x[d] && c+dir_x[d]<room[0].size()
            && !room[r+dir_y[d]][c+dir_x[d]]){
                r += dir_y[d];
                c += dir_x[d];
                around_empty = true;
                break;
            }
        }
        if(!around_empty){
            if(room[r-dir_y[d]][c-dir_x[d]]!=1){
                r -= dir_y[d];
                c -= dir_x[d];
            }
            else{
                return cnt;
            }
        }
        //printRoom(room,r,c);
    }

    return cnt;
}

int main(){
    int n, m;
    int r,c,d;

    cin>>n>>m;
    cin>>r>>c>>d;

    vector <vector<int>> room(n,vector<int>(m));

    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin>>room[i][j];
        }
    }
    cout<<cleanRoom(r,c,d,room);
}