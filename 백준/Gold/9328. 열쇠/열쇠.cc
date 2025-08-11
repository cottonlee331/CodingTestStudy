#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dr = {-1,1,0,0};
vector<int> dc = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int a = 0; a<n; a++){
        int h, w;
        cin>>h>>w;
        vector<vector<char>> vec(h,vector<char>(w));
        vector<pair<int,int>> enter;
        vector<vector<bool>> visit(h,vector<bool>(w,false));
        vector<bool> key(26);
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                cin>>vec[i][j];
                if((i==0 || i==h-1 || j==0 || j==w-1)&&vec[i][j]!='*'){
                    enter.push_back({i,j});
                }
            }
        }
        string tmp;
        cin>>tmp;
        for(int p = 0; p<tmp.size(); p++){
            if(tmp[p]=='0'){
                break;
            }
            if(tmp[p]-'a'<26){
                key[tmp[p]-'a'] = true;
            }
        }

        bool loop = true;
        int ans = 0;
        while(loop){
            loop = false;
            visit.assign(h,vector<bool>(w,false));
            queue<pair<int,int>> q;
            for(int k = 0; k<enter.size();k++){
                int r = enter[k].first;
                int c = enter[k].second;
                if(0<=vec[r][c]-'A' && vec[r][c]-'A'<26){   // 대문자
                    if(key[vec[r][c]-'A']){ // 문 열림
                        vec[r][c] = '.';
                    }
                    else{
                        continue;
                    }
                }
                else if(0<=vec[r][c]-'a' && vec[r][c]-'a'<26){  // 소문자
                    key[vec[r][c]-'a'] = true;
                    vec[r][c] = '.';
                }
                else if(vec[r][c]=='$'){    // 문서
                    ans++;
                    vec[r][c] = '.';
                }
                // 빈공간 포함 출입가능 모든 입구에 대해
                q.push({r,c});
                visit[r][c] = true;
            }

            // bfs
            while(!q.empty()){
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                for(int u = 0; u<4; u++){
                    int nr = cr+dr[u];
                    int nc = cc+dc[u];
                    if(0<=nr && nr<h && 0<=nc && nc<w 
                        && !visit[nr][nc] && vec[nr][nc]!='*'){
                            if(0<=vec[nr][nc]-'A' && vec[nr][nc]-'A'<26){   // 대문자
                                if(key[vec[nr][nc]-'A']){ // 문 열림
                                    vec[nr][nc] = '.';
                                }
                                else{
                                    continue;
                                }
                            }
                            else if(0<=vec[nr][nc]-'a' && vec[nr][nc]-'a'<26){  // 소문자
                                key[vec[nr][nc]-'a'] = true;
                                vec[nr][nc] = '.';
                                loop = true;
                            }
                            else if(vec[nr][nc]=='$'){    // 문서
                                ans++;
                                vec[nr][nc] = '.';
                            }
                            q.push({nr,nc});
                            visit[nr][nc] = true;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}