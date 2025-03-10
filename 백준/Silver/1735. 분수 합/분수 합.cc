#include <iostream>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b) {
		a%= b;
		swap(a, b);
	}
	return a;
}

pair <int, int> getFractionSum(pair<int, int> a, pair<int, int> b) {
	int numerator(a.first * b.second + b.first * a.second), denominator(a.second * b.second);
	pair <int, int> fraction_sum;
	int gcd(getGCD(numerator, denominator));
	fraction_sum.first = numerator / gcd;
	fraction_sum.second = denominator / gcd;
	return fraction_sum;
}

int main() {
	pair <int,int> a, b;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;

	pair <int,int> frac;
	frac = getFractionSum(a, b);
	cout << frac.first << ' ' << frac.second << '\n';



}
