#include <iostream>

#define MAX 1024*1024-1

using namespace std;

int bitMasking(string func, int set, int x) {
	int x_bin = 1 << (x - 1);
	if (func == "add") {
		set |= x_bin;
	}
	else if (func == "remove") {
		set &= (MAX ^ x_bin);
	}
	else if (func == "toggle") {
		set ^= x_bin;
	}
	else if (func == "all") {
		set = MAX;
	}
	else if (func == "empty") {
		set = 0;
	}
	return set;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, set = 0;
	string func;
	int x, chk;

	cin >> m;
	while (m--) {
		cin >> func;
		if (func == "all" || func == "empty") {
			x = 0;
		}
		else {
			cin >> x;
			if (func == "check") {
				chk = set & (1 << (x - 1)) ? 1 : 0;
				cout << chk << '\n';
				continue;
			}
		}
		set = bitMasking(func, set, x);
	}
}