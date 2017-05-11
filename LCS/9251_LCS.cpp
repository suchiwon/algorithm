#include <stdio.h>

#define MAX_SIZE 1000
int arr[MAX_SIZE + 1];

int main() {
	char dest[1001];
	char src[1001];
	int dest_size = 0, src_size = 0;

	scanf("%s %s",dest,src);

	while (dest[dest_size] != 0) {
		dest_size++;
	}
	while (src[src_size] != 0) {
		src_size++;
	}

	for (int i = 0; i <= MAX_SIZE; i++) {
		arr[i] = 0;
	}

	for (int i = 0; i < src_size; i++) {
		for (int j = dest_size; j >= 0; j--) {
			if (dest[j] == src[i]) {
				int max = 0;
				for (int k = j - 1; k >= 0; k--) {
					if (max < arr[k]) {
						max = arr[k];
					}
				}

				arr[j] = max + 1;
			}
		}
	}

	int max = 0;

	for (int i = 0; i < MAX_SIZE; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	printf("%d\n",max);

	return 0;
	
}