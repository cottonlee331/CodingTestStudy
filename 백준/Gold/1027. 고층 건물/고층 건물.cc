#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = -1;
    cin>>n;
    vector<int> building(n,0);
    for(int i = 0; i<n; i++){
        cin>>building[i];
    }
    int result = 0;
    for(int j = 0; j<n; j++){
        int cnt = 0;
        for(int k = 0; k<n; k++){
            if(j==k){
                continue;
            }
            int start = min(j,k);
            int end = max(j,k);
            double slp = double(building[end]-building[start])/double(end-start);
            bool visible = true;
            for(int a = start+1; a<end; a++){
                double tmp = double(building[a]-building[start])/double(a-start);
                if(slp<=tmp){
                    visible = false;
                    break;
                }
            }
            if(visible){
                cnt++;
            }
        }
        result = max(result,cnt);
    }
    cout<<result;
}