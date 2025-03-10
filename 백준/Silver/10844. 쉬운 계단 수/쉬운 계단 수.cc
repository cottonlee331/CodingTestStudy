// 백준 10844

#include<iostream>
#include<vector>

#define MOD 1000000000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    vector<vector<int>> vec(10,vector<int>(n+1));

    vec[0][1] = 0;
    for(int a = 1; a<10; a++){
        vec[a][1] = 1;
    }
    for(int i = 2; i<n+1; i++){
        vec[0][i] = vec[1][i-1]%MOD;

        for(int j = 1; j<9; j++){
            vec[j][i] = (vec[j-1][i-1]+vec[j+1][i-1])%MOD;
        }

        vec[9][i] = vec[8][i-1]%MOD;
    }

    long long result = 0;
    for(int k = 0; k<10; k++){
        result+=vec[k][n];
    }
    cout<<result%MOD;
}