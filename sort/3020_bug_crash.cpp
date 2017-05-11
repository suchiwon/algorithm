#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX_SIZE 500000

using namespace std;

int upper[MAX_SIZE + 1];
int down[MAX_SIZE + 1];

bool sortFunc(int a, int b)
{
	if(a < b)
		return true;
	else
		return false;
}

int main()
{
	int N, H;
	int a, b;

	vector<int> arr;

	int count = 1, min = 999999;

	scanf("%d %d",&N, &H);

	memset(upper,0,sizeof(upper));
	memset(down,0,sizeof(down));

	for(int i = 0; i < N/2; i++)
	{
		scanf("%d %d",&a, &b);

		upper[a]++;
		down[b]++;
	}

	for(int i = H; i > 1; i--)
	{
		upper[i - 1] += upper[i];
		down[i - 1] += down[i];
	}

	for(int i = 1; i <= H; i++)
	{
		arr.push_back(upper[i] + down[H + 1 - i]);
	}

	sort(arr.begin(),arr.end(),sortFunc);

	for(int i = 1; i < arr.size(); i++)
	{
		if(arr[0] == arr[i])
			count++;
		else
			break;
	}

	printf("%d %d\n",arr[0],count);

	return 0;
}
