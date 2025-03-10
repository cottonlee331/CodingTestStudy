// 백준 1516 

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> vec(n+1,vector<int>());
    vector<int> in_cnt(n+1,0);
    vector<int> max_time(n+1,0);
    vector<int> bld_time(n+1);
    for(int i = 1; i<n+1; i++){
        int time,tmp;
        cin>>time>>tmp;
        bld_time[i] = time;
        while(tmp!=-1){
            vec[tmp].push_back(i);
            in_cnt[i]++;
            cin>>tmp;
        }
    }

    int node_cnt = n;
    while(node_cnt>0){
        for(int k = 1; k<n+1; k++){
            if(in_cnt[k]==0){
                in_cnt[k] = -1;
                node_cnt--;
                for(int p = 0; p<vec[k].size(); p++){
                    in_cnt[vec[k][p]]--;
                    max_time[vec[k][p]] = max(max_time[k]+bld_time[k],max_time[vec[k][p]]);
                }
            }
        }
    }

    for(int q = 1; q<n+1; q++){
        cout<<bld_time[q]+max_time[q]<<'\n';
    }
}