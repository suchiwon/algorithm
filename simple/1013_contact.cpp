#include <stdio.h>

#define MAX_SIZE 200
#define INIT_STATE 0
#define TRAP_STATE 10

/*
(100+1+ | 01)+ 에 대한 오토마타 그래프
*/
int automata[11][2];

void SetAutomata() {
	automata[0][0] = 1;
	automata[0][1] = 3;

	automata[1][0] = TRAP_STATE;
	automata[1][1] = 2;

	automata[2][0] = 1;
	automata[2][1] = 3;

	automata[3][0] = 4;
	automata[3][1] = TRAP_STATE;

	automata[4][0] = 5;
	automata[4][1] = TRAP_STATE;

	automata[5][0] = 5;
	automata[5][1] = 6;

	automata[6][0] = 8;
	automata[6][1] = 7;

	automata[7][0] = 9;
	automata[7][1] = 7;

	automata[8][0] = TRAP_STATE;
	automata[8][1] = 2;

	automata[9][0] = 5;
	automata[9][1] = 2;

	automata[TRAP_STATE][0] = TRAP_STATE;
	automata[TRAP_STATE][1] = TRAP_STATE;
}

int main() {
	int T, idx, state;

	scanf("%d",&T);

	char str[MAX_SIZE + 1];

	SetAutomata();

	while (T--) {
		scanf("%s",str);

		state = INIT_STATE;
		idx = 0;

		while (str[idx] != 0) {
			if (str[idx] == '0') {
				state = automata[state][0];
			} else if (str[idx] == '1') {
				state = automata[state][1];
			}

			idx++;
		}

		if (state == 2 || state == 6 || state == 7) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}