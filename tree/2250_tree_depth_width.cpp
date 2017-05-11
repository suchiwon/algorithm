#include <stdio.h>

#define MAX_SIZE 10000

#define LEFT 0
#define RIGHT 1
#define NONE -1
#define MIN 0
#define MAX 1
#define MAX_VALUE 1000000

int tree[MAX_SIZE + 1][2];
int count = 1;
int max_depth = 0;
bool is_root[MAX_SIZE + 1];
int level_val[MAX_SIZE + 1][2];

void setRow(int idx, int level) {

	if (tree[idx][LEFT] != NONE) {
		setRow(tree[idx][LEFT], level+1);
	}

	if (level_val[level][MIN] > count) {
		level_val[level][MIN] = count;
	}

	if (level_val[level][MAX] < count) {
		level_val[level][MAX] = count;
	}

	if (max_depth < level) {
		max_depth = level;
	}

	count++;

	if (tree[idx][RIGHT] != NONE) {
		setRow(tree[idx][RIGHT], level+1);
	}
}

int main() {
	int N;
	int node, left, right;
	int level, ans = 0;
	int root;
	scanf("%d",&N);

	for (int i = 0; i <= MAX_SIZE; i++) {
		level_val[i][MIN] = MAX_VALUE;
		level_val[i][MAX] = 0;
		is_root[i] = true;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d",&node,&left,&right);

		tree[node][LEFT] = left;
		tree[node][RIGHT] = right;

		if (left != NONE)
			is_root[left] = false;

		if (right != NONE)
			is_root[right] = false;
	}

	for (int i = 1; i <= N; i++) {
		if (is_root[i]) {
			root = i;
			break;
		}
	}

	setRow(root,0);

	for (int i = 0; i <= max_depth; i++) {
		if (ans < level_val[i][MAX] - level_val[i][MIN] + 1) {
			level = i;
			ans = level_val[i][MAX] - level_val[i][MIN] + 1;
		}
	}

	printf("%d %d\n",level+1,ans);

	return 0;
}