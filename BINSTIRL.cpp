/*
LINK: http://www.spoj.com/problems/BINSTIRL/
TAG: math
*/

#include <cstdio>

int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		printf("%d\n", !((n - m) & ((m - 1) >> 1)));
	}
	return 0;
}
