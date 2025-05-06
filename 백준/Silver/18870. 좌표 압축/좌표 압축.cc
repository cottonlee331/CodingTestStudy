#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> vec(n,0);
    vector<int> srt(n,0);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        srt[i] = vec[i];
    }
    sort(srt.begin(),srt.end());
    map<int,int> mp;
    int idx = 1;
    for(int j = 0; j<n; j++){
        if(!mp[srt[j]]){
            mp[srt[j]] = idx;
            idx++;
        }
    }
    for(int k = 0; k<n; k++){
        cout<<mp[vec[k]]-1<<' ';
    }
}