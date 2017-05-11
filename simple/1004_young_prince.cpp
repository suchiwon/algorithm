#include <stdio.h>
#include <math.h>
#include <vector>
#include <list>

using namespace std;


typedef struct _circle {
	int x;
	int y;
	int r;
	list<_circle> next_level;
} circle;

list<circle> circleMap;

/*
int isInCircle(circle src, circle dest) {
	if (((src.r + dest.r) * (src.r + dest.r)) >
		(((src.x - dest.x) * (src.x - dest.x)) + ((src.y - dest.y) * (src.y - dest.y)))) {
			if (src.r > dest.r) {
				return -1;
			} else {
				return 1;
			}
	} else {
		return 0;
	}
}

int checkLevel(circle &c, list<circle> &levelMap, int level) {

	int max_level = level;
	int temp;
	
	list<circle>::iterator iter = levelMap.begin();

	for (; iter != levelMap.end(); iter++) {
		if (isInCircle(c, (*iter)) == 1 && (*iter).r != 0) {
			temp = checkLevel(c, (*iter).next_level, level + 1);

			if (temp > max_level) {
				max_level = temp;
			}
			break;
		}
	}

	if (iter == levelMap.end() && c.r != 0) {
		iter = levelMap.begin();

		while (iter != levelMap.end()) {
			if (isInCircle(c, (*iter)) == -1) {
				list<circle>::iterator iter_temp = iter;
				iter_temp++;
				c.next_level.push_front((*iter));
				levelMap.erase(iter);

				iter = iter_temp;
			} else {
				iter++;
			}
		}

		levelMap.push_front(c);
	}

	return max_level;
}

int main() {
	int T, n;
	int x_start, y_start, x_end, y_end;
	int x,y,r;
	scanf("%d",&T);

	circle temp;

	temp.r = 0;
	temp.x = 0;
	temp.y = 0;

	while (T--) {

		circleMap.clear();

		//circleMap.push_back(temp);

		scanf("%d %d %d %d",&x_start, &y_start, &x_end, &y_end);

		scanf("%d",&n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d",&x,&y,&r);

			circle c;

			c.x = x;
			c.y = y;
			c.r = r;

			//c.next_level.push_back(temp);

			checkLevel(c, circleMap, 0);
		}

		int ans = 0;

		circle point;

		point.x = x_start;
		point.y = y_start;
		point.r = 0;

		ans += checkLevel(point, circleMap, 0);
		
		point.x = x_end;
		point.y = y_end;
		point.r = 0;

		ans += checkLevel(point, circleMap, 0);

		printf("%d\n",ans);
	}

	return 0;
}
*/

int isInCircle(circle c, int x, int y) {
	if ((((c.x - x) * (c.x - x)) + ((c.y - y) * (c.y - y))) < (c.r * c.r)) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int T;
	int x1,y1,x2,y2;
	int n;
	int x,y,r;
	int ans;
	list<circle>::iterator iter;
	scanf("%d",&T);

	while (T--) {

		ans = 0;

		circleMap.clear();
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		scanf("%d",&n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d",&x,&y,&r);

			circle c;
			c.x = x;
			c.y = y;
			c.r = r;

			circleMap.push_back(c);
		}

		for (iter = circleMap.begin(); iter != circleMap.end(); iter++) {
			int pos1_in = isInCircle((*iter),x1,y1);
			int pos2_in = isInCircle((*iter),x2,y2);

			if (pos1_in != pos2_in) {
				ans++;
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}