#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec(9,vector<int>(9,0));
vector<vector<bool>> row(9,vector<bool>(10,false));
vector<vector<bool>> col(9,vector<bool>(10,false));
vector<vector<bool>> box(9,vector<bool>(10,false));

void PrintVec(){
    for(int a = 0; a<9; a++){
        for(int b = 0; b<9; b++){
            cout<<vec[a][b];
        }
        if(a==8){
            continue;
        }
        cout<<'\n';
    }
}

bool BackTracking(int idx){
    if(idx == 81){
        PrintVec();
        return true;
    }
    int x = idx/9;
    int y = idx%9;
    if(vec[x][y]==0){
        for(int i = 1; i<10; i++){
            int bx_idx = (x/3)*3+(y/3)%3;
            if(row[x][i] || col[y][i] || box[bx_idx][i]){
                continue;
            }
            vec[x][y] = i;
            row[x][i] = true;
            col[y][i] = true;
            box[bx_idx][i] = true;
            // PrintVec();
            // cout<<'\n';

            bool back = BackTracking(idx+1);
            
            if(back){
                return true;
            }
            vec[x][y] = 0;
            row[x][i] = false;
            col[y][i] = false;
            box[bx_idx][i] = false;
        }
    }
    else{
        if(BackTracking(idx+1)){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            char tmp;
            cin>>tmp;
            tmp = tmp-'0';
            vec[i][j] = tmp;
            row[i][tmp] = true;
            col[j][tmp] = true;
            int idx = (i/3)*3+(j/3)%3;
            box[idx][tmp] = true;
        }
    }
    BackTracking(0);
}