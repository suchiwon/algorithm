#include <iostream>
#include <fstream>

using namespace std;

void main() {
	int test_size, case_num = 0;
	long long N, K, count, get_length;

	long long big_length, small_length;
	long long big_size, small_size;

	long long big_length_saver, small_length_saver;
	long long big_size_saver, small_size_saver;

	ifstream in("in.txt");
	ofstream out("suchiwon.txt");

	in >> test_size;

	while (case_num < test_size) {

		case_num++;

		in >> N >> K;

		count = 1;
		get_length = 0;

		if (N%2 == 0) {
			big_length = N/2;
			big_size = 1;
			small_length = N/2 - 1;
			small_size = 1;
		} else {
			big_length = N/2;
			big_size = 2;
			small_length = N/2;
			small_size = 0;
		}

		if (K == 1) {
			out << "Case #" << case_num << ": " << big_length << " " << small_length << endl;
			continue;
		}

		while (count < K) {
			count += big_size;

			if (count >= K) {
				get_length = big_length;
				break;
			} else {
				if (big_length%2 == 0) {
					big_length_saver = big_length/2;
					big_size_saver = big_size;
					small_length_saver = big_length/2 - 1;
					small_size_saver = big_size;
				} else {
					big_length_saver = big_length/2;
					big_size_saver = big_size * 2;
					small_length_saver = big_length_saver - 1;
					small_size_saver = 0;
				}
			}

			count += small_size;

			if (count >= K) {
				get_length = small_length;
				break;
			} else {
				if (small_length%2 == 0) {
					big_size_saver += small_size;
					small_size_saver += small_size;
				} else {
					small_size_saver += small_size * 2;
				}
			}

			big_length = big_length_saver;
			big_size = big_size_saver;
			small_length = small_length_saver;
			small_size = small_size_saver;
		}

		if (get_length%2 == 0) {
			out << "Case #" << case_num << ": " << get_length/2 << " " << get_length/2 - 1 << endl;
		} else {
			out << "Case #" << case_num << ": " << get_length/2 << " " << get_length/2 << endl;
		}
	}
}