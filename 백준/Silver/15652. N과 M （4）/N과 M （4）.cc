#include <iostream>
#include <vector>

using namespace std;

int limit, cnt;
vector<int> vec;

void BackTracking(int n,int count){
    if(count==cnt){
        for(int i = 1; i<limit+1; i++){
            for(int j = 0; j<vec[i]; j++){
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        return;
    }
    if(n>limit){
        return;
    }
    
    vec[n]++;
    BackTracking(n,count+1);
    vec[n]--;
    BackTracking(n+1,count);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>limit>>cnt;
    vec.assign(limit+1,0);
    BackTracking(1,0);
}