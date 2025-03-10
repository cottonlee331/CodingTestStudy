// 백준 2251

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int acap, bcap, ccap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    struct {
        int a;
        int b;
        int c;
    }typedef Bottle;

    cin>>acap>>bcap>>ccap;
    Bottle bottle;
    bottle.a = 0; 
    bottle.b = 0; 
    bottle.c = ccap;

    queue<Bottle> que;
    que.push(bottle);
    vector<vector<vector<bool>>> visited(acap+1,vector<vector<bool>>(bcap+1,vector<bool>(ccap+1,false)));
    while(!que.empty()){
        Bottle curr = que.front();
        Bottle tmp;
        int pour;
        que.pop();

        //a->b
        pour = min(curr.a,bcap-curr.b);
        tmp.a = curr.a-pour;
        tmp.b = curr.b+pour;
        tmp.c = curr.c;
        if(!visited[tmp.a][tmp.b][tmp.c]){
           que.push(tmp);
           visited[tmp.a][tmp.b][tmp.c] = true;
        }
        //a->c
        pour = min(curr.a,ccap-curr.c);
        tmp.a = curr.a-pour;
        tmp.b = curr.b;
        tmp.c = curr.c+pour;
        if(!visited[tmp.a][tmp.b][tmp.c]){
           que.push(tmp);
           visited[tmp.a][tmp.b][tmp.c] = true;
        }
        //b->a
        pour = min(curr.b,acap-curr.a);
        tmp.a = curr.a+pour;
        tmp.b = curr.b-pour;
        tmp.c = curr.c;
        if(!visited[tmp.a][tmp.b][tmp.c]){
           que.push(tmp);
           visited[tmp.a][tmp.b][tmp.c] = true;
        }
        //b->c
        pour = min(curr.b,ccap-curr.c);
        tmp.a = curr.a;
        tmp.b = curr.b-pour;
        tmp.c = curr.c+pour;
        if(!visited[tmp.a][tmp.b][tmp.c]){
           que.push(tmp);
           visited[tmp.a][tmp.b][tmp.c] = true;
        }
        //c->a
        pour = min(curr.c,acap-curr.a);
        tmp.a = curr.a+pour;
        tmp.b = curr.b;
        tmp.c = curr.c-pour;
        if(!visited[tmp.a][tmp.b][tmp.c]){
           que.push(tmp);
           visited[tmp.a][tmp.b][tmp.c] = true;
        }
        //c->b
        pour = min(curr.c,bcap-curr.b);
        tmp.a = curr.a;
        tmp.b = curr.b+pour;
        tmp.c = curr.c-pour;
        if(!visited[tmp.a][tmp.b][tmp.c]){
           que.push(tmp);
           visited[tmp.a][tmp.b][tmp.c] = true;
        }
    }

    for(int b = visited[0].size()-1; b>=0; b--){
        for(int c = 0; c<visited[0][b].size();c++){
            if(visited[0][b][c]){
                cout<<c<<' ';
            }
        }
    }
}