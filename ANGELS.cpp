/*
LINK: http://www.spoj.com/problems/ANGELS/
TASK: bipartite matching
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))

const int MAX = 10000;

struct data{
	int l, r, i;
	data (int ll, int rr, int ii) : l(ll), r(rr), i(ii) {}
};

vector < int > edges[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX], R, C, nr, nc;

bool dfs(int u) {
	if (visited[u])
		return false;
	visited[u] = true;
	int len = edges[u].size(), i, v;
	for(i = 0; i < len; i++) {
		v = edges[u][i];
		if(Right[v] == -1) {
			Right[v] = u;
			Left[u] = v;
			return true;
		}
	}
	for(i = 0; i < len; i++) {
		v = edges[u][i];
		if (dfs(Right[v])) {
			Right[v] = u;
			Left[u] = v;
			return true;
		}
	}
	return false;
}

int match() {
	SET(Left);
	SET(Right);
	int i, ret = 0;
	bool done;
	do {
		done = true;
		CLR(visited);
		for(i = 0; i < nr; i++) {
			if(Left[i] == -1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i = 0; i < nr; i++) ret += (Left[i] != -1);
	return ret;
}

char grid[300][300], temp[10];

int main() {
	int t, i, j, s;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				scanf("%s", temp);
				grid[i][j] = temp[0];
			}
		}
		vector< data > row, col;
		
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] != 'A') {
					s = j;
					while(j < C && grid[i][j] != 'A') j++;
					row.push_back(data(s, j - 1, i));
					j--;
				}
			}
		}
		for(i = 0; i < C; i++) {
			for(j = 0; j < R; j++) {
				if(grid[j][i] != 'A') {
					s = j;
					while(j < R && grid[j][i] != 'A') j++;
					col.push_back(data(s, j - 1, i));
					j--;
				}
			}
		}
		nr = row.size(), nc = col.size();
		if(!nr || !nc)
			printf("%d\n", max(nr, nc));
		else {
			for(i = 0; i < nr; i++) {
				edges[i].clear();
				for(j = 0; j < nc; j++) {
					if (
					    col[j].l <= row[i].i && row[i].i <= col[j].r &&
					    row[i].l <= col[j].i && col[j].i <= row[i].r &&
					    grid[row[i].i][col[j].i] == 'H'
					   ) {
						edges[i].push_back(j);
					}
				}
			}
			printf("%d\n", match());
		}
	}
	return 0;
}
