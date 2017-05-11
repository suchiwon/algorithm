#include <stdio.h>
#include <queue>

#define MAX_SIZE 1000

using namespace std;

int grid[MAX_SIZE + 1][MAX_SIZE + 1];

queue< pair<int, int> > tomato;

int main() {
	int H,W, max = 0;
	bool is_first_full = true;
	scanf("%d %d",&H,&W);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d",&grid[i][j]);

			if (grid[i][j] == 1) {
				tomato.push(make_pair(i,j));
			} else if (grid[i][j] == 0) {
				is_first_full = false;
			}
		}
	}

	if (is_first_full) {
		printf("0\n");
		return 0;
	}

	while (!tomato.empty()) {
		int h = tomato.front().first;
		int w = tomato.front().second;

		if (h > 0) {
			if (grid[h-1][w] == 0) {
				grid[h-1][w] = grid[h][w] + 1;
				tomato.push(make_pair(h-1,w));
			}
		}

		if (h < H -1) {
			if (grid[h+1][w] == 0) {
				grid[h+1][w] = grid[h][w] + 1;
				tomato.push(make_pair(h+1,w));
			}
		}

		if (w > 0) {
			if (grid[h][w-1] == 0) {
				grid[h][w-1] = grid[h][w] + 1;
				tomato.push(make_pair(h,w-1));
			}
		}

		if (w < W - 1) {
			if (grid[h][w+1] == 0) {
				grid[h][w+1] = grid[h][w] + 1;
				tomato.push(make_pair(h,w+1));
			}
		}

		tomato.pop();
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (grid[i][j] == 0) {
				printf("-1\n");
				return 0;
			} else {
				if (max < grid[i][j]) {
					max = grid[i][j];
				}
			}
		}
	}

	if (max > 1) {
		printf("%d\n",max - 1);
	}
	else {
		printf("1\n");
	}
	return 0;
}

