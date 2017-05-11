#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

vector<string> wearArr;
vector<int> wearNum;

int main() {
	int T, n, ans = 1, idx;

	scanf("%d",&T);

	while (T--) {
		scanf("%d",&n);

		wearArr.clear();
		wearNum.clear();
		ans = 1;

		for (int i = 0; i < n; i++) {
			char temp[22], temp2[100];
			scanf("%s %s",temp, temp2);

			for (idx = 0; idx < wearArr.size(); idx++) {
				if (strcmp(temp2, wearArr[idx].c_str()) == 0) {
					wearNum[idx]++;
					break;
				} 
			}

			if (idx >= wearArr.size()) {
				string str;
				str.append(temp2);
				wearArr.push_back(str);
				wearNum.push_back(1);
			}
		}

		for (int i = 0; i < wearNum.size(); i++) {
			ans *= wearNum[i] + 1;
		}

		printf("%d\n",ans - 1);
	}
}