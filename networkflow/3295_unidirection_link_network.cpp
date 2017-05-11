#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_SIZE 1000
#define NOT_INIT -1

using namespace std;

vector< vector<int> > graph;
bool is_visited[MAX_SIZE + 1];
int matched[MAX_SIZE + 1];

bool match(int idx) {
	
	if(is_visited[idx]) {
		return false;
	} else {
		is_visited[idx] = true;

		for(int i = 0; i < graph[idx].size(); i++) {
			
			if(matched[graph[idx][i]] == NOT_INIT || match(matched[graph[idx][i]])) {
				matched[graph[idx][i]] = idx;

				return true;
			}
		}
		return false;
	}
}

int main() {
	int T;
	int n, m;
	int u, v;
	int ans;

	scanf("%d",&T);

	while(T--){
		graph.clear();
		ans = 0;

		scanf("%d %d",&n, &m);

		graph.resize(n);

		for(int i = 0; i < m; i++) {
			scanf("%d %d",&u, &v);

			graph[u].push_back(v);
		}

		memset(matched,NOT_INIT,sizeof(matched));

		for(int i = 0; i < n; i++) {
			memset(is_visited,false,sizeof(is_visited));

			if(match(i)) {
				ans++;
			}
		}
		
		printf("%d\n",ans);
	}

	return 0;
}