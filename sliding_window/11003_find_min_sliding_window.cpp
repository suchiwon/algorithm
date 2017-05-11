#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr;
priority_queue<int> sliding_window;

int main() {
	int N, K;

	scanf("%d %d",&N,&K);

	arr.resize(N + 1);

	for (int i = 0; i < N; i++) {
		scanf("%d",&arr[i]);

		sliding_window.push(
	}

	for (int i = 0; i < K; i++) {
		sliding_window.insert(arr[i]);
		printf("%d ",*sliding_window.begin());
	}

	for (int i = K; i < N; i++) {
		sliding_window.erase(sliding_window.find(arr[i - K]));
		sliding_window.insert(arr[i]);
		printf("%d ",*sliding_window.begin());
	}

	return 0;
}