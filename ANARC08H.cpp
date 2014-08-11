/*
LINK: http://www.spoj.com/problems/ANARC08H/
TASK: simulation
*/

#include <cstdio>

int solve(int n, int d){
	int i, ans = 0;
	for(i = 2; i <= n; i++)
		ans = (ans + d) % i;
	return ans;
}

int main(){
	int n, d;
	while( scanf("%d%d", &n, &d) == 2 && (n + d))
		printf("%d %d %d\n", n, d, solve(n, d) + 1);
	return 0;
}
