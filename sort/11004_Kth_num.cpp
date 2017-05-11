#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
	int N, idx;

	scanf("%d %d",&N, &idx);

	arr.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d",&arr[i]);
	}

	std::sort(arr.begin(),arr.end());

	printf("%d\n",arr[idx-1]);

	return 0;
}