#include <stdio.h>

#define MAX_SIZE 10000

int arr[MAX_SIZE + 1];

int main() {
	int n,k, temp;

	scanf("%d %d",&n,&k);

	for (int i = 1; i <= k; i++) {
		arr[i] = 0;
	}

	arr[0] = 1;

	for (int i = 0; i < n; i++) {
		scanf("%d",&temp);
		for (int j = 0; j <= k; j++) {
			if (temp <= j) {
				arr[j] += arr[j - temp];
			}
		}
	}

	printf("%d\n",arr[k]);

	return 0;
}