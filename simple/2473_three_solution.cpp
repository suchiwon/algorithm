#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100000
#define MAX 0x5fffffffffffff

vector<long long> arr;

int main() {
	int N;
	long long min = MAX;
	long long min_val_a, min_val_b, min_val_c;

	scanf("%d",&N);
	
	arr.resize(N);

	int left_idx = 0, right_idx = N - 1;

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	std::sort(arr.begin(), arr.end());

	while (left_idx < right_idx) {
		long long temp = arr[left_idx] + arr[right_idx];

		for (int i = left_idx + 1; i < right_idx; ++i) {
			if (abs((long)(temp + arr[i])) < min) {
				min = abs((long)(temp + arr[i]));
				min_val_a = arr[left_idx];
				min_val_b = arr[i];
				min_val_c = arr[right_idx];
			}
		}

		if (temp > 0) {
			right_idx--;
		} else {
			left_idx++;
		}
	}

	printf("%lld %lld %lld\n",min_val_a, min_val_b, min_val_c);

	return 0;
}