#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define IS_TRUE 10

long long pow10[20];

int isTidy(long long n, int idx) {
	vector<int> digits;
	int temp;
	bool bTiny = true;

	while (n != 0) {
		temp = n%10;
		digits.push_back(temp);
		n /= 10;
	}

	if (idx < digits.size() - 1) {
		temp = digits[idx];
	}

	for (int i = digits.size() - 1; i > 0; --i) {
		if (digits[i-1] < digits[i]) {
			bTiny = false;
		}
	}

	if (bTiny == true) {
		temp = IS_TRUE;
	}

	return temp;
}

void main() {
	int t, temp, idx;
	long long n;

	ifstream in("B-large.in");
	ofstream out("B-large.txt");

	pow10[0] = 1;

	for (int i = 1; i < 20; i++) {
		pow10[i] = pow10[i-1] * 10;
	}

	in >> t;

	for (int i = 1; i <= t; ++i) {
		in >> n;

		idx = 0;

		while (true) {
			temp = isTidy(n, idx);
			if (temp == IS_TRUE) {
				out << "Case #" << i << ": " << n << endl;
				break;
			} else {
				n -= (temp + 1) * pow10[idx];
				++idx;
			}
		}
	}
}