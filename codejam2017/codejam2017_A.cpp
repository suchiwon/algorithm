#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_SIZE 1000

void main() {
	int t, K, count;
	string pancakes;

	bool is_possible;

	ifstream in("A-large.in");
	ofstream out("A-large.txt");

	in >> t;

	for (int i = 1; i <= t; ++i) {
		in >> pancakes >> K;

		count = 0;
		is_possible = true;

		for (int j = 0; j <= pancakes.size() - K; ++j) {
			if (pancakes[j] == '-') {
				for (int k = j; k < j + K; ++k) {
					if (pancakes[k] == '-') {
						pancakes[k] = '+';
					} else {
						pancakes[k] = '-';
					}
				}

				count++;
			}
		}

		for (int j = 0; j < pancakes.size(); ++j) {
			if (pancakes[j] == '-') {
				is_possible = false;
				break;
			}
		}

		if (is_possible) {
			out << "Case #" << i << ": " << count << endl;
		} else {
			out << "Case #" << i << ": IMPOSSIBLE" << endl;
		}
	}
}