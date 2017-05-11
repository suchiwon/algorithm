#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	vector<int> radix;

	radix.resize(10001);

	int N, temp;

	scanf("%d",&N);

	for (int i =  0; i < N; i++) {
		scanf("%d",&temp);

		radix[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < radix[i]; j++) {
			printf("%d\n",i);
		}
	}

	return 0;
}