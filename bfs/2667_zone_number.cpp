#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 25

int x_move[4] = {1,-1,0,0};
int y_move[4] = {0,0,1,-1};

int grid[MAX_SIZE + 1][MAX_SIZE + 1];
int zone[MAX_SIZE + 1][MAX_SIZE + 1];

int H,W;

vector<int> num_arr;

void bfs(int h, int w, int idx) {
	num_arr[idx-1]++;
	for (int i = 0; i < 4; i++) {
		int x = w + x_move[i];
		int y = h + y_move[i];

		if (x >= 0 && x < W && y >= 0 && y < H) {
			if (grid[y][x] == 1 && zone[y][x] == 0) {
				zone[y][x] = idx;
				bfs(y,x,idx);
			}
		}
	}
}

int main() {

	int count = 0;
	char temp[26];
	
	scanf("%d",&H);
	W = H;

	for (int i = 0; i < H; i++) {
		scanf("%s",temp);
		for (int j = 0; j < W; j++) {
			if (temp[j] == '0') {
				grid[i][j] = 0;
			} else {
				grid[i][j] = 1;
			}
			zone[i][j] = 0;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (grid[i][j] == 1 && zone[i][j] == 0) {
				num_arr.push_back(0);
				count++;
				zone[i][j] = count;
				bfs(i,j,count);
			}
		}
	}

	std::sort(num_arr.begin(),num_arr.end());

	printf("%d\n",count);

	for (int i = 0; i < num_arr.size(); i++) {
		printf("%d\n",num_arr[i]);
	}

	return 0;

}