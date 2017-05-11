#include <stdio.h>

#define MAX_SIZE 100000

int in_order[MAX_SIZE + 1];
int post_order[MAX_SIZE + 1];
int pre_order[MAX_SIZE + 1];
int pre_idx = 0;

void search(int start, int end, int post_start, int post_end) {

	if (post_start > post_end) {
		return;
	}

	pre_order[pre_idx++] = post_order[post_end];

	for (int i = end; i >= start; i--) {
		if (in_order[i] == post_order[post_end]) {
			search(start, i - 1, post_start,post_start + i - 1 - start);
			search(i + 1, end, post_start + i - start, post_end - 1);
		}
	}

	return;
}


int main() {
	int N;

	scanf("%d",&N);

	for (int i = 0; i < N; i++) {
		scanf("%d",&in_order[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d",&post_order[i]);
	}

	search(0, N - 1, 0, N - 1);

	for (int i = 0; i < N; i++) {
		if (i < N - 1)
			printf("%d ",pre_order[i]);
		else
			printf("%d\n",pre_order[i]);
	}

	return 0;
}