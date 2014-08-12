/*
LINK: http://www.spoj.com/problems/ARMY/
TASK: ad-hoc
*/

#include <cstdio>
int main(){
	int t, ng, nm, maxg, maxm, g, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &ng, &nm);
		maxg = -1; maxm = -1;
		while(ng--){
			scanf("%d", &g);
			if (g > maxg)
				maxg = g;
		}
		while(nm--){
			scanf("%d", &m);
			if (m > maxm)
				maxm = m;
		}
		if (maxg >= maxm)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}
	return 0;
}
