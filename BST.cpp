/*
LINK: http://www.spoj.com/problems/BST/
TAG: binary tree construction
*/

#include <cstdio>
#include <set>
using namespace std;

#define MAX 300010

long long flag[MAX][3]; // 0 depth, 1 left, 2 right

int main(){
	set <int> L;
	set <int> :: iterator it;
	int n, q;
	long long c = 0;
	scanf("%d%d", &q, &n);
	L.insert(L.begin(), n);
	printf("%d\n", c);
	while(--q){
		scanf("%d", &n);
		it = L.lower_bound(n);
		if(it == L.end()){
			L.insert(it, n);
			it--; it--;
			flag[*it][2] = 1;
			flag[n][0] = flag[*it][0] + 1;
		}
		else
			if(it == L.begin()){
				L.insert(it, n);
				flag[*it][1] = 1;
				flag[n][0] = flag[*it][0] + 1;
			}
			else{
				L.insert(it, n);
				it--;it--;
				if(!flag[*it][2]){
					flag[*it][2] = 1;
					flag[n][0] = flag[*it][0] + 1;
				}
				else{
					it++;it++;
					flag[*it][1] = 1;
					flag[n][0] = flag[*it][0] + 1;
				}
			}
		c += flag[n][0];
		printf("%lld\n", c);
	}
	return 0;
}
