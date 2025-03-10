// 백준 2042

#include<iostream>
#include<vector>
#include<cmath>

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
    vector<long long> vec(pow(2,cnt+2));
    for(int i = 0; i<n; i++){
        cin>>vec[root+i];
        int tmp = root+i;
        while(true){
            tmp/=2;
            vec[tmp] += vec[root+i];
            if(tmp == 1){
                break;
            }
        }
    }
    for(int j = 0; j<m+k; j++){
        int a, b;
        long long c;
        cin>>a>>b>>c;
        if(a == 1){
            long long org = vec[root+b-1];
            vec[root+b-1] = c;
            int tmp = root+b-1;
            while(true){
                tmp/=2;
                vec[tmp] = vec[tmp]-org+c;
                if(tmp == 1){
                    break;
                }
            }
        }
        else{
            int start = root+b-1;
            int end = root+c-1;
            long long sum = 0;
            while(start<=end){
                if(start%2 == 1){
                    sum+=vec[start];
                }
                start = (start+1)/2;
                if(end%2 == 0){
                    sum+=vec[end];
                }
                end = (end-1)/2;
            }
            cout<<sum<<'\n';
        }
    }
}