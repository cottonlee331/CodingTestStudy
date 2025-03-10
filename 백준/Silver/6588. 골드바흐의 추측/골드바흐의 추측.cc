#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <bool> getPrime(int n){
    vector <bool> primes(n+1,true);
    primes[0] = primes[1] = false;
    for(int i = 2; i<sqrt(n); i++){
        if(!primes[i]){
            continue;
        }
        for (int j = i*i; j<=n;j+=i){
            primes[j]=false;
        }
    }
    return primes;
}

pair <int,int> isGoldbach(int n, vector <bool> &primes){
    for (int i = 3; i<=n/2; i+=2){
        if(primes[i]&&primes[n-i]){
            return make_pair(i,n-i);
        }
    }

    return make_pair(-1,-1);
}

int main(){
    vector <int> vec;
    int n(0), m(0);
    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        if(n>m){
            m = n;
        }
        vec.push_back(n);
    }

    vector <bool> prime_vec = getPrime(m);
    pair <int,int> gold_pair;

    for(int i = 0; i<vec.size();i++){
        gold_pair = isGoldbach(vec[i],prime_vec);
        if(gold_pair.first == -1){
            cout<<"Goldbach's conjecture is wrong.\n";
            continue;
        }
        cout<<vec[i]<<" = "<<gold_pair.first<<" + "<<gold_pair.second<<'\n';

    }

}