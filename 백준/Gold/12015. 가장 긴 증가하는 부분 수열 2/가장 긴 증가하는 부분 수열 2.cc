#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> vec(n);
    vector<int> lis;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    int cnt = 1;
    for(int j = 0; j<n; j++){
        if(lis.empty()){
            lis.push_back(vec[j]);
        }
        auto it = lower_bound(lis.begin(),lis.end(),vec[j]);
        if(it==lis.end()){
            lis.push_back(vec[j]);
            cnt++;
        }
        else{
            *it=vec[j];
        }
    }
    cout<<cnt;
}