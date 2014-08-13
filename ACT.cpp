/*
LINK: http://www.spoj.com/problems/ACT/
TAG: ad-hoc
*/

#include <cstdio>
#include <cstring>

int main(){
	char str[50005];
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d %s", &n, str);
		printf("%c\n", str[strlen(str)-1]);
	}
	return 0;
}
