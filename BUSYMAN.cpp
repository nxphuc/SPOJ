/*
LINK: http://www.spoj.com/problems/BUSYMAN/
TAG: sorting
*/

#include <cstdio>
#include <algorithm>
using namespace std;

pair <int, int> task[100000];

inline bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	int test, i, n, last, cnt;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d %d", &task[i].first, &task[i].second);
		sort(task, task + n, cmp);
		cnt = 0, last = -1;
		for(i = 0; i < n; i++) {
			if(task[i].first >= last) {
				cnt++;
				last = task[i].second;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
