#include <stdio.h>

#define MAX_SIZE 10000

long long arr[MAX_SIZE + 1];

int main() {
	int N, K;
	scanf("%d %d",&N, &K);

	long long left = 0, right = 0, mid, count;

	for (int i = 0; i < N; i++) {
		scanf("%lld",&arr[i]);

		if (arr[i] > right) {
			right = arr[i];
		}
	}

	while (left <= right) {
		mid = (left + right)/2;


		count = 0;

		for (int i = 0; i < N; i++) {
			count += arr[i]/mid;
		}

		if (count < K) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	printf("%lld\n",right);

	return 0;
}