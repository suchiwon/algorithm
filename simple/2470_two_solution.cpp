#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100000
#define MAX 2000000001

vector<int> arr;

int main() {
	int N;
	int min = MAX;
	int min_val_a, min_val_b;

	scanf("%d",&N);
	
	arr.resize(N);

	int left_idx = 0, right_idx = N - 1;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	std::sort(arr.begin(), arr.end());

	while (left_idx < right_idx) {
		int temp = arr[left_idx] + arr[right_idx];

		if (temp == 0) {
			min_val_a = arr[left_idx];
			min_val_b = arr[right_idx];
			break;
		} else if (abs(temp) < min) {
			min = abs(temp);

			min_val_a = arr[left_idx];
			min_val_b = arr[right_idx];
		}

		if (temp > 0) {
			right_idx--;
		} else {
			left_idx++;
		}
	}

	printf("%d %d\n",min_val_a, min_val_b);

	return 0;
}