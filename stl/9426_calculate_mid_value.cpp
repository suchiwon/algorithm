#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> Karr;
vector<int> Kcopy;

multiset< pair<int, int> > Kset;

int main() {
	int N, K;
	scanf("%d %d",&N,&K);

	int count, temp;
	int ans = 0, mid;

	if (K == 1) {
		for (int i = 0; i < N; i++) {
			scanf("%d",&temp);
			ans += temp;
		}

		printf("%d\n",ans);

		return 0;
	}

	multiset< pair<int, int> >::iterator iter;
	Karr.push_back(-1);

	for (int i = 1; i <= K; i++) {
		scanf("%d",&temp);
		Kset.insert(make_pair(temp,i));
		Karr.push_back(temp);
	}

	iter = Kset.begin();

	for (int i = 1; i < (K+1)/2; i++) {
		iter++;
	}

	mid = (*iter).first;

	ans += mid;

	pair<int, int> eraser;

	for (int i = 1; i < (N - K + 1); i++) {
		eraser = make_pair(Karr[i],i);
		scanf("%d",&temp);

		if (K%2 == 0) {
			if((*iter).second == i || eraser.first > (*iter).first) {
				iter--;
			}

			Kset.erase(eraser);

			Kset.insert(make_pair(temp,i+K));
			Karr.push_back(temp);

			if ((*iter).first <= temp) {
				iter++;
			}

			mid = (*iter).first;

			ans += mid;
		} else {
			if((*iter).second == i || eraser.first <= (*iter).first) {
				iter++;
			}

			Kset.erase(eraser);

			Kset.insert(make_pair(temp,i+K));
			Karr.push_back(temp);

			if ((*iter).first > temp) {
				iter--;
			}

			mid = (*iter).first;

			ans += mid;
		}
		
	}

	printf("%d\n",ans);

	return 0;
}