#include <stdio.h>
#include <set>
#include <list>

using namespace std;

list< set<int> > unionList;

int main()
{
	int N, M;

	int a, b;

	set<int> s;
	list< set<int> >::iterator iter;
	list< set<int> >::iterator iter2;

	scanf("%d %d",&N, &M);

	unionList.push_back(s);
	(*unionList.begin()).insert(1);

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d",&a,&b);

		for(iter = unionList.begin(); iter != unionList.end(); iter++)
		{
			if((*iter).find(a) != (*iter).end() || (*iter).find(b) != (*iter).end())
			{
				(*iter).insert(a);
				(*iter).insert(b);

				iter2 = iter;
				iter2++;

				for(;iter2 != unionList.end(); iter2++)
				{
					if((*iter2).find(a) != (*iter2).end() || (*iter2).find(b) != (*iter2).end())
					{
						for(set<int>::iterator iterC = (*iter2).begin(); iterC != (*iter2).end(); iterC++)
							(*iter).insert((*iterC));

						unionList.erase(iter2);
						break;
					}
				}

				break;
			}
		}

		if(iter == unionList.end())
		{
			set<int> temp;
			temp.insert(a);
			temp.insert(b);
			unionList.push_back(temp);
		}
	}

	printf("%d\n",(*unionList.begin()).size() - 1);

	return 0;
}