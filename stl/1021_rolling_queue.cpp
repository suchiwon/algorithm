#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	int m,n, ans = 0;
	int temp, idx;

	scanf("%d %d",&n,&m);

	arr.resize(n);

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d",&temp);

		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == temp) {
				idx = j;
				break;
			}
		}

		if (idx <= arr.size() - 1 - idx) {
			ans += idx;
			for (int j = 0; j < idx; j++) {
				temp = arr[0];
				arr.erase(arr.begin());
				arr.push_back(temp);
			}

			arr.erase(arr.begin());
		} else {
			ans += arr.size() - idx;

			for (int j = 0; j < arr.size() - 1 - idx; j++) {
				temp = arr.back();
				arr.pop_back();
				arr.insert(arr.begin(),temp);
			}

			arr.pop_back();
		}
	}

	printf("%d\n",ans);

	return 0;

}