#include <stdio.h>

#define MAX_SIZE 100

int x_move[4] = {1,-1,0,0};
int y_move[4] = {0,0,1,-1};

int grid[MAX_SIZE + 1][MAX_SIZE + 1];
int cost[MAX_SIZE + 1][MAX_SIZE + 1];

int H,W;

void dfs(int h, int w) {

	for (int i = 0; i < 4; i++) {
		int x = w + x_move[i];
		int y = h + y_move[i];

		if (y >= 1 && y <= H && x >= 1 && x <= W) {
			if (grid[y][x] == 1 && cost[y][x] > cost[h][w] + 1) {
				cost[y][x] = cost[h][w] + 1;
				dfs(y,x);
			}
		}
	}	
}

int main() {
	char temp[MAX_SIZE + 1];
	scanf("%d %d",&H,&W);

	for (int i = 1; i <= H; i++) {
		scanf("%s",temp);
		for (int j = 0; j < W; j++) {
			if (temp[j] == '0') {
				grid[i][j+1] = 0;
			} else {
				grid[i][j+1] = 1;
			}
			cost[i][j+1] = 100000;
		}
	}

	cost[1][1] = 1;

	dfs(1,1);

	printf("%d\n",cost[H][W]);

	return 0;
}