#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a,b;
    int cnt = 1;
    cin>>a>>b;
    if(a==b){
        cout<<cnt;
        return 0;
    }
    while(a<b){
        cnt++;
        if(b%10 == 1){
            b/=10;
        }
        else if(b%2!=0){
            break;
        }
        else{
            b/=2;
        }
    }
    if(a!=b){
        cout<<-1;
    }
    else{
        cout<<cnt;
    }

}