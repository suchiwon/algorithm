#include <stdio.h>

#define NONE -1
#define LEFT 0
#define RIGHT 1
#define MAX_SIZE 26

int tree[MAX_SIZE + 1][2];

void prefix (int idx) {

	printf("%c",idx + 'A');

	if (tree[idx][LEFT] != NONE) {
		prefix(tree[idx][LEFT]);
	}

	if (tree[idx][RIGHT] != NONE) {
		prefix(tree[idx][RIGHT]);
	}
}

void postfix (int idx) {

	if (tree[idx][LEFT] != NONE) {
		postfix(tree[idx][LEFT]);
	}

	if (tree[idx][RIGHT] != NONE) {
		postfix(tree[idx][RIGHT]);
	}

	printf("%c",idx + 'A');
}

void infix (int idx) {
	
	if (tree[idx][LEFT] != NONE) {
		infix(tree[idx][LEFT]);
	}

	printf("%c",idx + 'A');

	if (tree[idx][RIGHT] != NONE) {
		infix(tree[idx][RIGHT]);
	}
}

int main() {
	int N;
	int temp;
	char node, left, right;

	scanf("%d",&N);

	for (int i = 0; i < MAX_SIZE; i++) {
		tree[i][LEFT] = NONE;
		tree[i][RIGHT] = NONE;
	}

	for (int i = 0; i < N; i++) {

		fflush(stdin);
		scanf("%c %c %c", &node, &left, &right);

		if (left != '.') {
			tree[node - 'A'][LEFT] = left - 'A';
		}

		if (right != '.') {
			tree[node - 'A'][RIGHT] = right - 'A';
		}
	}

	prefix(0);
	puts("");

	infix(0);
	puts("");

	postfix(0);
	puts("");

	return 0;
}