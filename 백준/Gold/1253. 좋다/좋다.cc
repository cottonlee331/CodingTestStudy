// 백준 1253

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> vec;
    cin>>n;
    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }

    int result = 0;
    bool flag = false;
    sort(vec.begin(),vec.end());
    for(int j = 0; j<n; j++){
        int a = 0;
        int b = n-1;
        while(a<b){
            if(b == j){
                b--;
                continue;
            }
            else if(a==j){
                a++;
                continue;
            }


            if(vec[a]+vec[b] == vec[j]){
                result++;
                break;
            }
            else if( vec[a]+vec[b]>vec[j]){
                b--;
            }
            else{
                a++;
            }
        }
    }
    cout<<result;
}