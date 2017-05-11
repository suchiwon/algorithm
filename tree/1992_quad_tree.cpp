#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_SIZE 64

char arr[MAX_SIZE + 1][MAX_SIZE + 1];

vector<char> cut(int lp_x, int lp_y, int size) {
	if (size == 1) {
		vector<char> v;

		if (arr[lp_x][lp_y] == '0')
			v.push_back('0');
		else
			v.push_back('1');

		return v;
	} else {
		vector< vector<char> > val;

		val.resize(4);

		size = size/2;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				val[i * 2 + j] = cut(lp_x + (size * i), lp_y + (size * j),size);
			}
		}

		for (int i = 1; i < 4; i++) {
			if (val[0].size() != 1 || val[i].size() != 1 || val[0][0] != val[i][0]) {

				vector<char> v;
				v.push_back('(');

				for (int j = 0; j < 4; j++) {
					v.insert(v.end(),val[j].begin(),val[j].end());
				}

				v.push_back(')');

				return v;
			}
		}

		return val[0];
	}
}

int main() {
	int N;

	scanf("%d",&N);

	for (int i = 0; i < N; i++) {
		scanf("%s",arr[i]);
	}

	vector<char> v = cut(0,0,N);

	for (int i = 0; i < v.size(); i++) {
		printf("%c",v[i]);
	}

	return 0;
}