#include <stdio.h>

#define MAX_SIZE 100000
#define MAX 10000000000

#define min(a,b) a>b?b:a
#define max(a,b) a<b?b:a

long long arr[MAX_SIZE + 1];

long long search(int start, int end) {
	if (start > end) {
		return 0;
	} else if (start == end) {
		return arr[start];
	}

	int mid = (start + end)/2;

	long long max = max(search(start, mid),search(mid+1,end));

	int left = mid;
	int right = mid + 1;

	long long min_height = min(arr[left],arr[right]);

	if (max < min_height * 2) {
		max = min_height * 2;
	}

	while (left > start || right < end) {
		if (left > start && (right == end || arr[left-1] > arr[right+1])) {
			left--;
			min_height = min(min_height, arr[left]);
		} else {
			right++;
			min_height = min(min_height, arr[right]);
		}

		if ((min_height * (right - left + 1)) > max) {
			max = (min_height * (right - left + 1));
		}
	}

	return max;
}

int main() {
	int N = 1;

	while (true) {
		scanf("%d",&N);

		if (N == 0) {
			break;
		}

		for (int i = 1; i <= N; i++) {
			scanf("%lld",&arr[i]);
		}

		long long max = search(1,N);

		printf("%lld\n",max);
	}

	return 0;
}