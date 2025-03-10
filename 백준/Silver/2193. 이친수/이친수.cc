// 백준 2193

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<long long> one(n+1);
    vector<long long> zero(n+1);

    one[1] = 1;
    zero[1] = 0;

    for(int i = 2; i<n+1; i++){
        one[i] = zero[i-1];
        zero[i] = zero[i-1]+one[i-1];
    }

    cout<<zero[n]+one[n];

}