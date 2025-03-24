#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cc = 0;
void PrintVec(vector<vector<int>> &vec, int a, int b){
    for(int i = 0; i<vec.size(); i++){
        for(int j = 0; j<vec.size(); j++){
            if(a==i && b==j){
                cout<<"@ ";
            }
            else{
                cout<<vec[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int sz = 2;
    pair<int,int> pos;

    vector<vector<int>> vec(n,vector<int>(n,0));
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            int tmp;
            cin>>tmp;
            vec[i][j] = tmp;
            if(tmp==9){
                pos.first = i;
                pos.second = j;
                vec[i][j] = 0;
            }
        }
    }

    vector<int> dir_x = {-1,0,0,1};
    vector<int> dir_y = {0,-1,1,0};

    deque<pair<int,int>> que;
    deque<int> dist;
    que.push_back(pos);
    dist.push_back(0);
    visited[pos.first][pos.second] = true;

    int eat = 0;
    int cnt = 0;
    pair<int,int> nxt;
    int nxt_dist = -1;

    while(nxt_dist!=-1 || !que.empty()){
        int a, b, dst;
        if(que.empty()){
            dst = nxt_dist+1;
        }
        else{
            a = que.front().first;
            b = que.front().second;
            dst = dist.front();
            que.pop_front();
            dist.pop_front();
        }

        if(nxt_dist!=-1 && dst>nxt_dist){
            //cout<<"\n("<<++cc<<")\tsize: "<<sz<<"\tcnt:"<<cnt+dst<<'\n';
            //PrintVec(vec,a,b);
            
            eat++;
            if(eat==sz){
                // 크기 갱신
                sz++;
                eat = 0;
            }
            // 이동거리 갱신
            cnt+=nxt_dist;
            // 현재위치 갱신
            pos.first = nxt.first;
            pos.second = nxt.second;
            // 좌표값 갱신
            vec[nxt.first][nxt.second] = 0;
            
            // bfs 초기화
            que.clear();
            dist.clear();
            visited.assign(n,vector<bool>(n,false));
            nxt_dist = -1;

            // 현재위치 root으로 push
            que.push_back(nxt);
            dist.push_back(0);
            visited[nxt.first][nxt.second] = true;
            continue;
        }

        if(vec[a][b]!=0 && vec[a][b]<sz){
            if(nxt_dist == -1 
            || a<nxt.first
            || (a==nxt.first && b<nxt.second)){
                nxt_dist = dst;
                nxt.first = a;
                nxt.second = b;
            }
        }

        for(int i = 0; i<4; i++){
            int na = a+dir_x[i];
            int nb = b+dir_y[i];
            if(na>=0 && na<n
            && nb>=0 && nb<n
            && !visited[na][nb]
            && vec[na][nb]<=sz){
                que.push_back({na,nb});
                dist.push_back(dst+1);
                visited[na][nb] = true;
            }
        }
    }

    if(nxt_dist!=-1){
        cnt+=nxt_dist;
    }

    cout<<cnt;
}