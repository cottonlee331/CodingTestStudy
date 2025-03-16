#include <iostream>
#include <vector>

using namespace std;

vector<int> dirx = {0,1,-1,0,0};
vector<int> diry = {0,0,0,-1,1};

vector<int> horz = {0,0,0,0};
vector<int> vert = {0,0,0,0};
pair<int,int> pos = {0,0};
pair<int,int> dice = {0,0};

void RollDice(int dir, vector<vector<int>> &vec){
    if(pos.first+dirx[dir]<0 || pos.first+dirx[dir]>=vec[0].size()
        || pos.second+diry[dir]<0 || pos.second+diry[dir]>=vec.size()){
            return;
    }
    pos.first+=dirx[dir];
    pos.second+=diry[dir];
    dice.first+=dirx[dir]+4;
    dice.first%=4;
    dice.second+=diry[dir]+4;
    dice.second%=4;
    if(dir==1 || dir == 2){
        vert[dice.second%4] = horz[dice.first%4];
        vert[(dice.second+2)%4] = horz[(dice.first+2)%4];
    }
    else if(dir == 3 || dir == 4){
        horz[dice.first%4] = vert[dice.second%4];
        horz[(dice.first+2)%4] = vert[(dice.second+2)%4];
    }
    if(vec[pos.second][pos.first]==0){
        vec[pos.second][pos.first] = horz[dice.first];
    }
    else{
        horz[dice.first] = vert[dice.second] = vec[pos.second][pos.first];
        vec[pos.second][pos.first] = 0;
    }
    cout<<horz[(dice.first+2)%4]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y, k;
    cin>>n>>m>>x>>y>>k;
    pos = make_pair(y,x);
    vector<vector<int>> vec(n,vector<int>(m,0));
    

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>vec[i][j];
        }
    }

    for(int a = 0; a<k; a++){
        int move;
        cin>>move;
        RollDice(move,vec);
    }

}