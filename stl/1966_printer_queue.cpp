#include <stdio.h>
#include <list>

using namespace std;

list< pair<int, int> > printer;

int main() {
	int T, N, idx, temp, count;
	int front;
	bool poped;

	list< pair<int, int> >::iterator iter;

	scanf("%d",&T);

	while (T--) {
		scanf("%d %d",&N, &idx);

		count = 1;

		printer.clear();

		for (int i = 0; i < N; i++) {
			scanf("%d",&temp);

			printer.push_back(make_pair(temp,i));
		}

		while (!printer.empty()) {
			front = (*printer.begin()).first;

			poped = true;

			for (iter = printer.begin(); iter != printer.end(); ++iter) {
				if ((*iter).first > front) {
					printer.push_back(make_pair(front, (*printer.begin()).second));
					printer.pop_front();
					poped = false;
					break;
				}
			}

			if (poped) {
				if ((*printer.begin()).second == idx) {
					printf("%d\n",count);
					break;
				} else {
					printer.pop_front();
					count++;
				}
			}
		}
	}

	return 0;
}