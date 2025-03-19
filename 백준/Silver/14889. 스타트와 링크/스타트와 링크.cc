#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 1000000000

using namespace std;

int n;
vector<vector<int>> vec;
vector<int> start;
int start_pw = 0;
vector<int> link;
int link_pw = 0;

int diff = INF;

void BuildTeam(int idx){
    if(idx==n){
        diff = min(diff,abs(start_pw-link_pw));
        return;
    }
    else if(start.size()>n/2 || link.size()>n/2){
        return;
    }

    int sum = 0;
    if(start.size()<n/2){
        start.push_back(idx);
        for(int i = 0; i<start.size(); i++){
            sum+=vec[idx][start[i]]+vec[start[i]][idx];
        }
        start_pw+=sum;
        BuildTeam(idx+1);
        start.pop_back();
        start_pw-=sum;
    }

    sum = 0;
    if(link.size()<n/2){
        link.push_back(idx);
        for(int j = 0; j<link.size(); j++){
            sum+=vec[idx][link[j]]+vec[link[j]][idx];
        }
        link_pw+=sum;
        BuildTeam(idx+1);
        link.pop_back();
        link_pw-=sum;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    vec.assign(n,vector<int>(n,0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>vec[i][j];
        }
    }

    BuildTeam(0);
    cout<<diff;

}