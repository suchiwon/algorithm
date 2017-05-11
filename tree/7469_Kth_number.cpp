#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

vector< vector<int> > segment;
vector<int> arr;

void make_tree(int idx, int start, int end) {
	vector<int> v;

	if (start == end) {
		v.push_back(arr[start]);

		segment[idx] = v;
	} else {
		v.assign(arr.begin() + start, arr.begin() + end + 1);

		std::sort(v.begin(), v.end());

		segment[idx] = v;

		make_tree(idx*2,start,(start+end)/2);
		make_tree(idx*2+1,(start+end)/2+1,end);
	}
}

int main() {
	int n,m;

	int start, end, idx;

	scanf("%d %d",&n,&m);

	arr.resize(n);
	segment.resize(pow(2.0,n+1));

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	make_tree(1,0,n-1);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d",&start,&end,&idx);

		--start;
		--end;
	}

	return 0;
}