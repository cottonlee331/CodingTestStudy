#include <iostream>
#include <vector>

using namespace std;

int limit, cnt;
vector<bool> vec;

void BackTracking(int n,int count){
    if(count==cnt){
        for(int i = 1; i<limit+1; i++){
            if(vec[i]){
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        return;
    }
    if(n>limit){
        return;
    }
    
    vec[n] = true;
    BackTracking(n+1,count+1);
    vec[n] = false;
    BackTracking(n+1,count);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>limit>>cnt;
    vec.assign(limit+1,false);
    BackTracking(1,0);
}