#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n, k;
int a[104][104];
bool visited[104][104];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
int dfs(int y, int x) {
	visited[y][x] = 1;
	int temp = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] || a[ny][nx] == 1) continue;
		temp += dfs(ny, nx);
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				a[y][x] = 1;
			}
		}
	}

	vector<int> ret;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1 && !visited[i][j])
				ret.push_back(dfs(i, j));
		}
	}

	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int it : ret) cout << it << " ";
	return 0;
}