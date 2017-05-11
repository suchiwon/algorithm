#include <stdio.h>
#include <list>
#include <vector>

#define MAX_SIZE 1000
#define NOT_INIT -1

using namespace std;

int val[MAX_SIZE + 1];
int mem[MAX_SIZE + 1];
vector< list<int> > techtree;

int bfs(int idx) {

	if (mem[idx] != NOT_INIT) {
		return mem[idx];
	}

	list<int>::iterator iter;

	int max = 0, temp;

	for (iter = techtree[idx].begin(); iter != techtree[idx].end(); iter++) {
		temp = bfs((*iter));
		if (max < temp) {
			max = temp;
		}
	}

	mem[idx] = max + val[idx];

	return mem[idx];
}

int main() {
	int T;
	int n,m,start,end, W, ans;

	scanf("%d",&T);

	while (T--) {

		scanf("%d %d",&n,&m);

		techtree.clear();
		techtree.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			scanf("%d",&val[i]);
			mem[i] = NOT_INIT;
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d",&start,&end);

			techtree[end].push_back(start);
		}

		scanf("%d",&W);

		ans = bfs(W);

		printf("%d\n",ans);
	}

	return 0;
}
