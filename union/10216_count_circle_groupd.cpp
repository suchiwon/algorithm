#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_SIZE 3000

int parent[MAX_SIZE + 1];

typedef struct {
	int x;
	int y;
	int r;
} circle;

vector<circle> arr;

int _find(int idx) {
	
	if (idx == parent[idx]) {
		return idx;
	}

	return _find(parent[idx]);
}

void _union(int u, int v) {
	u = _find(u);
	v = _find(v);

	if (u != v) {
		parent[u] = v;
	}
}

void checkCollision(int a, int b) {
	circle c1 = arr[a];
	circle c2 = arr[b];

	int d = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
	int rad = (c1.r + c2.r) * (c1.r + c2.r);

	if (d <= rad) {
		_union(a, b);
	}
}

int main() {
	int N, T;
	int ans = 0;
	circle c;

	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);

		ans = 0;
		arr.clear();

		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < N; i++) {
			scanf("%d %d %d",&c.x, &c.y, &c.r);
			arr.push_back(c);
		}

		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				checkCollision(i,j);
			}
		}

		for (int i = 0; i < N; i++) {
			if (i == _find(i)) {
				ans++;
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}