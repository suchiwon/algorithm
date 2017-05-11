#include <iostream>
#include <string>

using namespace std;

bool bPelindrom(const char* subStr, int start, int end)
{
	while(start <= end)
	{
		if(subStr[start] != subStr[end])
			return false;

		start++;
		end--;
	}

	return true;
}

int main()
{
	int i = 0, size;

	string str;

	cin >> str;

	size = str.size();

	for(i = 0; i < size; i++)
	{
		if(bPelindrom(str.c_str(),i,size - 1))
			break;
	}

	cout << size + i << endl;

	return 0;
}

