//1655.cpp

#include <iostream>
#include <queue>

using namespace std;

int getMiddle(int num, priority_queue<int>& smaller, priority_queue<int, vector<int>, greater<int>>& bigger) {
    if (!bigger.empty() && bigger.top() < num) {
        bigger.push(num);
    }
    else {
        smaller.push(num);
    }
    auto a = smaller.size() - bigger.size();
    while (int(smaller.size()-bigger.size()) > 1) {
        bigger.push(smaller.top());
        smaller.pop();
    }
    while (bigger.size() > smaller.size()) {
        smaller.push(bigger.top());
        bigger.pop();
    }
    return smaller.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    priority_queue<int, vector<int>, greater<int>> bigger;
    priority_queue<int> smaller;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << getMiddle(num, smaller, bigger) << '\n';
    }


}