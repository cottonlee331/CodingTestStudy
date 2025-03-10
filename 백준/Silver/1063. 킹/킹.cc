// 1063.cpp

#include <iostream>
#include <vector>

using namespace std;
typedef pair<char, int> position;

position moveToken(position pos_start, string move){
    position pos_finish = pos_start;
    for( int i = 0; i<move.size();i++){
        switch (move[i])
        {
        case 'R':
            pos_finish.first+=1;
            break;
        case 'L':
            pos_finish.first-=1;
            break;
        case 'B':
            pos_finish.second-=1;
            break;
        case 'T':
            pos_finish.second+=1;
            break;
        default:
            break;
        }

        if('A'<=pos_finish.first && pos_finish.first<='H' && 1<=pos_finish.second && pos_finish.second<=8){
            continue;
        }

        return pos_start;
    }
    return pos_finish;
}

pair <position, position> getPosition(vector<string> moves, position pos_king, position pos_stone){

    for (int i=0; i<moves.size();i++){
        if(moveToken(pos_king,moves[i])==pos_king){
            continue;
        }

        if(moveToken(pos_king,moves[i])==pos_stone){
            if(moveToken(pos_stone,moves[i])==pos_stone){
                continue;
            }
            pos_stone = moveToken(pos_stone,moves[i]);
        }
        pos_king = moveToken(pos_king,moves[i]);
    }
    return make_pair(pos_king,pos_stone);
}

int main(){
    position pos_king, pos_stone;
    int n = 0;
    string init_king, init_stone;

    cin>> init_king >> init_stone>>n;
    pos_king = make_pair(init_king[0], init_king[1]-'0');
    pos_stone = make_pair(init_stone[0], init_stone[1]-'0');
    
    vector <string> moves(n);
    for (int i =0; i<moves.size();i++){
        cin>>moves[i];
    }

    pair <position, position> result = getPosition(moves,pos_king,pos_stone);
    cout<<result.first.first<<result.first.second<<'\n';
    cout<<result.second.first<<result.second.second;
}