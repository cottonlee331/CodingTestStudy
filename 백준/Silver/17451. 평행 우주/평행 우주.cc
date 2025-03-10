// 17451.cpp

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long spd, k;
    cin >> n;

    vector<long long> planet(n);
    for (int i = 0; i < n; i++){
        cin >> planet[i];
    }

    spd = planet[n-1];
    for (int j = n-2; j >= 0; j--){
        if (planet[j] >= spd){
            spd = planet[j];
        }

        else if(spd%planet[j]!=0){
            k = (long long)(spd/planet[j])+1;
            spd = planet[j] * k;
        }

    }

    cout << spd;

}