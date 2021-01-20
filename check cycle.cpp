#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;

vector < int > G[N];
int from[N], to[N];
bool ans;
int mark[N], cmpCnt = 1;

void dfs(int v) {
	mark[v] = cmpCnt;
	for (int i = 0; i < G[v].size(); i++) {
		if (mark[G[v][i]] != cmpCnt) {
			dfs(G[v][i]);
		} else {
			ans = true;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int i = 0;
	while (cin >> from[i] >> to[i]) {
		G[from[i]].push_back(to[i]);
		i++;
	}
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			dfs(i);
			cmpCnt++;
		}
	}
	cout << ans;
	return 0;
}
