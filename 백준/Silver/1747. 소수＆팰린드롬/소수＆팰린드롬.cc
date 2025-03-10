// 백준 1747

#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    while(true){
        if(n<2){
            n = 2;
            continue;
        }
        bool is_prime = true;
        for(int i = 2; i<=sqrt(n); i++){
            if(n%i==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            int tmp=n;
            int pelin = 0;
            while(tmp!=0){
                pelin*=10;
                pelin+=(tmp%10);
                tmp/=10;
            }
            if(pelin==n){
                break;
            }
        }
        n++;
    }
    cout<<n;
}