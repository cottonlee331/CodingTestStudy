#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int,int> mp;
vector<int> num;
vector<int> serial;
int m;

void BackTracking(int a){
    if(a==m){
        for(int i = 0; i<m; i++){
            cout<<serial[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int j = 0; j<num.size(); j++){
        int number = num[j];
        if(mp[number]>0){
            mp[number]--;
            serial.push_back(number);
            BackTracking(a+1);
            serial.pop_back();
            mp[number]++;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin>>n>>m;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(mp.find(tmp)==mp.end()){
            mp[tmp] = 1;
            num.push_back(tmp);
        }
        else{
            mp[tmp]++;
        }
    }
    sort(num.begin(),num.end());

    BackTracking(0);
}