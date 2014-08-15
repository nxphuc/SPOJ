/*
LINK: http://www.spoj.com/problems/BUGLIFE/
TAG: bi-coloring
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 2002;

vector <int> G[MAX];
int color[MAX];

bool bfs(int u) {
	int i, v, sz;
	queue <int> Q;
	Q.push(u);
	color[u] = 1;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i];
			if(color[v] == color[u])
				return false;
			if(!color[v]) {
				color[v] = 3 - color[u];
				Q.push(v);
			}
		}
	}
	return true;
}

int main() {
	int t, x, N, E, u, v, i;
	scanf("%d", &t);
	for(x = 1; x <= t; x++) {
		scanf("%d%d", &N, &E);
		for(i = 1; i <= N; i++) {
			G[i].clear();
			color[i] = 0;
		}
		for(i = 0; i < E; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(i = 1; i <= N; i++) {
			if(!color[i]) {
				if(bfs(i))
					continue;
				else
					break;
			}
		}
		printf("Scenario #%d:\n", x);
		if(i > N)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}
