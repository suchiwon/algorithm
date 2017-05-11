#include <vector>
#include <stdio.h>
#include <set>

#define NOT_INIT -1
#define INF 1000000

using namespace std;

vector< vector<int> > tree;
vector<int> val_arr;
vector<bool> search_end;

int search(int idx) {
	set<int> child;
	int val = 1, max = 1, min = INF, temp, j;
	set<int>::iterator iter;

	if (search_end[idx] == true) {
		return val_arr[idx];
	} else {
		search_end[idx] = true;

		for (int i = 0; i < tree[idx].size(); i++) {
			temp = search(tree[idx][i]);
			if (temp != NOT_INIT) {
				child.insert(temp);

				if (min > temp) {
					min = temp;
				}

				if (max < temp) {
					max = temp;
				}
			}
		}

		if (child.empty()) {
			val_arr[idx] = 1;
			return 1;
		} else if (child.size() == 1) {
			if ((*child.begin()) == 1) {
				val_arr[idx] = 2;
				return 2;
			} else {
				val_arr[idx] = 1;
				return 1;
			}
		} else {
			if (min > 1) {
				val_arr[idx] = 1;
				return 1;
			} else {
				for (j = min + 1; j < max; j++) {
					if (child.find(j) == child.end()) {
						val_arr[idx] = j;
						return j;
					}
				}

				val_arr[idx] = max + 1;
				return max + 1;
			}
		}
	}
}

int main() {
	int N;
	int start, end, ans = 0;

	scanf("%d",&N);

	tree.resize(N + 1);
	val_arr.resize(N + 1);
	search_end.resize(N + 1);

	for (int i = 1; i < N; i++) {
		scanf("%d %d",&start, &end);

		val_arr[i] = NOT_INIT;
		search_end[i] = false;
	
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	val_arr[N] = NOT_INIT;
	search_end[N] = false;

	search(1);

	for (int i = 1; i <= N; i++) {
		ans += val_arr[i];
	}

	printf("%d\n",ans);

	return 0;
}