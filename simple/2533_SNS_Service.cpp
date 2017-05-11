#include <stdio.h>
#include <string.h>

#define MIN(a,b) (a>b?b:a)

#define MAX_SIZE 1000000
#define NOT_INIT -1
#define ODD 0
#define EVEN 1

int level[MAX_SIZE + 1];

int main()
{
	int N, odd = 1, even = 0;
	int v1, v2;

	memset(level,NOT_INIT,sizeof(level));
	level[1] = ODD;

	scanf("%d",&N);

	for(int i = 0; i < N - 1; i++)
	{
		scanf("%d %d",&v1,&v2);

		if(level[v1] == ODD)
		{
			level[v2] = EVEN;
			even++;
		}
		else
		{
			level[v2] = ODD;
			odd++;
		}
	}

	printf("%d\n",MIN(even,odd));

	return 0;
}