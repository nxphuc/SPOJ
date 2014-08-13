/*
LINK: http://www.spoj.com/problems/BAISED/
TAG: sorting
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int a[100001];
char name[100001];

int main(){
	int n, i, t;
	ll ans;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%s %d", name, &a[i]);
		sort(a, a + n);
		ans = 0;
		for(i = 0; i < n; i++)
			ans += abs(a[i] - (i + 1));
		printf("%lld\n", ans);
	}
	return 0;
}
