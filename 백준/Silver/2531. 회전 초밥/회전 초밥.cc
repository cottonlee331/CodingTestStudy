// 2531.cpp
#include <iostream>
#include <vector>

using namespace std;

//슬라이딩 윈도우
int sushi(vector<int> trail, int d, int k, int c){
    int cnt = 1, max_cnt = 1;
    int l = 0, r = 0;
    vector<int> sushi_cnt (d+1,0);
    sushi_cnt[c]++;

    while(l<trail.size()){
        if(r-l == k){
            if(sushi_cnt[trail[l]] == 1){
                cnt--;
            }
            sushi_cnt[trail[l]]--;
            l++;
        }

        int r_ind = r%trail.size();
        if(sushi_cnt[trail[r_ind]] == 0){
            cnt++;
        }
        sushi_cnt[trail[r_ind]]++;
        r++;
        if(cnt > max_cnt){
            max_cnt = cnt;
        }

    }
    return max_cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d, k, c;
    cin>> n>> d>> k>> c;

    vector<int> trail (n);

    for(int i = 0; i<n; i++){
        cin>>trail[i];
    }
    cout<<sushi(trail, d, k, c);
}