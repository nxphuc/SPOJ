/*
LINK: http://www.spoj.com/problems/ANARC09A/
TAG: ad-hoc
*/

#include <cstdio>

int main() {
	int i, x, y, cs = 1;
	char str[4096];
	while(scanf("%s", str) == 1 && str[0] != '-') {
		for(x = 0, y = 0, i = 0; str[i]; i++) {
			x += (str[i] == '{' ? 1 : -1);
			if (x < 0){
			  x += 2; y++;
			}
		}
		printf("%d. %d\n", cs++, (x >> 1) + y);
	}
	return 0;
}
