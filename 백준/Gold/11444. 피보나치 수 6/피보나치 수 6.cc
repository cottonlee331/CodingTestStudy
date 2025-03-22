#include <iostream>
#include <vector>

#define MOD 1000000007
#define Matrix vector<vector<long long>>

using namespace std;

 Matrix MulMatrix(Matrix &a, Matrix &b){
    Matrix result(a.size(),vector<long long>(b[0].size()));
    for(int i = 0; i<result.size(); i++){
        for(int j = 0; j<result[0].size(); j++){
            for(int k = 0; k<result[0].size(); k++){
                result[i][j]+=a[i][k]*b[k][j];
                result[i][j]%=MOD;
            }
        }
    }
    return result;
 }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;

    if(n==1){
        cout<<1; 
        return 0;
    }

    long long a = n-1;
    Matrix result = {{1,0},{0,1}};
    Matrix base = {{1,1},{1,0}};

    while(a>0){
        if(a%2==1){
            result = MulMatrix(result,base);
        }
        base = MulMatrix(base,base);
        a/=2;
    }
    cout<<result[0][0];
}