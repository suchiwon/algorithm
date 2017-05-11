#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_SIZE 100000

vector< vector< pair<int, int> > > tree;
bool is_visited[MAX_SIZE + 1] = {false,};
int val[MAX_SIZE + 1] = {0,};
int ans = 0;

int search(int idx) {
	vector<int> val_arr;
	int max = 0, second_max = 0;
	if (is_visited[idx]) {
		return 0;
	}

	is_visited[idx] = true;

	for (int i = 0; i < tree[idx].size(); i++) {
		if (!is_visited[tree[idx][i].first]) {
			int val = search(tree[idx][i].first) + tree[idx][i].second;
				
			if (max < val) {
				second_max = max;
				max = val;
			} else if (second_max < val) {
				second_max = val;
			}
		}
	}

	if (ans < max + second_max) {
		ans = max + second_max;
	}

	return max;
}

int main() {
	int N;
	int idx, jump, depth;
	scanf("%d",&N);

	tree.resize(N + 1);

	for (int i = 0; i < N; i++) {
		scanf("%d",&idx);
				
		while (true) {
			scanf("%d",&jump);

			if (jump == -1) {
				break;
			} else {
				scanf("%d",&depth);

				tree[idx].push_back(std::make_pair(jump,depth));
			}
		}
	}

	search(1);

	printf("%d\n",ans);

	return 0;
}