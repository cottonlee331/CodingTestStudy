// 3079.cpp

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull cntPeople(ull tot_time, vector<ull>&port){
    ull cnt = 0;
    for(int i = 0; i<port.size(); i++){
        cnt+=int(tot_time/port[i]);
    }
    return cnt;
}

ull binarySearch(ull left, ull right, int people, vector<ull>&port){
    while(left<=right){
        ull mid = (left+right)/2;
        ull people_cnt = cntPeople(mid, port);

        if(people_cnt>=people){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return left;
}


int main(){
    int n, m;
    ull min_time = 1000000000;
    // ull max_time = 0;
    cin>>n>>m;
    vector <ull> port(n);
    for (int i = 0; i<n; i++){
        cin>>port[i];
        min_time=min(min_time,port[i]);
        // max_time=max(max_time,port[i]);
    }

    cout<<binarySearch(min_time,min_time*m,m,port);
}