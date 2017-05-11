#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
	int N;
	int ans = 0;
	int diff, idx;

	vector<int> arr;

	scanf("%d",&N);

	for (int i = 1; i <= N; i++) {
		arr.clear();

		idx = i;

		while(idx != 0) {
			arr.push_back(idx%10);
			idx = idx/10;
		}

		if (arr.size() <= 2) {
			ans++;
			continue;
		}

		diff = arr[1] - arr[0];

		for (idx = 2; idx < arr.size(); idx++) {
			if (arr[idx] - arr[idx - 1] != diff) {
				break;
			}
		}

		if (idx == arr.size()) {
			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}