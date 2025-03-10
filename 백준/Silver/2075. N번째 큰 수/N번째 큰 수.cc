// 2075.cpp

#include <iostream>
#include <vector>
#include <queue>

#define MIN -1*10000000000

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, tmp;
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> que;
    for (int a = 0; a < n; a++) {
        cin>>tmp;
        que.push(tmp);
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if(que.top()<tmp){
                que.push(tmp);
                que.pop();
            }
        }
    }

    cout << que.top()<<endl;
}