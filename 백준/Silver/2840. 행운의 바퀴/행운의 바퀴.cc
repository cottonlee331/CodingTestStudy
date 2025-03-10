#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <char> getRoulette(int n, vector<pair<int, char>> rec) {
	vector <char> roulette(n, '?');
	int idx_rlt(0);
	for (int i = rec.size() - 1; i >= 0; i--) {
		if (roulette[idx_rlt] != '?' && roulette[idx_rlt] != rec[i].second) {
			roulette.clear();
			roulette.push_back('!');
			break;
		}
		roulette[idx_rlt] = rec[i].second;
		idx_rlt +=rec[i].first;
		idx_rlt %= n;
		if (1<count(roulette.begin(), roulette.end(), rec[i].second)) {
			roulette.clear();
			roulette.push_back('!');
			break;
		}
	}
	return roulette;
}

int main() {
	int n(0), k(0);
	cin >> n >> k;
	vector<pair<int, char>> rec(k);
	for (int i = 0; i < k; i++) {
		cin >> rec[i].first >> rec[i].second;
	}
	vector <char> rulet = getRoulette(n, rec);
	for (auto a : rulet) {
		cout << a;
	}
	cout << '\n';
}
