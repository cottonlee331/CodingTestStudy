#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int m;
vector<int> vec;
vector<int> num;


void Backtracking(int n, int idx){
    if(n==m){
        for(int i = 0; i<n; i++){
            cout<<vec[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int j = idx; j<num.size(); j++){
        int nm = num[j];
        vec.push_back(nm);
        Backtracking(n+1,j);
        vec.pop_back();
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>m;
    
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        int tmp; 
        cin>>tmp;
        mp[tmp]++;
        if(mp[tmp]==1){
            num.push_back(tmp);
        }
    }
    sort(num.begin(), num.end());
    Backtracking(0,0);
}
