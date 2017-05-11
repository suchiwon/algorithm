#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

#define MAX 9999999999

vector< pair<int, int> > arr;
vector< pair<int, int> > candidate;

using namespace std;

long long get_length(pair<int, int> a, pair<int ,int> b) {
	int x = a.first - b.first;
	int y = a.second - b.second;
	return (x * x) + (y * y);
}

bool x_sort(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) {
		return true;
	} else {
		return false;
	}
}

bool y_sort(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) {
		return true;
	} else {
		return false;
	}
}

int main() {
	
	int N;
	int x,y;
	int ans;
	int diff, bound, dist;
	pair<int, int> min_point;
	pair<int, int> max_point;
	pair<int, int> upper;
	pair<int, int> lower;

	min_point.first = -MAX;
	max_point.first = MAX;

	vector< pair<int, int> >::iterator iter;

	scanf("%d",&N);

	arr.resize(N + 1);

	for (int i = 0; i < N; i++) {
		scanf("%d %d",&x,&y);

		arr[i] = std::make_pair(x,y);
	}

	std::sort(arr.begin(), arr.end(), x_sort);

	candidate.push_back(arr[0]);
	candidate.push_back(arr[1]);

	ans = get_length(arr[0], arr[1]);

	for (int i = 2; i < N; i++) {
		for (iter = candidate.begin(); iter != candidate.end();) {
			diff = arr[i].first - (*iter).first;

			if (diff * diff > ans) {
				iter = candidate.erase(iter);
			} else {
				iter++;
			}
		}
 
		std::sort(candidate.begin(), candidate.end(), y_sort);

		bound = sqrt((double)ans) + 1;

		min_point.second = arr[i].second - bound;
		max_point.second = arr[i].second + bound;

		lower = std::lower_bound(candidate.begin(),candidate.end(),min_point,y_sort);
		upper = std::upper_bound(candidate.begin(),candidate.end(),max_point,y_sort);

		for (iter = lower; iter != upper; iter++) {
			dist = get_length(arr[i],(*Iter));

			if (dist < ans) {
				ans = dist;
			}
		}

		candidate.push_back(arr[i]);
	}

	printf("%d\n",ans);

	return 0;
}