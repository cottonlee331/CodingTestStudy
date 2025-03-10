// 백준 11689

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;

    vector<bool> is_prime(sqrt(n)+1,true);

    for(long long j = 2; j<sqrt(n)+1; j++){
        if(!is_prime[j]){
            continue;
        }
        long long k = j*j;
        while(k*j<=sqrt(n)){
            is_prime[k*j] = false;
            k++;
        }
    }

    long long result = 1;

    long long tmp = n;
    for(long long i = 2; i<sqrt(n)+1; i++){
        if(tmp%i==0){
            if(is_prime[i]){
                long long cnt = 0;
                while(tmp%i == 0){
                    cnt++;
                    tmp/=i;
                }
                result*=pow(i,cnt-1)*(i-1);
            }
        }
    }
    if(n!=1 && tmp!=1){
        result*=(tmp-1);
    }
    cout<<result;
}