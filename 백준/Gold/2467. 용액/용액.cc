#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<long long> vec(n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    int neg = 0;
    int pos = n-1;
    long long minsum = abs(vec[neg]+vec[pos]);
    int ans_n = 0;
    int ans_p = n-1;
    while(neg<pos){
        long long sum = vec[neg]+vec[pos];
        if(minsum>=abs(sum)){
            ans_n = neg;
            ans_p = pos;
            minsum = abs(sum);
        }
        if(sum>0){
            pos--;
        }
        else if(sum<0){
            neg++;
        }
        else{
            break;
        }
    }
    cout<<vec[ans_n]<<' '<<vec[ans_p];
}