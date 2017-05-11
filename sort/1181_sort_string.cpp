#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool sort_string(string str1, string str2) {
	if (str1.size() > str2.size()) {
		return false;
	} else if (str1.size() < str2.size()) {
		return true;
	} else if (strcmp(str1.c_str(),str2.c_str()) < 0) {
		return true;
	} else {
		return false;
	}
}

int main() {

	vector<string> arr;
	set<string> tempSet;

	int N;

	scanf("%d",&N);

	string temp;
	char tempStr[51];

	for (int i = 0; i < N; i++) {

		scanf("%s",tempStr);

		temp = tempStr;

		if(tempSet.find(temp) == tempSet.end()) {
			arr.push_back(temp);
			tempSet.insert(temp);
		}

	}

	sort(arr.begin(),arr.end(),sort_string);

	for (int i = 0; i < arr.size(); i++) {
		printf("%s\n",arr[i].c_str());
	}

	return 0;
}