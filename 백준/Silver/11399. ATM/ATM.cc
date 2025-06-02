#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> p(n);
    for(int i = 0; i<n; i++){
        cin>>p[i];
    }

    sort(p.begin(),p.end());
    int sum = p[0];
    int wating = p[0];
    for(int j = 1; j<n; j++){
        wating += p[j];
        sum +=wating;
    }
    cout<<sum;
}