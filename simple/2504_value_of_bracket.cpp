#include <stdio.h>
#include <stack>

using namespace std;

int valLevel[17];

int main() {
	char bracketStr[31];
	int idx = 0;

	scanf("%s",bracketStr);

	stack<int> valStack;

	for (int i = 0; i < 16; i++) {
		valLevel[i] = 0;
	}

	while (bracketStr[idx] != 0) {
		if (bracketStr[idx] == '(') {
			valStack.push(2);
		} else if (bracketStr[idx] == '[') {
			valStack.push(3);
		} else if (bracketStr[idx] == ')') {
			if (valStack.empty() || valStack.top() != 2) {
				puts("0");
				return 0;
			} else {

				valStack.pop();

				if (valLevel[valStack.size() + 1] == 0) {
					valLevel[valStack.size()] += 2;
				} else {
					valLevel[valStack.size()] += 2 * valLevel[valStack.size() + 1];
					valLevel[valStack.size() + 1] = 0;
				}
			}
		} else if (bracketStr[idx] == ']') {
			if (valStack.empty() || valStack.top() != 3) {
				puts("0");
				return 0;
			} else {

				valStack.pop();

				if (valLevel[valStack.size() + 1] == 0) {
					valLevel[valStack.size()] += 3;
				} else {
					valLevel[valStack.size()] += 3 * valLevel[valStack.size() + 1];
					valLevel[valStack.size() + 1] = 0;
				}
			}
		}

		idx++;
	}

	if (!valStack.empty()) {
		puts("0");
	} else {
		printf("%d\n",valLevel[0]);
	}

	return 0;
}