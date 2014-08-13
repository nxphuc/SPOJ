/*
LINK: http://www.spoj.com/problems/ALICESIE/
TAG: math
*/

#include <cstdio>

int main() {
	int test, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		printf("%d\n", (n + 1) >> 1);
	}
	return 0;
}
