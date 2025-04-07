#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b, c; 
    cin>>a>>b>>c;

    long long base = a;
    long long ans = 1;
    while(b!=0){
        if(b%2 == 1){
            ans = (ans*base)%c;
            b--;
        }
        base = (base*base)%c;
        b/=2;
    }
    cout<<ans;
}