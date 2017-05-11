#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>

#define MAX_SIZE 100000

using namespace std;

deque<int> deck;

int main() {
	int T, n, idx;
	char command[MAX_SIZE + 1];
	char arrStr[3 * MAX_SIZE + 3];
	char* token;
	bool bReversed;
	bool bError;
	string str;

	scanf("%d",&T);

	while (T--) {
		scanf("%s",command);
		scanf("%d",&n);

		scanf("%s",arrStr);

		token = strtok(arrStr,"[,]");

		deck.clear();

		while (token != NULL) {
			deck.push_back(atoi(token));
			token = strtok(NULL,"[,]");
		}

		bReversed = false;
		bError = false;
		idx = 0;

		while (command[idx] != 0) {

			if (command[idx] == 'R') {
				if (bReversed) {
					bReversed = false;
				} else {
					bReversed = true;
				}
			} else if (command[idx] == 'D') {
				if (bReversed) {
					if (!deck.empty()) {
						deck.pop_back();
					} else {
						puts("error");
						bError = true;
						break;
					}
				} else {
					if (!deck.empty()) {
						deck.pop_front();
					} else {
						puts("error");
						bError = true;
						break;
					}
				}
			}

			idx++;
		}

		if (!bError) {
			printf("[");

			if (!bReversed) {
				while (!deck.empty()) {
					if (deck.size() > 1)
						printf("%d,",deck.front());
					else
						printf("%d",deck.front());
					deck.pop_front();
				}
			} else {
				while (!deck.empty()) {
					if (deck.size() > 1)
						printf("%d,",deck.back());
					else
						printf("%d",deck.back());
					deck.pop_back();
				}
			}

			puts("]");
		}
	}

	return 0;
}