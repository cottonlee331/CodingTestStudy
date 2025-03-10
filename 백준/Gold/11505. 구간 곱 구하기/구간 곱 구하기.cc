// 백준 11505

#include<iostream>
#include<vector>
#include<cmath>

#define MOD 1000000007

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;

    int root = n;
    int cnt = 0;
    while(root>1){
        root/=2;
        cnt++;
    }

    root = pow(2,cnt+1);
    vector<long long> vec(pow(2,cnt+2),1);
    for(int i = 0; i<n; i++){
        cin>>vec[root+i];
        int tmp = root+i;
        while(tmp>1){
            tmp/=2;
            vec[tmp]=(vec[tmp]*vec[root+i])%MOD;
        }
    }

    for(int j = 0; j<m+k; j++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            int idx;
            idx = root+b-1;
            vec[idx] = c;
            while(idx>1){
                int mul1 = idx;
                int mul2;
                if(idx%2==1){
                    mul2 = idx-1;
                }
                else{
                    mul2 = idx+1;
                }
                idx/=2;
                vec[idx] = (vec[mul1]*vec[mul2])%MOD;
            }

        }
        else{
            int start, end;
            start = root+b-1;
            end = root+c-1;
            long long result = 1;
            while(start<=end){
                if(start%2 == 1){
                    result=(result*vec[start])%MOD;
                }
                if(end%2 == 0){
                    result=(result*vec[end])%MOD;
                }
                start = (start+1)/2;
                end = (end-1)/2;
            }
            cout<<result<<'\n';
        }
    }
}