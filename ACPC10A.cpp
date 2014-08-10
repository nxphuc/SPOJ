/*
LINK: http://www.spoj.com/problems/ACPC10A/
TASK: ad-hoc
*/

#include <cstdio>

int main(){
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) == 3 && (a | b | c)) {
		if(b - a == c - b)
		  printf("AP %d\n", c + c - b);
		else
		  printf("GP %d\n", c * c / b);
	}
	return 0;
}
