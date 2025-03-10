// 18111.cpp
// 반례: https://www.acmicpc.net/board/view/86190

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair <int,int> landGrading(vector<int> land, int b){
    int time=0,lv;
    int get = 0, put = 0, bag = b;
    
    sort(land.begin(), land.end());

    if(land[0]==256){
        return make_pair(0,256);
    }
    else if(land[land.size()-1]==0){
        return make_pair(0,0);
    }

    for(int l = 0; l<=256; l++){
        bag = b;
        get = 0;
        put = 0;
        for(int i = 0; i<land.size(); i++){
            if(land[i]>l){
                get += (land[i]-l);
                bag += (land[i]-l);
            }
            else if(land[i]<l){
                put += (l-land[i]);
                bag -= (l-land[i]);
            }
        }

        if(bag<0){
            continue;
        }

        if(time == 0 || time>=get*2+put){
            time = get*2+put;
            lv = l;
        }

    }

    return make_pair(time,lv);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, b;
    cin>>n>>m>>b;
    vector <int> land(n*m);

    for(int i = 0; i<land.size(); i++){
        cin>>land[i];
    }

    pair<int,int> result = landGrading(land, b);
    cout<<result.first<<' '<<result.second;
    
}