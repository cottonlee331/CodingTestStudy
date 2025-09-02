#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

double GetDist(pair<double,double> a, pair<double,double> b){
    double res = 0;
    res = sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    priority_queue<pair<double,int>, vector<pair<double,int>>,greater<pair<double,int>>> que;
    vector<pair<double,double>> vec(n);
    vector<bool> visited(n,false);

    for(int i = 0; i<n; i++){
        cin>>vec[i].first>>vec[i].second;
    }

    double sum = 0;
    que.push({0,0});
    while(!que.empty()){
        int a = que.top().second/1000;
        int b = que.top().second%1000;
        double dst = que.top().first;
        que.pop();
        if(visited[b]){
            continue;
        }
        visited[b] = true;
        for(int j = 0; j<n; j++){
            if(!visited[j]){
                que.push({GetDist(vec[b],vec[j]),b*1000+j});
            }
        }
        sum+=dst;
    }

    cout.precision(3);
    cout<<sum;
}