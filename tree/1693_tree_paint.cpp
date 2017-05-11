#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

#define MAX_SIZE	100000
#define MAX			10000000
#define MAX_LOG		17
#define NOT_INIT	-1

int cost[MAX_SIZE + 1][MAX_LOG];
int color_num;

vector< vector<int> > tree;

int min3(int a, int b, int c) {
	int temp = a;

	if (temp > b) {
		temp = b;
	}

	if (temp > c) {
		temp = c;
	}

	return temp;
}

int dfs(int idx, int color, int parent) {
	int child, temp, min;

	if (cost[idx][color] != NOT_INIT) {
		return cost[idx][color];
	}

	cost[idx][color] = color + 1;

	for (int i = 0; i < tree[idx].size(); i++) {

		min = MAX;
		child = tree[idx][i];

		if (child == parent) {
			continue;
		}


		for (int i = 0; i < color_num; i++) {
			if (i != color) {
				temp = dfs(child,i,idx);

				if (min > temp) {
					min = temp;
				}
			}
		}

		cost[idx][color] += min;
	}

	return cost[idx][color];
}

int main() {

	int N;
	int a,b;
	int ans = MAX;
	int temp2;
	scanf("%d",&N);

	float temp = log((float)N) / log(2.0);

	if ((float)color_num != temp) {
		color_num = (int)temp + 1;
	} else {
		color_num = (int)temp;
	}

	tree.resize(N + 1);

	for (int i = 1; i < N; i++) {
		scanf("%d %d",&a,&b);

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < color_num; j++) {
			cost[i][j] = NOT_INIT;
		}
	}

	for (int i = 0; i < color_num; i++) {
		temp2 = dfs(1,i,-1);

		if (ans > temp2) {
			ans = temp2;
		}
	}

	printf("%d\n",ans);

	return 0;
}