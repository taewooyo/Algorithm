#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[105][105], b[105][105];
bool visited[105][105];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
void dfs(int y, int x, int h) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] <= h || visited[ny][nx]) continue;
		dfs(ny, nx, h);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ret = 1;
	for (int h = 1; h <= 100; h++) {

		fill(&visited[0][0], &visited[0][0] + 150 * 150, 0);
		int safe = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && a[i][j] > h) {
					dfs(i, j, h);
					safe++;
				}
			}
		}

		ret = max(ret, safe);
	}
	cout << ret << '\n';
	return 0;
}